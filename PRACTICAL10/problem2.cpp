#include <iostream>

using namespace std;

struct Node {
    int code;
    Node* next;
};
Node* shelf[10];
void init() {
    for (int i = 0; i < 10; i++) {
        shelf[i] = NULL;
    }
}
void addBook(int code) {
    int key = code % 10; 
    
    Node* newBook = new Node{code, NULL};

    if (shelf[key] == NULL) {
        shelf[key] = newBook;
    } else {
    
        newBook->next = shelf[key];
        shelf[key] = newBook;
    }
    cout << "Book " << code << " added to Shelf " << key << endl;
}

void display() {
    cout << "\n--- Final Library Shelves ---\n";
    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";
        Node* temp = shelf[i];
        if (temp == NULL) {
            cout << "Empty";
        }
        while (temp != NULL) {
            cout << "[" << temp->code << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    init();

    int books[] = {104, 204, 304, 112, 512, 709, 800};
    int n = sizeof(books) / sizeof(books[0]);

    for (int i = 0; i < n; i++) {
        addBook(books[i]);
    }

    display();

    return 0;
}