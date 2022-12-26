/**
 * ============================================================================
 * @file esp8266_mock.cpp
 * @author Enes OZTURK
 * @author Mehmet Emre OZTURK
 * @brief This project library implementation get from by Enes OZTURK.
 * @brief This source file provides call mocking functions.
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

#include "esp8266_mock.hpp"
#include "mock_uart_class.h"
#include <cstdarg>


std::shared_ptr<MockESP> mock_obj_g;


int gpio_init(void)
{
    std::cout<<"mock gpio_init\n";



    return mock_obj_g->gpio_init();
}

