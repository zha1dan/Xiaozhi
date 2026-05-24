#ifndef MYSERVO_H
#define MYSERVO_H

#include <stdint.h>
#include <ESP32Servo.h>
#include <freertos/FreeRTOS.h>

// 舵机引脚
#define SERVO_FL  2   // 左前
#define SERVO_FR  3   // 右前
#define SERVO_BL  4   // 左后
#define SERVO_BR  5   // 右后

// 动作指令（与语音模块 CMD 一一对应）
typedef enum {
    ACT_STOP     = 0x00,  // 停止，四腿回中
    ACT_FORWARD  = 0x01,  // 前进（对角 trot 步态）
    ACT_BACKWARD = 0x02,  // 后退（对角 trot 步态，相位反转）
    ACT_LEFT     = 0x03,  // 左转（左侧降速 80%）
    ACT_RIGHT    = 0x04   // 右转（右侧降速 80%）
} Action_t;

/* 步态参数（可根据实际效果微调） */
#define GAIT_CENTER     90      // 舵机中立位（腿垂直地面）
#define GAIT_AMPLITUDE  30      // 摆动幅度（±30°），越大步幅越大
#define GAIT_PHASE_STEP 0.15f   // 每 tick 相位增量，越大走得越快
#define GAIT_TICK_MS    20      // 控制周期 ms（50Hz 刷新率）

void MyServo_Init(void);
void MyTask_ServoControl(void *pvParameters);

#endif
