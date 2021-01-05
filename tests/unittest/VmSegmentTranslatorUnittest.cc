#include <iostream>
#include <VmSegmentTranslator.h>

class VmSegmentTranslatorUnittest {
public:
    void run(){
        VmSegmentTranslator translator = {"static"};
        std::string vmCode = "";
        vmCode += translator.PutToD("5");
        std::cout << "VmSegmentTranslator: ";
        if(vmCode == answer_){
            std::cout << "[O] Test Passed!\n";
        }
        else{
            std::cout << "[X] TEST NOT PASSED!\n";
            std::cout << vmCode << "\n\n" << answer_;
        }
        return;
    }
private:
    std::string answer_ = "@5\nD=A\n@static\nA=M\nA=A+D\nD=M\n";
};