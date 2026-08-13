#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    string items[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    h = h % n;  

    cout << "Final display order: ";

    for (int i = 0; i < n; i++)
    {
        cout << items[(i + h) % n] << " ";
    }

    return 0;
}
