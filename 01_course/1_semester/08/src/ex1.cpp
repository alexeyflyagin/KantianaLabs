#include "ex1.hpp"
#include "string_operations.hpp"
#include "strings.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <regex>
#include <set>

namespace Lab8 {
    namespace Ex1 {

        void findWords(std::string text, std::vector<std::pair<int, std::string>>& results) {
            std::regex pattern(StringOperations::REGEX_PATTERN__WORD);
            auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
            auto words_end = std::sregex_iterator();
            for (auto it = words_begin; it != words_end; it++) {
                int vowels_count = StringOperations::getVowelsCount(it->str());
                if (vowels_count != 0) {
                    std::pair<int, std::string> pair(vowels_count, it->str());
                    results.push_back(pair);
                }
            }
        }

        void uniqueWords(std::vector<std::pair<int, std::string>>& results) {
            std::set<std::pair<int, std::string>> uniqueSet(results.begin(), results.end());
            std::vector<std::pair<int, std::string>> uniqueResults(uniqueSet.begin(), uniqueSet.end());
            results = uniqueResults;
        }

        std::string getOutputText(std::vector<std::pair<int, std::string>>& results) {
            std::string text;
            for (int i = 0; i < results.size(); i++) {
                text += results[i].second + " - " + std::to_string(results[i].first) + '\n';
            }
            return text;
        }

        int start(std::string inputFilePath, std::string outputFilePath) {
            std::string text = Lab8::getLineFromFile(inputFilePath);
            StringOperations::tolower(text);

            std::vector<std::pair<int, std::string>> results;
            findWords(text, results);
            uniqueWords(results);

            std::sort(results.begin(), results.end(), [](std::pair<int, std::string>& f_pair, std::pair<int, std::string>& s_pair) {
                return f_pair.first > s_pair.first;
            });

            std::string result_text = getOutputText(results);
            Lab8::writeToFile(result_text, outputFilePath);
            std::cout << result_text;
            
            return 0;
        }
    }
}