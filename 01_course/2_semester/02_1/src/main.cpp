// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include <iostream>
#include <cmath>
#include "strings.hpp"


bool isPrimeHelper(const int n, const int divisor) {
    if (divisor == 1) return true;
    if (n % divisor == 0) return false;
    return isPrimeHelper(n, divisor - 1);
}


bool isPrime(const int n) {
    const int divisor = static_cast<int>(sqrt(n));
    return isPrimeHelper(n, divisor);
}


int main() {
    system("cls");

    int n;
    std::cout << Lab1::ENTER_N;
    std::cin >> n;

    std::cout << (isPrime(n) ? Lab1::IS_PRIME : Lab1::IS_NOT_PRIME) << std::endl;
}
