#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

extern QueueHandle_t faceQueue;
extern QueueHandle_t ActionQueue;
void Queues_Init(void);

#endif

/*
QueueHandle_t faceQueue;队列句柄创建
faceQueue = xQueueCreate(队列长度, 每个元素大小);
xQueueSend(队列句柄, 数据地址, 等待时间); 发
xQueueReceive(队列句柄, 接收地址, 等待时间);读，读到 == pdTRUE，没读到 == pdFALSE
xQueueReceive(faceQueue, &cmd, pdMS_TO_TICKS(10));（超时等待）//超时等待任务会休眠，不占用cpu

*/