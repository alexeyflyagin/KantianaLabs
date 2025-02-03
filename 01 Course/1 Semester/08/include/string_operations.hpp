#pragma once

#include <string>

namespace StringOperations
{

    const std::string VOWELS = "aeiouAEIOU";
    const std::string CONSONANTS = "bcdfghjklmnpqrtvwxzBCDFGHJKLMNPQRTVWXZ";
    const std::string REGEX_PATTERN__WORD = "[a-zA-Z]+";

    void tolower(std::string &it);

    void toupper(std::string &it);

    int getVowelsCount(std::string text);

    std::string getVowels(std::string text);

    std::string uniqueCharacters(std::string text);
}