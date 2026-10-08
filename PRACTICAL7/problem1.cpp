#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front, rear, count, capacity;

public:
    Queue(int n)
    {
        capacity = n;
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token)
    {
        if (count == capacity)
        {
            cout << "Error: Queue is Full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Token " << token << " joined." << endl;
        cout << "Front Token:" << arr[front] << endl;
    }

    void serve()
    {
        if (count == 0)
        {
            cout << "Error: Queue is Empty" << endl;
            return;
        }

        cout << "Token " << arr[front] << " served." << endl;

        front = (front + 1) % capacity;
        count--;

        if (count > 0)
            cout << "Front Token:" << arr[front] << endl;
        else
            cout << "Queue is Empty" << endl;
    }
};

int main()
{
    int capacity, operations;

    cout << "Enter the Queue capacity: ";
    cin >> capacity;

    cout << "Enter the number of operations: ";
    cin >> operations;

    Queue q(capacity);

    for (int i = 1; i <= operations; i++)
    {
        int choice;

        cout << "Enter 1 for join a token or 2 for serve a token: ";
        cin >> choice;

        if (choice == 1)
        {
            int token;
            cout << "Enter token number:";
            cin >> token;

            q.join(token);
        }
        else if (choice == 2)
        {
            q.serve();
        }
        else
        {
            cout << "Invalid operation." << endl;
        }

        cout << endl;
    }

    return 0;
}