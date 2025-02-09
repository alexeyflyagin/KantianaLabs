#include "utils.hpp"
#include <string>
#include <fstream>

namespace Lab8 {
    std::string getLineFromFile(std::string filePath) {
        std::string text;
        std::string line;
        std::ifstream inputFile(filePath);
        while (getline(inputFile, line)) { text += line + " "; }
        inputFile.close();
        return text;
    }

    std::string getTextFromFile(std::string filePath) {
        std::string text;
        std::string line;
        std::ifstream inputFile(filePath);
        while (getline(inputFile, line)) { text += line + "\n"; }
        inputFile.close();
        return text;
    }


    void writeToFile(std::string text, std::string filePath) {
        std::ofstream outputFile(filePath);
        outputFile << text;
        outputFile.close();
    }
}
