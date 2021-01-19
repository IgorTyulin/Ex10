// Copyright 2021 Tyulin Igor
#include <iostream>
#include <string>
#include "postfix.h"
using namespace std;

int main() {
    string ex1 = "2 + 2";
    cout << infix2postfix(ex1) << std::endl;
    string ex2 = "14 + 2 * 10 / (8 * 2)";
    cout << infix2postfix(ex2) << std::endl;
    string ex3 = "16 * 16 * 16 * 16 / 16 * (22 * 2)";
    cout << infix2postfix(ex3) << std::endl;
    return 0;
}

