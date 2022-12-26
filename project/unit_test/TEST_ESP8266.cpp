#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<iostream>
#include "mock_uart_class.h"
#include "esp8266_mock.hpp"

#include "appGpio.c"
#include "appUart.c"

// This function prototype defination used for function override. 
FUNC_TEST int gpio_init(void);

using namespace testing;


class Esp8266: public ::testing::Test {

public:
    std::shared_ptr<MockESP> mock_obj{std::make_shared<MockESP>()};
   void SetUp( ) {
       // code here will execute just before the test ensues
         mock_obj_g=mock_obj;
        
   }

   void TearDown( ) {
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
       mock_obj.reset();
       mock_obj_g.reset();
   }
   
};

TEST_F(Esp8266,UartInit)
{   
    
    UART_HandleTypeDef Uart;
    Uart.Instance = USART1;
    Uart.Init.BaudRate = BAUDRATE_9600;

    //SCENARIO-1
    EXPECT_CALL(*mock_obj, gpio_init()).Times(1).WillOnce(Return(0));
    EXPECT_EQ(20, uart_init(&Uart));

    //SCENARIO-2
    EXPECT_CALL(*mock_obj, gpio_init()).Times(1).WillOnce(Return(-1));
    EXPECT_EQ(-10, uart_init(&Uart));
}

