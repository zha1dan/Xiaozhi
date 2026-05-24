#ifndef MYVOICE_H
#define MYVOICE_H

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

void SU03T_init(void);
void SU03T_receive(void);

#endif