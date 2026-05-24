/*
-------------任务------------
TaskHandle_t tOLED;//任务句柄创建
xTaskCreate(任务函数指针,任务名字(调试用),堆栈大小,传入参数(一般NULL),优先级,任务句柄（输出型）);
vTaskDelay(毫秒数);//任务延时 
vTaskSuspend(任务句柄);//挂起
vTaskResume(任务句柄);//恢复
vTaskDelete(任务句柄);//删除
xTaskGetTickCount();//获取系统运行时间

-------------队列------------
QueueHandle_t faceQueue;队列句柄创建
faceQueue = xQueueCreate(队列长度, 每个元素大小);
xQueueSend(队列句柄, 数据地址, 等待时间); 发.(pdMS_TO_TICKS(100)例如)
xQueueReceive(队列句柄, 接收地址, 等待时间);读，读到 == pdTRUE，没读到 == pdFALSE
xQueueReceive(faceQueue, &cmd, portMAX_DELAY));（超时等待）//超时等待任务会休眠，不占用cpu
xQueueSendFromISR(q, &data, NULL);//中断使用

-------------信号量-----------
信号量有二值信号量，计数信号量，互斥信号量，递归信号量
二值信号量；
SemaphoreHandle_t binary_sem;//句柄地址创建
binary_sem = xSemaphoreCreateBinary();
xSemaphoreTake(binary_sem,portMAX_DELAY);      // 等待取信号
xSemaphoreGive(binary_sem);            // 发送信号
xSemaphoreGiveFromISR(binary_sem, NULL);            // 中断里发送，NULL是不管返回值意思

计数信号量:
SemaphoreHandle_t count_sem;//句柄创建
count_sem = xSemaphoreCreateCounting(5, 0);//容量，初始值
xSemaphoreTake(count_sem, portMAX_DELAY);      // 拿一个（-1）
xSemaphoreGive(count_sem);            // 还一个（+1）

互斥信号量
SemaphoreHandle_t mutex;
mutex = xSemaphoreCreateMutex();
xSemaphoreTake(mutex, portMAX_DELAY);          // 拿锁
xSemaphoreGive(mutex);                // 解锁
*/