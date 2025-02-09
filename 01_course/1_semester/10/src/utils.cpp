#include "utils.hpp"

namespace Lab9 {

    bool onlyOddDigits(int num) {
        if (num == 0) return false;
        int temp = num;
        while (temp != 0) {
            int s = temp % 10;
            if (s % 2 == 0) return false;
            temp /= 10;
        }
        return true;
    }

    int getFirstDigit(int num) {
        if (num == 0) return 0;
        int temp = num;
        int r = 0;
        while (temp != 0) {
            int s = temp % 10;
            if (s % 2 == 0) r = s;
            temp /= 10;
        }
        return r;
    }

    bool containsDigit(int num, int digit) {
        if (num == 0) return num == digit;
        int temp = num;
        while (temp != 0) {
            int s = temp % 10;
            if (s == digit) return true;
            temp /= 10;
        }
        return false;
    }
}