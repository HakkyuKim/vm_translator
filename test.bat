@ECHO off
cmake -S . -B out\tests
msbuild out\tests\vm_translator.vcxproj -property:Configuration=Release

out\tests\Release\vm_translator.exe tests\project\07\MemoryAccess\BasicTest\BasicTest.vm tests\project\07\MemoryAccess\BasicTest\BasicTest.asm
out\tests\Release\vm_translator.exe tests\project\07\MemoryAccess\PointerTest\PointerTest.vm tests\project\07\MemoryAccess\PointerTest\PointerTest.asm
out\tests\Release\vm_translator.exe tests\project\07\MemoryAccess\StaticTest\StaticTest.vm tests\project\07\MemoryAccess\StaticTest\StaticTest.asm
out\tests\Release\vm_translator.exe tests\project\07\StackArithmetic\SimpleAdd\SimpleAdd.vm tests\project\07\StackArithmetic\SimpleAdd\SimpleAdd.asm
out\tests\Release\vm_translator.exe tests\project\07\StackArithmetic\StackTest\StackTest.vm tests\project\07\StackArithmetic\StackTest\StackTest.asm

out\tests\Release\vm_translator.exe tests\project\08\ProgramFlow\BasicLoop\BasicLoop.vm tests\project\08\ProgramFlow\BasicLoop\BasicLoop.asm
out\tests\Release\vm_translator.exe tests\project\08\ProgramFlow\FibonacciSeries\FibonacciSeries.vm tests\project\08\ProgramFlow\FibonacciSeries\FibonacciSeries.asm

REM out\tests\Release\vm_translator.exe tests\project\08\FunctionCalls\SimpleFunction\SimpleFunction.vm tests\project\08\FunctionCalls\SimpleFunction\SimpleFunction.asm

python3 validate.py