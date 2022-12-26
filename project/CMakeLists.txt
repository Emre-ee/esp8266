cmake_minimum_required(VERSION 3.0.0)

project (esp8266)


message(STATUS "--- CMAKE SYSTEM: ${CMAKE_SYSTEM}")
message(STATUS "--- CMAKE SYSTEM LIB PATH: ${CMAKE_SYSTEM_LIBRARY_PATH}")
message(STATUS "--- CMAKE LIB PATH: ${CMAKE_LIBRARY_PATH}")
message(STATUS "--- CMAKE VERSION: ${CMAKE_VERSION}")
message(STATUS "--- PLATFORM: ${PLATFORM}")
message(STATUS "--- Do not warn about unused CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "--- Do not warn about unused BUILD_DIR: ${BUILD_DIR}")
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


