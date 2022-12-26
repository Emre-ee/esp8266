#include"appUart.h"
#include "appGpio.h"


int uart_init(UART_HandleTypeDef* Uart)
{
    printf("Uart Init\n");

    int a=10,b=20;
    int retVal = gpio_init();



    if(retVal == -1)
    {
        return -10;
    }
    else
    {
        return 20;
    }

}