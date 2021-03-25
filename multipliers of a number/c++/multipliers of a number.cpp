#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

/*find multipliers of a number
Algorithm:
Step 1: take input as n.
Step 2: i = 1, j = (int) n^0.5, s = {}.
Step 3: if n%i == 0 and i <= j goto Step 4. Or, goto Step 5.
Step 4: if i != n/i, add i and n/i in s and goto Step 3. Else add only i in s
        and goto Step 3.
Step 5: If length of s > 0 print s.
*/


std::vector<long long> multipliers(long long n)
{
    // this function will return a vector of all the multipliers
    std::vector<long long> mul; // mul will store result. it will be returned
    long long j = (long long) std::sqrt(n); // j = stop point
    for(long long i = 1; i <= j; i += 1){
        if(n % i == 0){
            if(i != n / i){
                mul.push_back(i);
                mul.push_back(n / i);
            }
            else{
                // if  i == n/i then we need one of them cause both are same.
                // other wise we will get multiple same value in list
                mul.push_back(i);
            }
        }
    }
    std::sort(mul.begin(), mul.end()); // after importing all the numbers we need to sort the list
    return mul;
}

int main()
{
    long long n;
    std::cin >> n;
    std::vector<long long> res = multipliers(n); // calling the multipliers function and taking
                                                // its values into res vector
    for(long long i = 0; i < res.size(); i += 1){
        std::cout << res.at(i) << "  ";
    }
    return 0;
}
