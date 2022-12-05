########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14) # googletest min cpp standard is c++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")# to deal clion debug invalid

set(PROJECT_NAME "she_base64" VERSION 0.0.1)
set(CMAKE_BUILD_TYPE "RELEASE") # Release or Debug or MinSizeRel
project(${PROJECT_NAME})

########################################################################################################################
set(unit_test "on")
set(library "on")

# test set
if (unit_test STREQUAL "on")
    set(unit_test_name "she_base64_test")
else()
    message(STATUS "CMakeLists.txt error")
endif ()

# lib set
if (library STREQUAL "on")
    set(library_name "she_base64")
else()
    message(STATUS "CMakeLists.txt error")
endif ()

########################################################################################################################
# set 3rd path
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
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
# test target
if (unit_test STREQUAL "on")
    file(GLOB_RECURSE TEST_SRC "${CMAKE_SOURCE_DIR}/test/*")
    add_executable(${unit_test_name} ${TEST_SRC} ${SRC})
    target_link_libraries(${unit_test_name} "-pthread" gmock gtest)
else()
    message(STATUS "CMakeLists.txt error")
endif ()

# lib target
if (library STREQUAL "on")
    add_library(${library_name} STATIC ${SRC}) #  STATIC SHARED
else()
    message(STATUS "CMakeLists.txt error")
endif ()

########################################################################################################################
# install include
install(FILES
        ${CMAKE_SOURCE_DIR}/src/sheBase64.h # source head
        DESTINATION # to
        ${CMAKE_SOURCE_DIR}/sheBase64/include # target dir
        )
# install lib
install(TARGETS
        ${library_name}
        DESTINATION
        ${CMAKE_SOURCE_DIR}/sheBase64/lib
        )


