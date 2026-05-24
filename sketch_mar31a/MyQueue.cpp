#include "MyQueue.h"

QueueHandle_t faceQueue;
QueueHandle_t ActionQueue;
void Queues_Init(void)
{
  faceQueue = xQueueCreate(5, sizeof(uint8_t));
  ActionQueue = xQueueCreate(5, sizeof(uint8_t));
}