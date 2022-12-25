cmake_minimum_required(VERSION 3.0.0)

project (unitTest)


set(Sources
    mock/esp8266_mock.cpp
    TEST_ESP8266.cpp
)

set(Headers
    mock/esp8266_mock.hpp
    mock/mock_uart_class.h
)




add_executable(unitTest ${Sources} ${Headers})


target_link_libraries(unitTest PUBLIC
    gtest_main
    gmock_main
    esp8266Lib
)   

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/mock")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/mock")
 # I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
 include_directories("${source_dir}/googletest/include"
                     "${source_dir}/googlemock/include")
 

add_test(
    NAME unitTest
    COMMAND unitTest
)