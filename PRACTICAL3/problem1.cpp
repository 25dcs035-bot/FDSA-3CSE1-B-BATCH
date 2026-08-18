#include <iostream>
using namespace std;


void p(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bs(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
    cout << "Bubble Sort:    ";
    p(a, n);
}

void ss(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
        }
        swap(a[i], a[m]);
    }
    cout << "Selection Sort: ";
    p(a, n);
}

void is(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
    cout << "Insertion Sort: ";
    p(a, n);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[n], b[n], c[n];
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = c[i] = a[i]; 
    }

    cout << "\nResults:\n";
    bs(a, n);
    ss(b, n);
    is(c, n);

    return 0;
}