// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович
// Вариант 8

#include "ex1.hpp"
#include "ex2.hpp"
#include "ex3.hpp"
#include "strings.hpp"

const std::string PATH_TO_PROJECT = "D:\\Study\\MO1_Labs\\lab_8\\";     // Установите путь до рабочей дирректории!

const std::string OUTPUT_FILE_PATH = PATH_TO_PROJECT + "output.txt";
const std::string EX1__INPUT_FILE_PATH = PATH_TO_PROJECT + "input.txt";
const std::string EX2__INPUT_FILE_PATH = PATH_TO_PROJECT + "input.txt";
const std::string EX3__INPUT_FILE_PATH = PATH_TO_PROJECT + "input.txt";

int main()
{
    system("cls");
    Lab8::Ex1::start(EX1__INPUT_FILE_PATH, OUTPUT_FILE_PATH);
    // Lab8::Ex2::start(EX2__INPUT_FILE_PATH, OUTPUT_FILE_PATH);
    // Lab8::Ex3::start(EX3__INPUT_FILE_PATH, OUTPUT_FILE_PATH);
}
