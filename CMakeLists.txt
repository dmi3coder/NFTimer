cmake_minimum_required(VERSION 3.9)
project(NFTimer)

include_directories(/)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(nf nf.c TimeHandler.c Database.c)

include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(nf sqlite3)
