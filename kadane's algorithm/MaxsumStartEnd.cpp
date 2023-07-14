#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> sumstartend(vector<int> v)
{
    int max_sum = INT_MIN, temp_sum = 0, start = 0, end = 0, s = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        temp_sum += v[i];
        if (temp_sum > max_sum)
        {
            max_sum = temp_sum;
            start = s;
            end = i;
        }
        if (temp_sum < 0)
        {
            temp_sum = 0;
            s = i + 1;
        }
    }
    return {max_sum, start, end};
}

int main()
{
    vector<int> v = {-2, -1, 1, 4, 7, -1, 5, 0, 5};
    v = sumstartend(v);
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    return 0;
}