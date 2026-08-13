#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of Book which you borrowed: ";
    cin >> n;

    int arr[n];

    cout << "Enter Book ID's: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "This books are borrowed more than one time: ";

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    } 

    return 0;
}