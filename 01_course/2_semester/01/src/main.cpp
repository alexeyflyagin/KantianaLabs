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
    std::cout << Lab1::ENTER_N;
    std::cin >> n;

    Lab1::DoublyLinkedList list;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        list.append(value);
    }

    if (list.is_sorted(true) || list.is_sorted(false)) {
        std::cout << "first" << std::endl;
        list.remove_if([](int n) { return Lab1::isPrime(n); });
        list.duplicate_if([](int n) { return n % 10 == 0; });
    } else {
        std::cout << "second" << std::endl;
        list.sort([](int n1, int n2) {
            return Lab1::getFirstDigit(n1) < Lab1::getFirstDigit(n2);
        });
    }

    std::cout << std::endl << list.toString() << std::endl;
}
