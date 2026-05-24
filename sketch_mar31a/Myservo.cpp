#include "Myservo.h"
#include "MyQueue.h"
#include <math.h>

static Servo servo[4];               // 舵机对象数组
static Action_t mode = ACT_STOP;     // 当前运动模式
static float phase = 0.0f;          // 步态相位（弧度，0~2π）

// 四腿对应的 GPIO 引脚
static const uint8_t pins[4] = {SERVO_FL, SERVO_FR, SERVO_BL, SERVO_BR};

// 对角相位偏移：FL+BR 同相(0)，FR+BL 反相(π)
// 保证任意时刻有一组对角线在"推"、另一组在"回"
static const float offsets[4] = {0.0f, M_PI, M_PI, 0.0f};

// 标记是否为左侧腿（用于差速转弯）
static const int is_left[4] = {1, 0, 1, 0};

void MyServo_Init(void)
{
    for (int i = 0; i < 4; i++) {
        servo[i].attach(pins[i]);
        servo[i].write(GAIT_CENTER);    // 全部回中，立正
    }
}

/*
 * 核心：根据当前 mode 和 phase 计算并输出四腿角度
 *
 * 对角 trot 步态：
 *   FL + BR = center + dir * amp * sin(phase + 0)
 *   FR + BL = center + dir * amp * sin(phase + π)  ← 完全反相
 *
 * 转弯：差速原理
 *   左转 → 左侧腿摆幅降为 20%，右侧维持 100% → 机器人向左偏
 *   右转 → 同理反向
 */
static void apply_gait(void)
{
    if (mode == ACT_STOP) {
        // 停止：四腿回中
        for (int i = 0; i < 4; i++)
            servo[i].write(GAIT_CENTER);
        return;
    }

    // 后退时摆动方向取反（相当于 sin(θ+π)）
    float dir = (mode == ACT_BACKWARD) ? -1.0f : 1.0f;

    // 转弯时单侧降速
    float left_factor = 1.0f, right_factor = 1.0f;
    if (mode == ACT_LEFT)
        left_factor = 0.2f;
    else if (mode == ACT_RIGHT)
        right_factor = 0.2f;

    // 逐腿计算并输出角度
    for (int i = 0; i < 4; i++) {
        float factor = is_left[i] ? left_factor : right_factor;
        float angle = GAIT_CENTER + dir * GAIT_AMPLITUDE * factor * sinf(phase + offsets[i]);
        servo[i].write((int)(angle + 0.5f));    // +0.5 四舍五入
    }
}

/*
 * 舵机控制任务（Task_Duoji 直接调用，永不返回）
 *
 * 控制循环：每 20ms 读一次队列 → 应用步态 → 推进相位
 * 队列读取出队即清空，0 超时 = 不阻塞，没指令就继续当前动作用 vTaskDelayUntil 保证精确 20ms 周期
 */
void MyTask_ServoControl(void *pvParameters)
{
    uint8_t cmd;
    TickType_t last_wake = xTaskGetTickCount();

    while (1) {
        // 非阻塞读队列：有指令就切模式，没有就继续
        if (xQueueReceive(ActionQueue, &cmd, 0) == pdTRUE) {
            if (cmd <= ACT_RIGHT)
                mode = (Action_t)cmd;
            else
                mode = ACT_STOP;    // 未知指令 → 安全停机
        }

        apply_gait();   // 根据当前模式更新舵机角度

        // 推进相位（停止时不推进，避免重新启动时突变）
        if (mode != ACT_STOP)
            phase += GAIT_PHASE_STEP;
        if (phase > 6.28318f)      // 2π 溢出回卷
            phase -= 6.28318f;

        vTaskDelayUntil(&last_wake, pdMS_TO_TICKS(GAIT_TICK_MS));
    }
}
