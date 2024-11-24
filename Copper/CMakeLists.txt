cmake_minimum_required(VERSION 3.10)

project(Copper)

file(GLOB SOURCES
src/*.cpp
src/Lexer/*.cpp
)

file(GLOB HEADERS
src/*.hpp
src/Token/*.hpp
src/Lexer/*.hpp
)

add_executable("copper" "${SOURCES}" "${HEADERS}")

include_directories(src/)