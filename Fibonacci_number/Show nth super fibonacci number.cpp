#include <iostream>
using namespace std;
long long Superfibonacci(long long N)
{
    if (N < 2)
    {
        return N;
    }

    else
    {
        return Superfibonacci(N - 1) + 2 * Superfibonacci(N - 2);
    }
}
int main()
{
    long long p;
    cin >> p;
    cout << Superfibonacci(p) << endl;
}
