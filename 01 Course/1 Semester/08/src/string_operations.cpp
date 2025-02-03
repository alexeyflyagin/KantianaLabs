// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "string_operations.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
#include <set>

namespace StringOperations {

    void tolower(std::string& it) {
        std::transform(it.begin(), it.end(), it.begin(), [](char c) {
            return std::tolower(c); 
        });
    }

    void toupper(std::string& it) {
        std::transform(it.begin(), it.end(), it.begin(), [](char c) {
            return std::toupper(c); 
        });
    }

    std::string replaceVowels(std::string text, char new_char) {
        std::string replaced_text = text;
        for (unsigned char c: VOWELS) {
            int pos = 0;
            while ((pos = replaced_text.find_first_of(c, pos)) != std::string::npos) {
                replaced_text.replace(pos, 1, "*");
                pos++;
            }
        }
        return replaced_text;
    }

    int countSubstrings(std::string text, std::string pattern) {
        std::regex regex_pattern(pattern);
        auto begin = std::sregex_iterator(text.begin(), text.end(), regex_pattern);
        auto end = std::sregex_iterator();
        return std::distance(begin, end);
    }

    int getVowelsCount(std::string text) {
        std::string replaced_text = replaceVowels(text, '*');
        return countSubstrings(replaced_text, "\\*\\*");
    }

    std::string getVowels(std::string text) {
        std::string foundVowels;
        for (char c: text) {
            if (VOWELS.find(c) != std::string::npos) foundVowels += c;
        }
        return foundVowels;
    }

    std::string uniqueCharacters(std::string text) {
        std::set<char> unique_chars(text.begin(), text.end());
        return std::string(unique_chars.begin(), unique_chars.end());
    }
}


