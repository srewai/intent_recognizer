cmake_minimum_required(VERSION 3.10)
project(intent_recognizer)

set( CMAKE_CXX_STANDARD 11 )

add_executable( "${PROJECT_NAME}" "main.cpp" )

enable_testing()
add_test( NAME Tests COMMAND "${PROJECT_NAME}" test )