#include <iostream>
#include <string>
using namespace std;

int iterativeSearch(string plates[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
        {
            return i;  
        }
    }

    return -1;  
}

int recursiveSearch(string plates[], int n, string target, int index)
{

    if (index == n)
    {
        return -1;
    }
    if (plates[index] == target)
    {
        return index;
    }

    return recursiveSearch(plates, n, target, index + 1);
}


int main()
{
    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;


    string plates[n];


    cout << "Enter license plates:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }


    string target;

    cout << "Enter target license plate: ";
    cin >> target;

    int result1 = iterativeSearch(plates, n, target);


    if (result1 != -1)
    {
        cout << "Iterative Search: Plate found at position " << result1 + 1 << endl;
    }
    else
    {
        cout << "Iterative Search: Plate not found" << endl;
    }
    int result2 = recursiveSearch(plates, n, target, 0);


    if (result2 != -1)
    {
        cout << "Recursive Search: Plate found at position "
             << result2 + 1 << endl;
    }
    else
    {
        cout << "Recursive Search: Plate not found" << endl;
    }
 return 0;
}
