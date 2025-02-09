// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "ex_2.hpp"
#include "utils.hpp"
#include "strings.hpp"
#include <iostream>
#include <set>
#include <algorithm>

void ex2()
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
        arr.push_back(j);
    }
    sort(arr.begin(), arr.end(), [](int a, int b)
    {
        std::vector<int> aDigits = getDigitsFromNum(a);
        std::vector<int> bDigits = getDigitsFromNum(b);
        int aSum = getSum(aDigits);
        int bSum = getSum(bDigits);
        if (aSum == bSum) 
        {
            int aMin = *min_element(aDigits.begin(), aDigits.end());
            int bMin = *min_element(bDigits.begin(), bDigits.end());
            if (aMin == bMin) return a < b;
            return aMin < bMin;
        }
        return aSum < bSum;
    });
    std::cout << fromVectorToString(arr);
}
