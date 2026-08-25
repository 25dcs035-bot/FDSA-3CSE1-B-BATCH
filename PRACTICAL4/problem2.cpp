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



void display(Node* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    display(head->next);
}
void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
   
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position";
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}

void Traverse(Node* head) {
    if (head == NULL)
        return;

    Traverse(head->next);
    cout << head->data << " ";
}

void Forward(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
 
int main() {
    Node* head = NULL;

    int value[] = {10,20,30,40};
    int n = 4;

    for (int i = 0; i < n; i++) {
        insertEnd(head, value[i]);
    }

    cout << "Hospital Patient Queue\n";
    cout << "----------------------\n";

    cout << "Initial patient queue:\n";
    display(head);


    cout<<"\n\nPatient with token 30 is leaving.\n";
    cout<<"Removing token 30 from the queue.\n";
    cout<<"\nupdated Queue:\n";
    deleteAtPosition(head,3);
    display(head);
    
    cout<<"\n\nReverse queue:\n";
    Traverse(head);

    cout<<"\n\nForward Queue:\n";
    
     Forward(head);

    return 0;
}