// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "ex_1.hpp"
#include "utils.hpp"
#include "strings.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

void ex1()
{
    int n;
    std::cout << ENTER_N;
    std::cin >> n;
    int c = 0;
    std::vector<int> arr;
    std::cout << ENTER_SEQUENCE;
    for (int i = 0; i < n; i++)
    {
        int j;
        std::cin >> j;
        std::string jString = std::to_string(j);
        std::set<char> jSet(jString.begin(), jString.end());
        if (jSet.size() == 1 && jString.size() > 1) c++;
        arr.push_back(j);
    }
    if (c >= 3) std::sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
    std::cout << fromVectorToString(arr);
}
