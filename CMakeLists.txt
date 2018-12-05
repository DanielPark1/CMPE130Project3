cmake_minimum_required(VERSION 3.8)
project(CMPE130Project3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        test.txt
        BigInteger.h
        BigInteger.cpp
        keypair.h
        keypair.cpp)
add_executable(CMPE130Project3 ${SOURCE_FILES})