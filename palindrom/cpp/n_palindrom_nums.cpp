/*nth palindrom can be found using binet formula*/
#include <iostream>
#include <cmath>
using namespace std;

int binetFormula(int n)
{
    double part1, part2, part3, s5 = sqrt(5);
    part1 = pow(1 + s5, n);
    part2 = pow(1 - s5, n);
    part3 = pow(2, n) * s5;
    return (part1 - part2) / part3;
}

int main()
{
    cout << "Index starts form 0\n";
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << x << "th palindrom number: " << binetFormula(x) << '\n';
    }
    return 0;
}