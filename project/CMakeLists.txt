cmake_minimum_required(VERSION 3.0.0)

project (esp8266)
find_package(Threads)

if (UNIT_TEST STREQUAL "ON")
    enable_testing ()
    add_subdirectory (app)

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googletest" AND IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/googletest")
        message(STATUS "Gtest available at : ${CMAKE_CURRENT_SOURCE_DIR}/googletest")
        add_subdirectory(googletest)
    else()
        message(STATUS "EXTERNAL: Clone Google Test Framework from Git repository...")
        include(FetchContent)
        FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
        )

        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()
    add_subdirectory (unit_test)

else()
    add_subdirectory (app)
endif()


