#include <iostream>
#include "unittest/StackSegmentTranslatorUnittest.cc"
#include "unittest/VmSegmentTranslatorUnittest.cc"
#include "unittest/CodeWriterUnittest.cc"

int main(){
    std::cout << "Running Test Sets...\n";
    StackSegmentTranslatorUnittest test;
    VmSegmentTranslatorUnittest test2;
    CodeWriterUnittest test3;
    
    test.run();
    test2.run();
    test3.run();
    return 0;
}