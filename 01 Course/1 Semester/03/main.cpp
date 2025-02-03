// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include <iostream>

int main() {
    system("cls");

    unsigned x, i;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter i: ";
    std::cin >> i;
    unsigned int mask = ~(1 << (i - 1));
    x = x & mask;
    std::cout << x;

    return 0;
}
