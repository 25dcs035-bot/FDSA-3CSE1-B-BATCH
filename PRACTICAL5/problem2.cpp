#include <iostream>
using namespace std;

class SinglyNode
{
public:
    string name;
    SinglyNode *next;

    SinglyNode(string n)
    {
        name = n;
        next = NULL;
    }
};
class SinglyCircular
{
    SinglyNode *head;

public:
    SinglyCircular()
    {
        head = NULL;
    }

    void insert(string name, int pos)
    {
        SinglyNode *newNode = new SinglyNode(name);

       
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 1)
        {
            SinglyNode *last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;
            return;
        }

        SinglyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        if (pos == 1)
        {
            SinglyNode *last = head;

            while (last->next != head)
                last = last->next;

            SinglyNode *temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }
SinglyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        if (temp->next == head)
        {
            cout << "Invalid position\n";
            return;
        }

        SinglyNode *del = temp->next;
        temp->next = del->next;

        delete del;
    }
void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        SinglyNode *temp = head;

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};
class DoublyNode
{
public:
    string name;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(string n)
    {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular
{
    DoublyNode *head;

public:
    DoublyCircular()
    {
        head = NULL;
    }

    void insert(string name, int pos)
    {
        DoublyNode *newNode = new DoublyNode(name);

        
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        if (pos == 1)
        {
            DoublyNode *last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        DoublyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        if (pos == 1)
        {
            DoublyNode *last = head->prev;
            DoublyNode *temp = head;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete temp;
            return;
        }

        DoublyNode *temp = head;

        for (int i = 1; i < pos && temp->next != head; i++)
            temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        DoublyNode *temp = head;

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};
int main()
{
    cout << "SINGLY CIRCULAR LINKED LIST\n";

    SinglyCircular s;

    s.insert("p", 1);
    cout << "After p joins: ";
    s.display();

    s.insert("q", 2);
    cout << "After q joins: ";
    s.display();

    s.insert("r", 3);
    cout << "After r joins: ";
    s.display();

    s.insert("s", 4);
    cout << "After s joins: ";
    s.display();

    s.remove(3);
    cout << "After r leaves: ";
    s.display();

    s.insert("t", 2);
    cout << "After t joins at position 2: ";
    s.display();

    cout << "\nDOUBLY CIRCULAR LINKED LIST\n";
     DoublyCircular d;

    d.insert("p", 1);
    cout << "After p joins: ";
    d.display();

    d.insert("q", 2);
    cout << "After q joins: ";
    d.display();

    d.insert("r", 3);
    cout << "After r joins: ";
    d.display();

    d.insert("s", 4);
    cout << "After s joins: ";
    d.display();

    d.remove(3);
    cout << "After r leaves: ";
    d.display();

    d.insert("t", 2);
    cout << "After t joins at position 2: ";
    d.display();

    return 0;
}