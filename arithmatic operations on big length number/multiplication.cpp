#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void long_mul(vector<int> &num, int n)
{
    // multiply n with num(considering num as a whole number)
    int mul = 0, carry = 0;
    for (vector<int>::reverse_iterator it = num.rbegin(); it != num.rend(); it++)
    {
        mul = *it * n + carry;
        *it = mul % 10;
        carry = mul / 10;
    }
    // lenth of carry can be more then 1. but in a cell we want single digit number
    // thats why we are cutting the carry and inserting it in front of the vector
    // example: num = {2, 3, 7} carry = 12. so num will be {1, 2, 2, 3, 7}
    while (carry)
    {
        num.insert(num.begin(), carry % 10);
        carry /= 10;
    }
}

void print(vector<int> v)
{
    for (int x: v)
    {
        cout << x << "  ";
    }
    cout << "\n";
}

int main()
{
    vector<int> v = {1};
    for (int i = 2; i <= 100; i++)
    {
        long_mul(v, i);
    }
    print(v);
    return 0;
}