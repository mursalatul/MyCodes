#include<iostream>
#include<string>
#include<algorithm>
/* algorithm of this super fast power function:

if our target is 5 ^ 20
20 = 10100
a = 5
n = 20
result = 1
process:
        result = result * result        if binar = 1, result = a * result
1 ->            1 * 1 = 1                       5 * 1 = 5
0 ->            5 * 5 = 25                          x
1 ->            25 * 25 = 625                   5 * 625 = 3125
0 ->            3125 * 3125 = 9765625               x
0 ->            9765625 * 9765625 = 95367431640625
so finally answer will be 95367431640625
*/
long long po(long long a, long long n)
{
    std::string binary = "";
    // this loop will find binary version of n from last to first order
    // so after this loop we need to reverse it.
    while(n > 0){
        if(n % 2 == 0) binary += "0";
        else binary += "1";
        n /= 2;
    }
    std::reverse(binary.begin(), binary.end());
    long long res = 1;
    for(int i = 0; i < binary.size(); i ++){
        res = res * res;
        if(binary[i] == '1') res = a * res;
    }
    return res;
}

int main()
{   
    std::cout << "a, n = ";
    long long a, n;
    std::cin >> a >> n;
    std::cout <<"\nans = "<< po(a, n);
    return 0;
}