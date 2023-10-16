#include <iostream>
using namespace std;
long long fibonacci(long long N)
{
    if (N < 2)
    {
        return N;
    }

    else
    {
        return fibonacci(N - 1) + fibonacci(N - 2);
    }
}
int main()
{
    long long p;
    cin >> p;
    cout << fibonacci(p) << endl;
}
