#pragma once
#include <string>

namespace Lab8 {
    
    std::string getLineFromFile(std::string file_path);
    
    std::string getTextFromFile(std::string file_path);

    void writeToFile(std::string text, std::string file_path);
}
