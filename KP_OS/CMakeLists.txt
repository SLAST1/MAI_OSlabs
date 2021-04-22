cmake_minimum_required(VERSION 3.16)
project(oskp1)

set(CMAKE_CXX_STANDARD 17)


add_library(utility_lib lib.cpp)

add_executable(A client-hw.cpp)
add_executable(B server-hw.cpp)
add_executable(C server2-hw.cpp)


target_link_libraries(utility_lib zmq)
target_link_libraries(A zmq utility_lib)
target_link_libraries(B zmq utility_lib)
target_link_libraries(C zmq utility_lib pthread)
