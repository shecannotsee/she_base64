cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14) # googletest min cpp standard is c++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "googletest_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

#
get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode}")
get_filename_component(sheTestcode_f ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode_f's path:${sheTestcode_f}")

set(googletest "${sheTestcode_f}/libraries/googletest-v1.12.1")
########################################################################################################################

# include
include_directories(
        ${googletest}/include
)
# lib
link_directories(
        ${googletest}/lib/
)

########################################################################################################################

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )
########################################################################################################################

# 链接库
target_link_libraries(${PROJECT_NAME}
        "-pthread"
        gmock gtest
        )
