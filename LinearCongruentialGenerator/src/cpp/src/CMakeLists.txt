cmake_minimum_required(VERSION 3.2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_library(liblcg lcg.cpp)
add_executable(lcgdemo demolcg.cpp)
target_link_libraries(lcgdemo liblcg)

add_executable(lcgtest testlcg.cpp)
target_link_libraries(lcgtest liblcg ${GTEST_LIBRARIES} pthread)

add_executable(boostlcgtest testboostlcg.cpp)
target_link_libraries(boostlcgtest ${GTEST_LIBRARIES} pthread)

