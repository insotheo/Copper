cmake_minimum_required(VERSION 3.10)

project(Copper)

file(GLOB SOURCES
src/*.cpp
)

add_executable("copper" "${SOURCES}")