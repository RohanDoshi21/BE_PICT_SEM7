#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void recursive(int n)
{
    for (int i = 0; i < n; ++i)
        cout << fibonacci(i) << " ";
}

void iterative(int n)
{
    int a1 = 0;
    int a2 = 1;

    cout << a1 << " " << a2 << " ";

    for (int i = 2; i < n; i++)
    {
        int a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
        cout << a2 << " ";
    }

    cout << endl;
}

int main()
{
    recursive(10);
    cout << endl;
    iterative(10);
    return 0;
}