#include<iostream>
#include<algorithm> // min(), max()

long long gcd(long long n, long long m)
{
    /*finding which number is greater among n and m.
    this step is needed cause we dont know if user
    gave big number at first argument or last argument.*/
    long long x = std::max(n, m);
    long long y = std::min(n, m);
    /*if max number is dividable by min then min is the gcd
    in this function all time we will find this*/
    if(x % y == 0) return y;
    else{
        while(true){
            /*replace max number with (max number % min number)
            and check above status.
            if true then new min number is the gcd.
            if not then again replace present max with (max number % min number)*/
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
    int n = 1000000000, m = 999999999;

    std::cout << std::__gcd(n, m);
    return 0;
}
