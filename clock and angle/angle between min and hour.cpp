#include <iostream>
#include <cmath>

void sortest_angle(double *x)
{//return sortest value of x in 360 scale
    
    *x = (*x > 180) ? (double(360)) - *x : *x;
}

double minimum_angle (double h, double m)
{
// angles of h and m
    h = (h * 30) + (30 * (m / 60));
    m = m * 6;

    // checking if h and m in same side or not
    bool same_side = false; // by default we are considering they are not in same side
    if ((h < 180 && m < 180) || (h > 180 && m > 180) || (h == 180 && m == 180))
    {
        same_side = true;
    }

    // set h and m into their sortest angle
    sortest_angle(&m);
    sortest_angle(&h);
    
    // delete small angle from large angle if they are in same side
    double res; // res = store result
    if (same_side)
    {
        res = std::fabs(h - m);
    }
    // sum the two angles if they are in different sides and convert into sortest angle
    else
    {
        res = h + m;
        sortest_angle(&res);
    }

    return res;
}

int main ()
{
    double h, m;
    std::cout << "Hour = ";
    std::cin >> h;

    std::cout << "Minute = ";
    std::cin >> m;
    
    double minimum = minimum_angle(h, m);
    double maximum = 360 - minimum;
    

    printf("Minimum angle between %f:%f is %f\nMaximum angle between %f:%f is %f", h, m, minimum, h, m, maximum);
    return 0;
}