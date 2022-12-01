cmake_minimum_required(VERSION 3.0.0)

project (esp8266)


if (UNIT_TEST STREQUAL "ON")
    enable_testing ()
    add_subdirectory (app)
    add_subdirectory(googletest)
    add_subdirectory (unit_test)

else()
    add_subdirectory (app)
endif()


