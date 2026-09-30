#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char stack[100];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char c = stack[top];
    top--;
    return c;
}
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    string infix = "(3 + 4) * 2";
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (ch == ' ') continue;
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += pop();
            }
            if (top != -1) pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix += pop();
    }

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}