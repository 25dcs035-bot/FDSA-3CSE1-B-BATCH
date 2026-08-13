#include <iostream>
using namespace std;
int iterativeBinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
int recursiveBinarySearch(int arr[], int low, int high, int target)
{

    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target < arr[mid])
    {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
    else
    {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter book codes in sorted order:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter book code to search: ";
    cin >> target;

    int iterativeResult = iterativeBinarySearch(arr, n, target);

    if (iterativeResult != -1)
    {
        cout << "\nIterative Binary Search:\n";
        cout << "Book code found at index: " << iterativeResult << endl;

        cout << "Position: " << iterativeResult + 1 << endl;
    }
    else
    {
        cout << "\nIterative Binary Search:\n";
        cout << "Book code not found." << endl;
    }
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, target);

    if (recursiveResult != -1)
    {
        cout << "\nRecursive Binary Search:\n";
        cout << "Book code found at index: " << recursiveResult << endl;

        cout << "Position: " << recursiveResult + 1 << endl;
    }
    else
    {
        cout << "\nRecursive Binary Search:\n";
        cout << "Book code not found." << endl;
    }

    return 0;
}