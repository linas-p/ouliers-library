cmake_minimum_required(VERSION 2.8)

project(OutliersLibrary)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -g  -pedantic -I. -Wall -pthread -ggdb -fprofile-arcs -ftest-coverage")
set (CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")


enable_testing()
include_directories( "${SRC_DIR}" "${INC_DIR}" )

file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
set (LIB_NAME "calculating")
set (PROJECT_NAME "Outliers")
add_library ("${LIB_NAME}" STATIC ${SRC_FILES})

link_directories( ${GTEST_HOME}/lib )
add_executable("${PROJECT_NAME}" ./main.cpp)
target_link_libraries(${PROJECT_NAME} "${LIB_NAME}")


## testing
set (GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/googletest")
add_subdirectory (${GTEST_DIR})
include_directories ("${GTEST_DIR}/include")
set (TEST_EXEC "${LIB_NAME}_test")
set (TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
file (GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp")
add_executable ("${TEST_EXEC}" ${TEST_SRC_FILES})
target_link_libraries ("${TEST_EXEC}" "${LIB_NAME}" "gtest" "gtest_main")



