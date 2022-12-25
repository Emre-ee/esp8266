#ifndef APPESP8266_H
#define APPESP8266_H
#include <stdio.h>
#include <stdint.h>
#include "config.h"

int appEsp8266Init(void);
int uart_init(UART_HandleTypeDef *Uart);

#endif // APPESP8266_H
