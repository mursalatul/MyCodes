#include<iostream>


long long bigmod(int a, int p, int m)
{
    if(p == 0) return 1;
    if(p % 2 == 0){
        int half1 = bigmod(a, p / 2, m);
        return ((half1 % m) * (half1 % m)) % m;
    }
    if(p % 2 == 1){
        int half1 = bigmod(a, p -  1, m);
        int half2 = a % m;
        return ((half1 % m) * (half2 % m)) % m;
    }
}

int main()
{
    std::cout << bigmod(2, 100, 7);
    return 0;
}
