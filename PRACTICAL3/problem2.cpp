#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count0 = 0, count1 = 0, count2 = 0;


    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }


    int i = 0;

    while (count0--)
        arr[i++] = 0;


    while (count1--)
        arr[i++] = 1;


    while (count2--)
        arr[i++] = 2;

    cout << "Sorted colour codes: ";

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}