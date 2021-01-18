@ECHO off
cmake -S . -B out
msbuild out\src\driver.vcxproj