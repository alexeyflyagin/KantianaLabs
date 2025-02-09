// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "ex_3.hpp"
#include "strings.hpp"
#include <iostream>
#include <string>

void ex3() {
    int n, m;
    std::cout << ENTER_N;
    std::cin >> n;
    std::cout << ENTER_M;
    std::cin >> m;

    int** arr = new int*[n]; // I use regular arrays, not vectors :)
    for (char i = 0; i < n; i++) { arr[i] = new int[m]; }

    std::cout << ENTER_EACH_CELL << std::endl;
    for (char i = 0; i < n; i++) {
        for (char j = 0; j < m; j++) { 
            std::cin >> arr[i][j]; 
        }
    }

    int maxProductColumnIndex = 0;
    for (char j = 0; j < m; j++) {
        int columnProduct = 1;
        for (char i = 0; i < n; i++) { 
            columnProduct *= arr[i][j]; 
        }
        if (columnProduct > maxProductColumnIndex) maxProductColumnIndex = j;
    }

    for (char i = 0; i < n; i++) {
        arr[i][maxProductColumnIndex] -= 3;
    }

    std::cout << std::endl << RESULT << std::endl;
    for (char i = 0; i < n; i++) {
        for (char j = 0; j < m; j++) { 
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) { 
        delete[] arr[i]; 
    }
    delete[] arr;
}
