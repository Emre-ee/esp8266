cmake_minimum_required(VERSION 3.0.0)

project (unitTest)


set(Sources
    main.cpp
)


add_executable(unitTest ${Sources})


target_link_libraries(unitTest PUBLIC
    gtest_main
    esp8266Lib
)   



add_test(
    NAME unitTest
    COMMAND unitTest
)