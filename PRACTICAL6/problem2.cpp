#include <iostream>
#include <string>
using namespace std;
struct Node {
    string page;
    Node* next;
};

Node* top = NULL; 
void visit(string page) {
    Node* newNode = new Node{page, top}; 
    top = newNode;                      
    cout << "Visited: " << top->page << " | Current Page: " << top->page << endl;
}
void back() {
    if (top == NULL) {
        cout << "Error: No history." << endl;
        return;
    }

    Node* temp = top;
    top = top->next; 
    delete temp;     

    if (top == NULL) {
        cout << "Went Back --> Current Page: Blank" << endl;
    } else {
        cout << "Went Back --> Current Page: " << top->page << endl;
    }
}

int main() {
    visit("google");
    visit("github");
    visit("linkedin");

    back(); 
    back();

    visit("youtube"); 
    back();
    back();
    return 0;
}
