// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include <iostream>

void ex1() {
    int n;
    int p = 1;
    int max = INT_MIN;
    int maxIndex = 0;
    std::cout << "Enter the length of the sequence: ";
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        std::cout << i << ": ";
        std::cin >> x;
        if (x % 5 != 0) {
            p *= x;
            if (x > max) {
                max = x;
                maxIndex = i;
            }
        }
    }
    std::cout << "Product: " << p << "\t" << "max: " << max << " (" << maxIndex << ")" << std::endl;
}

void ex2() {
    int n;
    int p = 1;
    std::cout << "Enter the number: ";
    std::cin >> n;
    while (n != 0) {
        int ns = n % 10;
        if (ns % 2 != 0) p *= ns;
        n /= 10;
    }
    std::cout << "Product: " << p << std::endl;
}

int main()
{
    system("cls");
    ex1();
    std::cout << std::endl;
    ex2();
    return 0;
}
