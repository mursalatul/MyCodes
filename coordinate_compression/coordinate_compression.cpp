#include <bits/stdc++.h>
using namespace std;
typedef signed long long int ll;

void convert(vector<ll> &v)
{
    // 
    // """""""""""Coordinate Compression"""""""""""""""""""
    // 
    // size of the vector
    ll n = v.size();

    // copying vector in a temp vector
    vector<ll> temp(v.begin(), v.end());

    // sorting it so that i can find tha indexs
    sort(temp.begin(), temp.end());
    
    unordered_map<ll, ll> ump;
    ll x = 0;
    for (ll i = 0; i < n; i++)
    {
        // if it is already counted then it dont need to count again
        if (ump[temp[i]] > 0) // it is more then 0 only when it is already processed
            continue;
        else
        {
            ump[temp[i]] = x;
            x++; // increasing the count
        }
    }
    // replacing the elements with there indexes
    // here, index = the sequence of the order
    // 1, 3, 2, 5 = 0, 2, 1, 3
    for (ll i = 0; i < n; i++)
        v[i] = ump[v[i]];
}

// print a vector
void printv(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    // seeding the rand function so that every time we get different
    // random number
    srand(time(0));
    vector<ll> v1;
    for (ll i = 0; i < 10; i++)
    {
        // random number x (0 <= x <= 10)
        ll x = rand() % 11;
        v1.push_back(x);
    }

    // copying v1 so that we can further use the orginal vector
    vector<ll> v2(v1.begin(), v1.end());
    printv(v2);  // before process
    convert(v2);
    cout << "\n";
    printv(v2); // after processing
    return 0;
}
