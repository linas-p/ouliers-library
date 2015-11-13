cmake_minimum_required(VERSION 2.8)

project(OutliersLibrary)
enable_language(CXX)

set(TESTING "TRUE")
set(CMAKE_CXX_FLAGS "-std=c++11	-Wall -pedantic -Wsign-compare")

if(TESTING)
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

set (PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set (GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/googletest")

include_directories( "${SRC_DIR}" "${INC_DIR}"
	${GTEST_DIR} ${GTEST_DIR}/include)

file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
set (LIB_NAME "calculating")
set (PROJECT_NAME "Outliers")

add_library ("${LIB_NAME}" STATIC ${SRC_FILES})
add_executable("${PROJECT_NAME}" ./main.cpp)
target_link_libraries(${PROJECT_NAME} "${LIB_NAME}")


if(TESTING)
	enable_testing()
	add_custom_target(
		git_update
		COMMAND git submodule init
		COMMAND git submodule update
		WORKING_DIRECTORY ${PROJECT_DIR}
		)
	add_library(gtest
		${GTEST_DIR}/src/gtest-all.cc
		${GTEST_DIR}/src/gtest_main.cc)
	add_dependencies(gtest git_update)
	include_directories(${GTEST_DIR})
	set_source_files_properties(${GTEST_DIR}/src/gtest-all.cc  PROPERTIES GENERATED 1)
	set_source_files_properties(${GTEST_DIR}/src/gtest-all.cc  PROPERTIES GENERATED 1)

	set (TEST_EXEC "${LIB_NAME}_test")
	set (TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
	file (GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp" )
	add_executable ("${TEST_EXEC}" ${TEST_SRC_FILES})
	add_dependencies(${TEST_EXEC} gtest)
	target_link_libraries ("${TEST_EXEC}" gtest "${LIB_NAME}" pthread)

	include(CTest)
	add_test(unit ${TEST_EXEC})
endif()
