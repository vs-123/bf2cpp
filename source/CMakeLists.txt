cmake_minimum_required(VERSION 3.5)

project(bf
        VERSION 0.0.1
        DESCRIPTION "A BF to CPP compiler"
        LANGUAGES CXX)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(bf main.cpp ${SOURCE_FILES})
target_compile_features(bf PRIVATE cxx_std_20)
target_include_directories(bf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)