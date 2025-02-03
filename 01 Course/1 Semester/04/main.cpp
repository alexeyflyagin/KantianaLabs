// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include <iostream>

const std::string NEGATIVE_NUM_TEXT = "Negative number";
const std::string POSITIVE_NUM_TEXT = "Positive number";
const std::string ERROR__INCORRECT_VAR_FORMAT = "Error: incorrect variable format.";

int main()
{
    system("cls");

    // ex. 1
    int a, b, c;
    std::cout << "Enter a, b, c:" << std::endl;
    std::cin >> a >> b >> c;
    if (a % c == 0 && b % c == 0) std::cout << (a + b) / c << std::endl;
    else if (a % c == 0 && b % c != 0) std::cout << a / c + b << std::endl;
    else std::cout << a - b - c << std::endl;
    std::cout << std::endl;



    // ex. 2
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    switch (n)
    {
    case 0:
        std::cout << "zero" << std::endl;
        break;
    case 1:
        std::cout << "one" << std::endl;
        break;
    case 2:
        std::cout << "two" << std::endl;
        break;
    case 3:
        std::cout << "three" << std::endl;
        break;
    case 4:
        std::cout << "four" << std::endl;
        break;
    case 5:
        std::cout << "five" << std::endl;
        break;
    case 6:
        std::cout << "six" << std::endl;
        break;
    case 7:
        std::cout << "seven" << std::endl;
        break;
    case 8:
        std::cout << "eight" << std::endl;
        break;
    case 9:
        std::cout << "nine" << std::endl;
        break;
    default:
        std::cout << ERROR__INCORRECT_VAR_FORMAT << std::endl;
        break;
    }
    std::cout << std::endl;



    // ex. 3
    int x;
    std::cout << "Enter x (only -1 or 1): ";
    std::cin >> x;
    if (x == -1)
        std::cout << NEGATIVE_NUM_TEXT;
    else if (x == 1)
        std::cout << POSITIVE_NUM_TEXT;
    // В данном случае можно было использовать и switch, но я не стал, так как switch выглядит более грамоздким по кол-ву строчек кода.
    // Также можно было бы записать и два if подряд вместо использования вложенных условий в блок else, однако это нецелесообразно:
    // Нам не нужно проверять второе условие, если уже подошло первое (лишнее действие).
    std::cout << std::endl;

    return 0;
}
