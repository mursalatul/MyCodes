#include<cmath>
#include<iostream>

/*here prime function return true if a number is prime and return false if a number is not prime.*/
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

int main()
{
    for(int i = 0; i < 20 ; i ++){
    long long n{0};
    std::cin >> n;
    std::cout << n << " = " << prime(n)<< "\n";
    }
    return 0;
}
