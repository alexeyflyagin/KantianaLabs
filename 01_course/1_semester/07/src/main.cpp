// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "utils.hpp"
#include "matrix_operations.hpp"
#include "strings.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace MatrixOperations;

int main()
{
    system("cls");

    int n;
    std::cout << ENTER_N;
    std::cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) { matrix[i] = new int[n]; }

    inputMatrix(matrix, n);
    processMatrix(matrix, n);
    std::cout << std::endl << RESULT << std::endl;
    showMatrix(matrix, n);

    for (int column = 0; column < n; column++) { 
        delete[] matrix[column]; 
    }
    delete[] matrix;

    return 0;
}
