cmake_minimum_required(VERSION 3.16)
project(data_structures_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage -fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)
find_library(GMOCK_LIB NAMES gmock REQUIRED)

set(SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../Buzz Yateer/DS")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../test_reports/data_structures")
add_executable(data_structures-a42ccdd0cdaa4160a9d04436b1966ee8_tests
    data_structures_tests.cpp
    "${SOURCE_ROOT}/LinkedList.h"
    "${SOURCE_ROOT}/ListADT.h"
    "${SOURCE_ROOT}/Node.h"
    "${SOURCE_ROOT}/Pair.h"
    "${SOURCE_ROOT}/PriortyNode.h"
    "${SOURCE_ROOT}/Queue.h"
    "${SOURCE_ROOT}/QueueADT.h"
    "${SOURCE_ROOT}/priority_queue.h"
    "${SOURCE_ROOT}/priortyQueueADT.h")
target_include_directories(data_structures-a42ccdd0cdaa4160a9d04436b1966ee8_tests PRIVATE "${SOURCE_ROOT}")
target_link_libraries(data_structures-a42ccdd0cdaa4160a9d04436b1966ee8_tests GTest::gtest ${GMOCK_LIB})

enable_testing()
add_test(NAME data_structures_tests
    COMMAND data_structures-a42ccdd0cdaa4160a9d04436b1966ee8_tests
    --gtest_output=json:${CMAKE_CURRENT_SOURCE_DIR}/../../test_reports/data_structures/gtest_report.json)
