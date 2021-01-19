// Copyright 2021 Tyulin Igor
#include "MyStack.h"
#include "postfix.h"
using namespace std;
int stprior(char x) {
    switch (x) {
        case '(' :
            return 1;
        case ')':
            return -1;
        case '+':
            return 2;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 3;
        default:
            return 0;
    }
}
string infix2postfix(std::string infix) {
    string linow;
    MyStack<char> stek(200);
    int score;
    for (int i = 0; i < infix.length(); i++) {
        score = stprior(infix[i]);
        if (score == 1)
            stek.push(infix[i]);
        if (score == -1) {
            while (stprior(stek.get()) != 1) {
                linow += ' ';
                linow += stek.get();
                stek.pop();
            }
            stek.pop();
        }
        if (score == 0)
            linow += infix[i];
        if (score > 1) {
            while (!stek.isEmpty() && !stek.isFull()) {
                if (stprior(stek.get()) >= score) {
                    linow += stek.get();
                    stek.pop();
                } else {
                    break;
                }
            }
            stek.push(infix[i]);
        }
    }
    linow += ' ';
    while (!stek.isEmpty() && !stek.isFull()) {
            linow += stek.get();
            linow += ' ';
            stek.pop();
    }
    for (int i = 0; i < linow.length(); i++)
        if (linow[i] == ' ' && linow[i + 1] == ' '){
        for(int j = i; j < linow.length()-1; j++)
        linow[j] = linow[j+1];
        linow[i] = 0;
        }
    return linow;
}

