cmake_minimum_required(VERSION 2.8)

project(OutliersLibrary)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -g  -pedantic -I. -Wall -pthread")

enable_testing()
include_directories( ./include ${GTEST_HOME}/include )
add_library(calculating STATIC ./src/calculator.cpp)
link_directories( ${GTEST_HOME}/lib )
add_executable(Outliers ./main.cpp)
target_link_libraries(Outliers calculating)


add_executable( runUnitTests ./tests/test_generation.cpp )
target_link_libraries(runUnitTests gtest_main.so gtest.so )
add_test( runUnitTests runUnitTests )


