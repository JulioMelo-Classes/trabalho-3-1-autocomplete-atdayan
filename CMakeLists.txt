cmake_minimum_required(VERSION 3.5)
project(Autocomplete VERSION 1.0 LANGUAGES CXX )

include_directories( include )

add_executable( autocomplete
                src/Autocomplete.cpp
                src/Database.cpp
                src/IOManager.cpp )

#adicionei aqui uma vez que vc está usando c++17 no using namespace ..., ...,
set_property(TARGET autocomplete PROPERTY CXX_STANDARD 17) 