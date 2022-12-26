#pragma once
#ifndef CONFIG_H
#define CONFIG_H
/* code */
#include <stdint.h>
#include <stdio.h>
#define SUCCESS 0
#define FAILURE 1


#ifdef UNIT_TEST
#define FUNC_TEST __attribute__((weak))
#else
#define FUNC_TEST
#endif




typedef enum
{
    USART_NONE = 0,
    USART1,
    USART2,
    USART3,
    USART4,
    USART5,
    USART6
} UART_TypeDef;

typedef enum
{
    BAUDRATE_DEFAULT = 9600,
    BAUDRATE_9600 = 9600,
    BAUDRATE_14400 = 14400,
    BAUDRATE_19200 = 19200,
    BAUDRATE_38400 = 38400,
    BAUDRATE_57600 = 57600,
    BAUDRATE_115200 = 115200,
    BAUDRATE_128000 = 128000,
    BAUDRATE_256000 = 256000
} UART_BaudRateTypeDef;

typedef struct
{
    UART_BaudRateTypeDef BaudRate;


} UART_Init_HandleTypeDef;

typedef struct
{
    UART_TypeDef Instance;
    UART_Init_HandleTypeDef Init;

} UART_HandleTypeDef;

#endif //CONFIG_H
