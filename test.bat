@ECHO off
cmake -S . -B out\tests
msbuild out\tests\tests\TEST.vcxproj /property:Configuration=Release
out\tests\tests\Release\TEST.exe