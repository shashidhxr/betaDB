cmake_minimum_required(VERSION 3.10)
project(betaDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/Crow/include src)

add_executable(beta src/db.cpp src/main.cpp)

target_link_libraries(beta pthread)
