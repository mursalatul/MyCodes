#include <iostream>
#include <algorithm> // min(), max()
using namespace std;

long long Pgcd(long long n, long long m)
{
    // 0 is dividable by any number. so other number is the gcd(0 or non zero)
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    /*if max number is dividable by min then min is the gcd
    in this function all time we will find this*/
    if (max(n, m) % min(n, m) == 0)
        return min(n, m);
    while (true)
    {
        /*replace max number with (max number % min number)
        and check above status.
        if true then new min number is the gcd.
        if not then again replace present max with (max number % min number)*/
        if (n >= m)
        {
            n = n % m;
            if (m % n == 0)
                return n;
        }
        else
        {
            m = m % n;
            if (n % m == 0)
                return m;
        }
    }
}

int main()
{
    int n = 1296878609, m = 119789098;
    cout << Pgcd(n, m);
    return 0;
}
