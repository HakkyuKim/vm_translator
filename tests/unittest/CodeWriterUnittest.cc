#include <iostream>
#include <CodeWriter.h>

class CodeWriterUnittest {
public:
    void run(){
        CodeWriter writer;
        Tokens tokens = Tokens();
        tokens.operation = OperationType::POP;
        tokens.segmentType = SegmentType::LOCAL;
        tokens.index = "10";
        std::string vmCode = writer.Decode(tokens);
        std::cout << "CodeWriter: ";
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
    std::string answer_ = "";
};