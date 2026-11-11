cmake_minimum_required(VERSION 3.12)
project(leetcode-solutions-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")

foreach(file ${SOURCES})
    get_filename_component(target_name ${file} NAME_WE)
    add_executable(${target_name} ${file})
endforeach()