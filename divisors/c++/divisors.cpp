#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

std::vector<long long> divisors(long long n)
{
    /*divisor function returns a list of divisors of the number. n*/
    std::vector<long long> list_of_divisors;
    long long till{(long long)std::sqrt(n)};
    for(long long i = 1; i <= till; i += 1){
        if(n % i == 0){ // if reminder = 0 then it is a divisor of n
            if(n / i != i){ // if reminder = 0 then both divisor and
                    // quotient is divisor. if x / y = z and x % y == 0,
                    // then both y and z if divisible by x.
                list_of_divisors.push_back(i); // so we are taking both i
                list_of_divisors.push_back(n / i); // and n / i.
            }
            else{ // sometimes i and n/i is a same number.in this case
                    // we have to take one of them.
                list_of_divisors.push_back(i);
            }
        }
    }
    // have to sort cause it will return unsorted result.
    std::sort(list_of_divisors.begin(), list_of_divisors.end());
    return list_of_divisors;
}
int main()
{
    // calling the function + example input + output
    long long t = 
    return 0;
}
