// Лабораторную работу выполнил студент 1 курса
// Направление: Математическое обеспечение и администрирование информационных систем
// Флягин Алексей Иванович

#include <iostream>
#include <string>

using namespace std;


void showType(string type, string volume, string range) {
    cout << type << ":\t" << volume << " (" << range << ")" << endl;
}

int main() {
    system("cls");

    // 1. Переменная - это объект в оперативной памяти, содержащий значение, тип и имя, по которому к этому объекту можно обращаться.
    //
    //
    // 2.1 Целочисленные типы данных:
    // - знаковые: char (1 байт, -128..127), short (2 байта, −32 768..32 767), int (4 байта, −2^31..2^31-1), long long (8 байт, -2^63..2^63-1),
    // - беззнаковые unsigned int (4 байта, 0..2^32-1)
    //
    // 2.2 Символьные:
    // char (1 байт, -128..127)
    //
    // 2.3 Вещественные:
    // float (4 байта, 6-7 знач. цифр), double (8 байт, 15-16 значащих цифр)
    //
    // 2.4 Логический:
    // bool (1 байт, true/false)

    cout << "Data types and operations with them" << endl;
    cout << endl;
    
    cout << "Integer:" << endl;
    showType("char", "1 byte", "-128..127");
    char ch_a = -2;
    char ch_b = -4;
    char ch_r = ch_a + ch_b;
    showType("short", "2 byte", "-32 768..32 767");
    short short_a = -128;
    short short_b = 24;
    short short_r = short_a - short_b;
    showType("int", "4 byte", "-2^31..2^31-1");
    int int_a = -2314;
    int int_b = 543;
    int int_r = int_a / int_b;
    showType("long long", "8 byte", "-2^63..2^63-1");
    long long_a = 431;
    long long_b = -5142524352;
    long long_r = long_a * long_b;
    showType("unsigned int", "4 byte", "0..2^32-1");
    unsigned int uint_a = 4;
    unsigned int uint_b = 23145;
    unsigned int uint_r = uint_b % uint_a;
    cout << endl;

    cout << "Symbolic:" << endl;
    showType("char", "1 byte", "-128..127");
    char sym_a = 4;
    sym_a += 5;
    cout << endl;

    cout << "Real:" << endl;
    showType("float", "4 byte", "6-7 significant figures");
    float float_a = 43.32f;
    float float_b = -321.26556f;
    float float_r = float_a * float_b;
    showType("double", "8 byte", "15-16 significant figures");
    double double_a = 2.3231234443f;
    double double_b = -3.265532136f;
    double double_r = double_a / double_b;
    cout << endl;

    cout << "Logical:" << endl;
    showType("bool", "1 byte", "true / false");
    bool bool_a = true;
    bool bool_b = false;
    bool bool_r = bool_a * bool_b;

    return 0;
}
