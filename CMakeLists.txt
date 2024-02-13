cmake_minimum_required(VERSION 3.23)

set(MY_PROJECT_NAME "CPP_TEMPLATE")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	MY_PROJECT_NAME
	VERSION 0.1.0
	LANGUAGES CXX
)

find_package(GTest REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable(MY_PROJECT_NAME src/main.cpp)
target_link_libraries(MY_PROJECT_NAME gtest::gtest)
target_link_libraries(MY_PROJECT_NAME SQLite::SQLite3)
target_link_libraries(MY_PROJECT_NAME Boost::boost)





# Prevent building in the source directory
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
	message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()



# Testing
include(CTest)
include(GoogleTest)

add_executable(mainTest ./src/mainTest.cpp)
target_link_libraries(mainTest GTest::gtest_main)

add_test(NAME testMainReturns COMMAND MY_PROJECT_NAME)

add_test(NAME testMainOuput COMMAND MY_PROJECT_NAME)
set_property(TEST testMainOuput PROPERTY PASS_REGULAR_EXPRESSION "Hello World!")

gtest_discover_tests(mainTest TEST_PREFIX gtest.)
gtest_discover_tests(MY_PROJECT_NAME)