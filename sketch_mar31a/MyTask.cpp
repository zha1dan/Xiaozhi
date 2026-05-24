#include "MyTask.h"
#include "MyOLED.h"
#include "MyQueue.h"
uint8_t cmd;
uint8_t screen_timer = 0;   // 防烧屏计时器
uint8_t now_face = 0;       // 记录当前显示哪个表情

void MyTask_ShowFace()
{
  // 1. 读队列（100ms 超时，不阻塞）
  if(xQueueReceive(faceQueue, &cmd, pdMS_TO_TICKS(100)) == pdTRUE)
  {
    // 收到指令 → 立刻切换表情
    if(cmd == 1)
    {
      MyOLED_ShowFace_Squint();
      now_face = 1;       // 记住当前表情
      screen_timer = 0;   // 计时器清零
    }
    else if(cmd == 2)
    {
      MyOLED_ShowFace_EyeBox();
      now_face = 2;       // 记住当前表情 
      screen_timer = 0;   // 计时器清零
    }
    else if(cmd == 3)
    {
      MyOLED_ShowFace_Wink();
      now_face = 3;       // 记住当前表情
      screen_timer = 0;   // 计时器清零
    }
    else if(cmd == 4)
    {
      MyOLED_ShowFace_SmileEye();
      now_face = 4;       // 记住当前表情
      screen_timer = 0;   // 计时器清零
    }
  }
}