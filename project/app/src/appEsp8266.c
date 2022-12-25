#include "../inc/appEsp8266.h"
#include "../inc/config.h"


FUNC_TEST int gpio_init(void)
{
    return -1;
}
//https://www.codeproject.com/articles/1040972/using-googletest-and-googlemock-frameworks-for-emb
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

int appEsp8266Init(void)
{
    printf("Esp8266 Initialization\n");
    
    return SUCCESS;
}