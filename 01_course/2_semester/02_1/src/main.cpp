// The laboratory work was performed by a 1st year student
// Direction: Mathematical support and administration of information systems
// Option: 8
// Flyagin Alexey

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
