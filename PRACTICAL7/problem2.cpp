#include<iostream>
#include<string>
using namespace std;
struct Node {
    string name;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void arrive(string name) {
    Node* newNode = new Node{name, NULL};
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << name << " arrived | Front Patient: " << front->name << endl;
}
void attend() {
    if (front == NULL) {
        cout << "Error: empty! No patient waiting ." << endl;
        return;
    }

    Node* temp = front;
    string attended = temp->name;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
if (front == NULL) {
        cout << "Attended: " << attended << " | Current Front: None (Ward Empty)" << endl;
    } else {
        cout << "Attended: " << attended << " | Current Front: " << front->name << endl;
    }
}
int main() {
    arrive("Patient A");
    arrive("Patient B");
    arrive("Patient C");

    attend();
    attend();
    attend();
    attend();

    return 0;
}