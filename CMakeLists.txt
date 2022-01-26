cmake_minimum_required( VERSION 3.5 )
project( Autocomplete VERSION 1.0 LANGUAGES CXX )

include_directories( include )

add_executable( autocomplete
                src/Autocomplete.cpp
                src/Database.cpp
                src/IOManager.cpp )

set_property(TARGET autocomplete PROPERTY CXX_STANDARD 17)
