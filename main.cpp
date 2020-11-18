#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Headers/stack.h"

// std::string readExpFromFile(std::string path) {
//     std::string exp;
//     std::ifstream reader(path);
//     std::getline(reader, exp);
//     reader.close();
//     return exp;
// }

bool isOperator(char chr) {
    return  chr == '[' || chr == ']' ||
            chr == '(' || chr == ')' ||
            chr == '{' || chr == '}' ||
            chr == '+' || chr == '-';
}

bool isSign(char chr) {
    return chr == '+' || chr == '-';
}

bool isOpeningBracket(char chr) {
    return chr == '[' || chr == '{' || chr == '(';
}

bool isClosingBracket(char chr) {
    return chr == ']' || chr == '}' || chr == ')';
}

bool isOperand(char chr) {
    return chr == 'x' || chr == 'y' || chr == 'z';
}

char oppositeBracket(char bracket) {
    char result;
    switch (bracket) {
        case '(': { result = ')'; break; }
        case ')': { result = '('; break; }
        case '[': { result = ']'; break; }
        case ']': { result = '['; break; }
        case '{': { result = '}'; break; }
        case '}': { result = '{'; break; }
    }
    return result;
}

bool isExpression(std::string exp) {
    exp = '(' + exp + ')';
    bool result = true;
    Stack chars;
    char chr;
    for (int i = 0; i < exp.size() && result; i++) {
        chr = exp[i];
        if (isClosingBracket(chr)) {
            if (chars.isEmpty() || chars.top() == oppositeBracket(chr)) { result = false; }
            else while (!chars.isEmpty() && chars.top() != oppositeBracket(chr) && result) {
                char chr1;
                if (!isOperator(chars.top())) { chr1 = chars.pop(); }
                else { result = false; break; }
                if (!chars.isEmpty()) {
                    if (isSign(chars.top())) {
                        chars.pop();
                        if (!isOperand(chars.top())) { result = false; break; }
                    }
                    else if (chars.top() == oppositeBracket(chr)) { chars.pop(); chars.push('x'); break; }
                    else { result = false; break; }
                }
                else { result = false; break; }
            }

        } else if (isOperand(chr) || isOperator(chr)) {
            chars.push(chr);
        } else if (chr != ' ') { result = false; }
    }
    return (chars.size() == 1 && chars.top() == 'x' && result);
}


int main() {
    std::ifstream reader("Resources//input.txt");
    std::string expr;
    while (std::getline(reader, expr)) {
        std::cout << expr << " is an expression: " << (isExpression(expr) ? "true" : "false") << std::endl;
    }
    reader.close();
}