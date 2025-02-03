#include "ex1.hpp"
#include "string_operations.hpp"
#include "strings.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <regex>
#include <set>

namespace Lab8 {
    namespace Ex2 {

        void findWords(std::string text, std::vector<std::string>& words) {
            std::regex pattern(StringOperations::REGEX_PATTERN__WORD);
            auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
            auto words_end = std::sregex_iterator();
            for (auto it = words_begin; it != words_end; it++) {
                words.push_back(it->str());
            }
        }

        bool check(std::vector<std::string>& words) {
            for (int i = 0; i < words.size(); i++) {
                std::string vowels = StringOperations::getVowels(words[i]);
                std::string unique_vowels = StringOperations::uniqueCharacters(vowels);
                if (vowels.size() != unique_vowels.size()) return true;
            }
            return false;
        }

        void removeConsonants(std::string& text) {
            for (char consonant: StringOperations::CONSONANTS) {
                text.erase(std::remove(text.begin(), text.end(), consonant), text.end());
            }
        }

        void duplicateVowels(std::string& text) {
            std::string withDuplicates;
            for (char c: text) {
                if (StringOperations::VOWELS.find(c) != std::string::npos) withDuplicates += std::string(2, c);
                else withDuplicates += c;
            }
            text = withDuplicates;
        }
        
        std::string getOutputText(std::vector<std::string>& words) {
            std::string text;
            for (int i = 0; i < words.size(); i++) {
                text += words[i] + '\n';
            }
            return text;
        }

        int start(std::string inputFilePath, std::string outputFilePath) {
            std::string text = Lab8::getLineFromFile(inputFilePath);
            StringOperations::tolower(text);

            std::vector<std::string> words;
            findWords(text, words);
            if (check(words)) {
                for (std::string& word: words) { removeConsonants(word); }
            } else {
                for (std::string& word: words) {
                    if (StringOperations::getVowelsCount(word) >= 3) duplicateVowels(word);
                }
            }

            std::sort(words.begin(), words.end());

            std::string output_text = getOutputText(words);
            Lab8::writeToFile(output_text, outputFilePath);
            std::cout << output_text;
            
            return 0;
        }
    }
}