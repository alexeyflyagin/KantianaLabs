// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "utils.hpp"
#include <algorithm>
#include <vector>
#include <string>

std::string fromVectorToString(std::vector<int> arr)
{
    std::string r;
    for (auto element : arr) { r += std::to_string(element) + " "; }
    return r;
}

std::vector<int> getDigitsFromNum(int num)
{
    std::vector<int> a;
    while (num != 0)
    {
        a.push_back(num % 10);
        num /= 10;
    }
    std::reverse(a.begin(), a.end());
    return a;
}

int getSum(std::vector<int> arr)
{
    int r = 0;
    for (int i : arr) { r += i; }
    return r;
}
