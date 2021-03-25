#include<iostream>
#include<algorithm>

long long gcd(long long n, long long m)
{
    long long x = std::max(n, m);
    long long y = std::min(n, m); // x > y
    if(x % y == 0) return y;
    else{
        while(true){
             if(x >= y){
                x = x % y;
                if(y % x == 0) return x;
             }
             else{
                y = y % x;
                if(x % y == 0) return y;
             }
        }
    }
}

int main()
{
    long long n = 1000000000, m = 999999999;
        /*for find lcd, 1st find gcd.
    1st number X 2nd number = gcd X lcd, use this ref for find lcd from gcd*/
    long long greatest= std::__gcd(n, m);
    long long least = (n * m) / greatest;
    std::cout << least;
    return 0;
}

