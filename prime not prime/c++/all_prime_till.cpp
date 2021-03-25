#include<vector>
#include<cmath>
#include<iostream>


bool prime(long long n)
{
    if(n < 2 || (n > 2 && n % 2 == 0)){
        return false;
    }
    long long till {std::sqrt(n) + 2};
    for(long long i = 3; i < till; i += 2){
        if( n % i == 0){
            return false;
        }
    }
    return true;
}
/*this function will return a list of prime number between 2 to n.*/
std::vector<long long> all_prime_till(long long n)
{
    std::vector<long long> res;
    if(n < 2){
        return res;
    }
    res.push_back(2);
    for(long long i = 3; i <= n; i += 2){
        if(prime(i) == true){
            res.push_back(i);
        }
    }
    return res;
}

int main()
{

    long long n{1000}; // n = 1000 as input
    std::vector<long long> prime_number_list = all_prime_till(n); // assigning result

    //output sector
    for(long long i = 0; i < prime_number_list.size(); i ++){
        std::cout << prime_number_list[i] << ", ";
    }
    return 0;
}

