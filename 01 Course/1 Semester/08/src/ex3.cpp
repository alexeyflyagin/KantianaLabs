#include "ex1.hpp"
#include "string_operations.hpp"
#include "strings.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <regex>
#include <set>

namespace Lab8 {
    namespace Ex3 {

        std::string getSpecialCharacters(std::string text) {
            std::vector<std::string> words;
            std::string characters;
            std::regex pattern(StringOperations::REGEX_PATTERN__WORD);
            auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
            auto words_end = std::sregex_iterator();
            for (auto it = words_begin; it != words_end; it++) { words.push_back(it->str()); }
            sort(words.begin(), words.end(), [](std::string& f_str, std::string& s_str) {
                return f_str.size() > s_str.size();
            });
            int maxLength = words[0].size();
            for (std::string word: words) {
                if (word.size() != maxLength) break;
                characters += word;
            }
            std::set<char> setOfCharacters(characters.begin(), characters.end());
            return std::string(setOfCharacters.begin(), setOfCharacters.end());
        }

        std::string getAnotherCharacters(std::string word, std::string specialCharacters) {
            std::set<char> anotherCharacters;
            StringOperations::tolower(word);
            for (char c: word) {
                if (specialCharacters.find(c) == std::string::npos) anotherCharacters.insert(c);
            }
            return std::string(anotherCharacters.begin(), anotherCharacters.end());
        }

        std::string format(std::string text, std::string specialCharacters) {
            std::string replaced_text = text; 
            std::regex pattern(StringOperations::REGEX_PATTERN__WORD);
            auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
            auto words_end = std::sregex_iterator();
            int offset = 0;
            for (auto it = words_begin; it != words_end; it++) {
                std::string anotherCharacters = getAnotherCharacters(it->str(), specialCharacters);
                if (anotherCharacters.size() != 0) {
                    std::string replacement = it->str();
                    StringOperations::toupper(replacement);
                    replacement += "(" + anotherCharacters + ")";
                    replaced_text.replace(it->position() + offset, it->length(), replacement);
                    offset += replacement.size() - it->str().size();
                }
            }
            return replaced_text;
        }

        int start(std::string inputFilePath, std::string outputFilePath) {
            std::string text = Lab8::getTextFromFile(inputFilePath);

            std::string lower_text = text;
            StringOperations::tolower(lower_text);

            std::string characters = getSpecialCharacters(lower_text);
            std::string formatted_text = format(text, characters);

            Lab8::writeToFile(formatted_text, outputFilePath);
            std::cout << formatted_text;
            
            return 0;
        }
    }
}