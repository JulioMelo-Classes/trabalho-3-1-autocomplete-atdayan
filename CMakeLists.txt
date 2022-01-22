cmake_minimum_required(VERSION 3.5)
project(Autocomplete VERSION 1.0 LANGUAGES CXX )

include_directories( include )

add_executable( autocomplete
                src/Autocomplete.cpp
                src/IOManager.cpp )
