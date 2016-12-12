cmake_minimum_required(VERSION 2.8)
project(handler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -std=c++1y -fexceptions -fpermissive -fpic")
include_directories(inc)

set(SOURCE_FILES src/handler/Handler.cpp src/handler/HandlerThread.cpp src/handler/MessageLoop.cpp src/handler/MessageQueue.cpp)
add_library(chandler STATIC ${SOURCE_FILES})

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} -pthread chandler)