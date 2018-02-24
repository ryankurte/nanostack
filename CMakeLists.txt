#SI446x interface project cmake file.
cmake_minimum_required(VERSION 2.8.4)

project(nanostack CXX C)

# Default to debug build
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_C_FLAGS_DEBUG "-std=gnu11 -O0 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-std=gnu++11 -O0 -g")

set(CMAKE_C_FLAGS_RELEASE "-std=gnu11 -Os -flto")
set(CMAKE_CXX_FLAGS_RELEASE "-std=gnu++11 -Os -flto")

# Include nanostack
include_directories(${CMAKE_CURRENT_LIST_DIR})
include(nanostack.cmake)

# Fetch commit hash
execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE GIT_HASH)



