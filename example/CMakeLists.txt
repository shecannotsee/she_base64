cmake_minimum_required(VERSION 3.11)

set(project_name "example")
project(${project_name})

# modify to your install path
set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/all_code/sheBase64/cmake-build-debug/she_base64")

find_package(she_base64)

# check
message(STATUS "----: ${she_base64}")
message(STATUS "----: ${she_base64_FOUND}")
message(STATUS "----: ${she_base64_INCLUDE_DIR}")
message(STATUS "----: ${she_base64_LIBRARIES}")
message(STATUS "----: ${she_base64_LINK_DIRECTORIES}")


if(she_base64_FOUND)
    include_directories(${she_base64_INCLUDE_DIR})
    link_directories(${she_base64_LIBRARIES})
else()
    message(WARNING "can not found")
endif()


add_executable(${project_name} ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(${project_name} "-pthread" ${she_base64_LINK_DIRECTORIES})

