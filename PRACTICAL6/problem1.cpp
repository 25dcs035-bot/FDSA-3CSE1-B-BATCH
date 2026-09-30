#include <iostream>
#include <string>
using namespace std;
int capacity = 3;       
int top = -1;           
string stackArr[100];   

bool isEmpty() {
    return top == -1;
}
bool isFull() {
    return top == capacity - 1;
}
void push(string tray) {
    if (isFull()) {
        cout << "Error: Stack Overflow . cannot place " << tray << endl;
        return;
    }
    top++;
    stackArr[top] = tray;
    cout << "Placed " << tray << " | Current Top: " << stackArr[top] << endl;
}
void pop() {
    if (isEmpty()) {
        cout << "Error: Stack Underflow . no tray to take." << endl;
        return;
    }
    string removed = stackArr[top];
    top--;
    
    if (isEmpty()) {
        cout << "Took " << removed << " | Current Top: None (Empty)" << endl;
    } else {
        cout << "Took " << removed << " | Current Top: " << stackArr[top] << endl;
    }
}

int main() {
    push("Tray 1");
    push("Tray 2");
    push("Tray 3");
    push("Tray 4"); 

    pop();
    pop();
    pop();
    pop(); 
    return 0;
}