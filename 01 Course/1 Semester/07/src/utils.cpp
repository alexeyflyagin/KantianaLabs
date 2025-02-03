// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "utils.hpp"
#include <iostream>
#include <vector>
#include <numeric>

int getSumOfDigits(int num)
{
    std::vector<int> a;
    while (num != 0)
    {
        a.push_back(num % 10);
        num /= 10;
    }
    reverse(a.begin(), a.end());
    return accumulate(a.begin(), a.end(), 0);
}
