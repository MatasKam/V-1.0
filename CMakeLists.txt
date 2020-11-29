# CMakeList.txt : CMake project for gg, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("gg")

# Add source to this project's executable.
add_executable (gg "gg.cpp" "biblioteka.h" "duomenys.h" "rasymas.cpp")

# TODO: Add tests and install targets if needed.
