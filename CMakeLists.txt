cmake_minimum_required(VERSION 3.12)

project(lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(lib main.cpp)

target_link_libraries(lib pthread)
