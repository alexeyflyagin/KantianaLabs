// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include <iostream>
#include "utils.hpp"
#include "strings.hpp"


int main()
{
    system("cls");

    int n;
    bool check = false;
    std::cout << Lab9::ENTER_N;
    std::cin >> n;

    Lab9::IntSingleLinkedList list;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        if (std::to_string(value).size() == 3 && Lab9::onlyOddDigits(value)) check = true; 
        list.append(value);
    }

    if (check) {
        list.remove_if([](int n) { return !Lab9::containsDigit(n, 8); });
        list.duplicate_all();
    } else {
        list.sort([](int n1, int n2) {
            return Lab9::getFirstDigit(n1) > Lab9::getFirstDigit(n2);
        });
    }

    std::cout << std::endl << list.toString() << std::endl;
}
