#include<iostream>
using namespace std;

class Node{
    public:
   int data;
   Node*next;

 };
  
 void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBeginning(Node*& head, int value){

    Node* newNode = new Node();

    newNode -> data = value;
    newNode -> next = head;
    
    head = newNode;
}

 void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    
    if (temp == NULL) {
        delete newNode;
        cout << "Invalid!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    display(head->next);
}
 
int main() {
    Node* head = NULL;

    int value[] = {10, 20, 30, 40};
    int n = 4;

    for (int i = 0; i < n; i++) {
        insertEnd(head, value[i]);
    }

    cout << "Hospital Patient Queue\n";
    cout << "----------------------\n";

    cout << "\nInitial patient queue:\n";
    display(head);

    cout << "\nCritical patient (Token 5):\n";
    insertBeginning(head, 5);
    display(head);

    cout<<"\nRoutine Patient(Token 15):\n";
    insertEnd(head,15);
    display(head);

    cout<<"\npatient with a priority number(Token 25) inserted at position 2:\n";
    insertAtPosition(head,25,3);
    display(head);
  
    cout<<"\nPatient with a priority number(Token 35) inserted at position 12:\n";
    insertAtPosition(head,35,10);
    

    return 0;
}