/**
 * ============================================================================
 * @file mock_uart_class.h
 * @author Enes OZTURK
 * @author Mehmet Emre OZTURK
 * @brief This project library implementation get from by Enes OZTURK.
 * @date 2022-12-25
 *
 * @copyright:  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
 */
#ifndef __MOCK_UART_CLASS_H__
#define __MOCK_UART_CLASS_H__

#include <gmock/gmock.h>
#include "../../app/inc/config.h"
#include <memory>

class IMockESP
{

public:
    virtual ~IMockESP() {}
    virtual int uart_init(UART_HandleTypeDef* Uart)=0;
    virtual int uart_transmit(UART_HandleTypeDef* Uart, uint8_t *outBuff, uint8_t len, int timeout)=0;
    virtual int uart_receive(UART_HandleTypeDef* Uart, uint8_t *readBuff, uint8_t len, int timeout)=0;
    virtual int gpio_init(void) = 0;
};

class MockESP : public IMockESP
{

public:
    MOCK_METHOD(int, uart_init, (UART_HandleTypeDef* Uart), (override));
    MOCK_METHOD(int, uart_transmit, (UART_HandleTypeDef* Uart, uint8_t *outBuff, uint8_t len, int timeout), (override));
    MOCK_METHOD(int, uart_receive, (UART_HandleTypeDef* Uart, uint8_t *readBuff, uint8_t len, int timeout), (override));
    MOCK_METHOD(int, gpio_init, (), (override));
};
extern std::shared_ptr<MockESP> mock_obj_g;

#endif // __MOCK_UART_CLASS_H__
