@ECHO off
cmake -S . -B out -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++
mingw32-make -C out