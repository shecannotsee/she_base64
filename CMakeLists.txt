########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14) # googletest min cpp standard is c++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")# to deal clion debug invalid

#set(target "test")
set(target "libshe_base64")
if (target STREQUAL "test")
    set(PROJECT_NAME "she_base64_test")
elseif(target STREQUAL "libshe_base64")
    set(PROJECT_NAME "she_base64")
else()
    message(STATUS "CMakeLists.txt error")
endif ()
project(${PROJECT_NAME})

########################################################################################################################
# set path
set(googletest "${CMAKE_SOURCE_DIR}/libraries/googletest")

########################################################################################################################
# include
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        ${googletest}/include)
# lib
link_directories(${googletest}/lib)

########################################################################################################################
# set target,test executable or lib
if (target STREQUAL "test")
    file(GLOB_RECURSE TEST "${CMAKE_SOURCE_DIR}/test/*")
    add_executable(${PROJECT_NAME} ${TEST})
elseif(target STREQUAL "libshe_base64")
    file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
    add_library(${PROJECT_NAME} STATIC ${SRC}) #  STATIC SHARED
else()
    message(STATUS "Target error")
endif ()

########################################################################################################################
# link
target_link_libraries(${PROJECT_NAME} "-pthread" gmock gtest)
