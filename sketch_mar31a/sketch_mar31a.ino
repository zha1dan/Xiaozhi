#include "Config.h"
#include "MyOLED.h"
#include "MyTask.h"
#include "MyQueue.h"
#include "MyVoice.h"
#include "Myservo.h"
TaskHandle_t tVoice;//语音任务句柄
TaskHandle_t tOLED;
TaskHandle_t tDuoji;
// 语音任务
void Task_Voice(void *p) 
{
  while(1) 
  {
    SU03T_receive();
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

// OLED 任务
void Task_OLED(void *p) 
{
  MyOLED_Init();
  uint8_t cmd;

  while(1)
   {
    MyTask_ShowFace(); 
     vTaskDelay(pdMS_TO_TICKS(10));
     }
}
void Task_Duoji(void *p)
{
    MyTask_ServoControl(NULL);
}
void setup() {
  Serial.begin(115200);
  Queues_Init();
  SU03T_init();
  MyServo_Init();
  xTaskCreate(Task_Voice, "Voice", 2048, NULL, PRIO_HIGHEST, &tVoice);
  xTaskCreate(Task_OLED,  "OLED",  2048, NULL, PRIO_NORMAL,  &tOLED);
  xTaskCreate(Task_Duoji,  "Duoji",4096, NULL, PRIO_NORMAL,  &tDuoji);
}

void loop() {}