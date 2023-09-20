#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// the equation
double f(double x)
{
   // return (x * x) - 3;
    // return (2 * (x * x * x)) - (2 * x) - 5;
	return (x*x*x) - x - 1;
}

void getPoint(double &a, double &b)
{
    a = 0, b = 1;
    while (f(a) * f(b) >= 0)
    {
        a++;
        b++;
    }
}

// show data
void show(double &a, double &b, double &c)
{
    // a, f(a), b, f(b), c, f(c), update
    printf("%10lf %10lf %10lf %10lf %10lf %10lf\t", a, f(a), b, f(b), c, f(c));
}

// checkif the first 6 digits after decimal point is zero or not of f(c).
// f(c) must be positive
bool first6digit0(double fc)
{
    if (fc < 0)
        return false;
    return fc <= 1e-6;
}

int main()
{
    // finding point a, b
    double a, b, c;
    getPoint(a, b);

    // taking accuracy
    cout << "Accuracy (give -1 if no accuracy need): ";
    double accuracy = -1;
    cin >> accuracy;

    // taking maximum term
    double maximum_term = -1;
    if (accuracy == -1)
    {
        cout << "As accuracy is not set, give maximum number of term: ";
        cin >> maximum_term;
    }

    // checking if accuracy or term is given or not
    if (accuracy == -1 && maximum_term == -1)
    {
        cout << "Both accuracy and maximum term is not given. It can generate an infinite series of operations. \nPlease provide one of them.\n";
    }
    // if given
    else
    {
        bool exect_root_found = false;
        // if term given
        printf("No\t  a          f(a)       b          f(b)       c          f(c)           Update\n");
        if (maximum_term != -1)
            for (int i = 1; i <= maximum_term; i++)
            {
                // calculating c
                c = (a + b) / 2;
                cout << i << '\t';
                show(a, b, c);
                double fc = f(c);
                if (first6digit0(fc))
                {
                    cout << "[Found 0, no update]\n";
                    exect_root_found = true;
                    break;
                }
                else if (fc < 0)
                {
                    a = c;
                    cout << "a = c\n";
                }
                else //if (fc > 0)
                {
                    b = c;
                    cout << "b = c\n";
                }
            }
        else
        {
            int i = 1;
            // accuracy is given
            while (true)
            {
                // calculating c
                c = (a + b) / 2;
                cout << i++ << '\t';
                show(a, b, c);
                double fc = f(c);
                if (fc < 0)
                {
                    a = c;
                    cout << "a = c\n";
                }
                else if (fc > 0)
                {
                    b = c;
                    cout << "b = c\n";
                }
                if (fabs(fc) <= accuracy || first6digit0(fc))
                {
                    if (first6digit0(fc))
                        exect_root_found = true;
                    break;
                }
            }
        }
        if (exect_root_found)
        {
            cout << "Root of the equation is: ";
        }
        else
        {
            cout << "Approximate root of the equation is: ";
        }
        printf("%lf\n", c);
    }
    return 0;
}
