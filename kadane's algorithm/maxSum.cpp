#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxsum(vector<int> v)
{
    int max_sum = INT_MIN, temp_sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        temp_sum += v[i];
        if (temp_sum > max_sum)
            max_sum = temp_sum;
        if (temp_sum < 0)
            temp_sum = 0;
    }
    return max_sum;
}

int main()
{
    vector<int> v = {-2, -1, 1, 4, 7, -1, 5, 0, 5};
    cout << maxsum(v);
}