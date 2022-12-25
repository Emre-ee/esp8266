cmake_minimum_required(VERSION 3.0.0)

project (esp8266)

set(Sources 
            "src/appEsp8266.c"
)

set(Headers 
            "inc/appEsp8266.h"
            "inc/config.h"
)

include_directories(inc)

if (UNIT_TEST STREQUAL "ON")

    message("esp8266 CMakeLists---> Unit Test On")
    add_library (esp8266Lib ${Sources} ${Headers})

    target_include_directories(esp8266Lib PUBLIC
    AppLib_include
    )

    target_compile_definitions(esp8266Lib PUBLIC UNIT_TEST=1)

else()
    message("app CMakeLists---> Unit Test Off")
    add_executable(esp8266 main.c ${Sources} ${Headers})
endif()



