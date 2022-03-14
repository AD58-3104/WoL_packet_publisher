cmake_minimum_required(VERSION 3.10)
project(wol_packet_publisher)

find_package(Boost REQUIRED COMPONENTS thread)

add_executable(magic_packet_pub main.cpp publisher.hpp)
target_include_directories(magic_packet_pub PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(magic_packet_pub ${Boost_LIBRARIES})