cmake_minimum_required(VERSION 3.10)

project(Herbata VERSION 0.0.0)

file(GLOB SOURCES
src/*.cpp
src/Lexer/*.cpp
src/Parser/*.cpp
src/LangDefs/*.cpp
)

file(GLOB HEADERS
src/*.hpp
src/Token/*.hpp
src/Lexer/*.hpp
src/Parser/*.hpp
src/LangDefs/*.hpp
)

add_executable("herbata" "${SOURCES}" "${HEADERS}")

include_directories(src/)