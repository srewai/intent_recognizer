cmake_minimum_required (VERSION "3.10.2")

#our project name
project("intent_recognizer")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
add_executable ("${PROJECT_NAME}" "main.cpp" "main.h")

