cmake_minimum_required(VERSION 3.22)
project(threads)

set(CMKAE_CXX_COMPILER "gcc")

add_executable(${PROJECT_NAME} task3.c)

target_link_libraries(${PROJECT_NAME})