#!/bin/bash
cmake -S . -B out -G "Ninja" -DCMAKE_CXX_COMPILER=g++
ninja -C out