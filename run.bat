@ECHO off
out\src\Debug\driver.exe tests\project\07\StackArithmetic\SimpleAdd\SimpleAdd.vm 
out\src\Debug\driver.exe tests\project\07\StackArithmetic\StackTest\StackTest.vm 
out\src\Debug\driver.exe tests\project\07\MemoryAccess\BasicTest\BasicTest.vm 
out\src\Debug\driver.exe tests\project\07\MemoryAccess\StaticTest\StaticTest.vm 
out\src\Debug\driver.exe tests\project\07\MemoryAccess\PointerTest\PointerTest.vm 

out\src\Debug\driver.exe tests\project\08\ProgramFlow\BasicLoop\BasicLoop.vm 
out\src\Debug\driver.exe tests\project\08\ProgramFlow\FibonacciSeries\FibonacciSeries.vm 

out\src\Debug\driver.exe tests\project\08\FunctionCalls\SimpleFunction\SimpleFunction.vm 
out\src\Debug\driver.exe tests\project\08\FunctionCalls\FibonacciElement -bootstrap 261
out\src\Debug\driver.exe tests\project\08\FunctionCalls\StaticsTest 