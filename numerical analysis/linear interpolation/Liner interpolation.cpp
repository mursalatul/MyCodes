#include <iostream>
#include <cmath>
using namespace std;

// return linear interpolation
double linerInterpolation(double x, double x1, double y1, double x2, double y2)
{
    return y1 + (((x - x1) * (y2 - y1)) / (x2 - x1));
}

int main()
{
    // input section
    double x, y, x1, y1, x2, y2;
    cout << "Enter the following value,\nx = ";
    cin >> x;
    cout << "x1 = ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "x2 = ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;

    // output section
    cout << "Value of y = " << linerInterpolation(x, x1, y1, x2, y2) << '\n';
    return 0;
}