#include <iostream>
#include "unittest/StackSegmentTranslatorUnittest.cc"

int main(){
    std::cout << "Running Test Sets...\n";
    StackSegmentTranslatorUnittest test;
    test.run();
    return 0;
}