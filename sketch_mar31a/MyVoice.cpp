#include"MyVoice.h"
#include <Arduino.h> 
#include "MyQueue.h"
/*
语音任务逻辑
识别语音，串口输出内容，将内容放消息队列里，发送给动作组识别，进行动
B7TX,B6RX
*/
void SU03T_init()
 {
  // 波特率 9600，RX=16，TX=17
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}

// 一帧 5 字节
#define FRAME_SIZE 5
uint8_t buf[FRAME_SIZE];
static uint8_t buf_idx = 0 ;
static uint8_t state = 0;
void SU03T_receive()
 {
  // 只要串口有数据就读
  while (Serial2.available() > 0)
  {
    uint8_t byte = Serial2.read();
    //Serial.print(byte); 
    //Serial.println(); 
    if (state == 0)
    {
      // 等待帧头 0xAA
      if (byte == 0xAA) {
        buf[0] = byte;
        state = 1;
      }
    }
    else if (state == 1) 
    {
      // 等待帧头 0x55
      if (byte == 0x55) {
        buf[1] = byte;
        buf_idx = 2;      // 下一个从 buf[2] 开始存
        state = 2;
      } 
      else
       {
        state = 0;      // 不对，重新开始
      }
    }
    else if (state == 2) {
      // 继续存后面的数据
      buf[buf_idx] = byte;
      buf_idx++;

      // 一帧收完了
      if (buf_idx >= FRAME_SIZE) {
        // 先校验帧尾是不是 55 AA
        if (buf[3] == 0x55 && buf[4] == 0xAA) {
          // 正确帧！拿出指令
          uint8_t cmd = buf[2];

          Serial.print("数据位：");
          Serial.println(cmd, HEX);
          xQueueSend(faceQueue, &cmd, pdMS_TO_TICKS(100));
          xQueueSend(ActionQueue, &cmd, pdMS_TO_TICKS(100));
        }

        // 重置，准备下一帧
        state = 0;
        buf_idx = 0;
      }
    }
  }
}