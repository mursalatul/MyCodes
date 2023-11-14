#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull fibonacci(ull n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    ull n;
    cout << "Enter the value of n for Fibonacci sequence(1-40): ";
    cin >> n;
    cout << n << " th" << "Fibonacci number is: " << fibonacci(n - 1) << '\n';
    return 0;
}
