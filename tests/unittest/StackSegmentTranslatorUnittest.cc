#include <iostream>
#include <StackSegmentTranslator.h>

class StackSegmentTranslatorUnittest {
public:
    void run(){
        StackSegmentTranslator translator;
        std::string vmCode = "";
        vmCode += translator.PushFromD();
        vmCode += translator.PopToD();
        std::string answer = "@SP\nA=M\nM=D\n@SP\nM=M+1\n@SP\nA=M\nD=M\n@SP\nM=M-1\n";
        std::cout << "StackSegmentTranslator: ";
        if(vmCode == answer){
            std::cout << "[O] Test Passed!\n";
        }
        else{
            std::cout << "[X] TEST NOT PASSED!\n";
            std::cout << vmCode << "\n\n" << answer;
        }
        return;
    }
private:
};