cmake_minimum_required(VERSION 3.10)

project(GoogleTestProject)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main_test test.cpp ../src/modify.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(main_test ${GTEST_LIBRARIES} pthread)

add_test(NAME my_test COMMAND main_test)
