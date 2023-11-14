#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull fact(ull n)
{
    if (n <= 1)
        return n;
    else
        return n * fact(n - 1);
}

int main()
{
    // taking targetted number
    ull n;
    cout << "Enter a value for factorial(0-20): ";
    cin >> n;
    // calculating the factorial
    ull factorial = fact(n);
    // printing the result
    cout << "Factorial of " << n << " is " << factorial << '\n';
    return 0;
}