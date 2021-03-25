#include<iostream>
#include<vector>
#include<algorithm>
std::vector<long long> all_indexs(long long num, std::vector<long long> arr);

int main()
{
    // input
    std::vector<long long> a {1, 2, 3, 4, 2 , 5, 2, 2, 0};

    //output
    std::vector<long long> s = all_indexs(2, a);
    for(int i = 0; i < s.size(); i ++){
        std::cout << s[i] << " ";
    }
    return 0;
}


/*this function returns a vector of all index of a number*/
std::vector<long long> all_indexs(long long num, std::vector<long long> arr)
{
    long long ind1 = 0;
    std::vector<long long> res;
    long long cc = std::count(arr.begin(), arr.end(), num);
    for(int j = 0; j < cc; j += 1){
        ind1 = std::find(arr.begin() + ind1, arr.end(), num) - arr.begin();
        res.push_back(ind1);
        ind1 += 1;
    }
    return res;
}
