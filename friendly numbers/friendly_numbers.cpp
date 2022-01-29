#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>

#define ll unsigned long long

// function prototypes
double abundancy(ll a); // return abundancy value of input
void help(void); // print keywords
void check(char *key); // check valid keyword
void isfriends(ll a, ll b); // print if two numbers are friendly or not
void between(ll a, ll b); // print every friendly numbers pain between a and b
double fgcd(double a, double b); // return double gcd of 2 numbers. In this case we need to consider double

int main(int argc, char **argv)
{
    if (argc > 4 || argc == 1 || argc == 3)
    {
        // invalid number of elements
        std::cout << "Need 3 arguments(type \"-help\" for more information) !\n";
        return 1;
    }
    else
    {
        // process input for use in program (start)
            char *key = argv[1]; // storing key
            // check intered keyword
            check(key);
            if (!strcmp(key, "-help")){ help(); return 0;} // if key = help, print documentation
            if (argc != 4) { std::cout << "Need 3 arguments(type \"-help\" for more information) !\n"; return 1;} // check number of arguments
            ll a = std::stoi(argv[2]);
            ll b = std::stoi(argv[3]);
        // process input for use in program (end)
        
        // warning to the user about number range
        if (a >= 999999999 || b >= 999999999)
        {
            std::cout << "Your system dont support number greater then " << std::pow(2, sizeof(ll) * 8) << ", so number greater then this value can cause unexpected result\n\n";
        }

        if (!strcmp(key,"-abu"))
        {
            printf("abundancy of %llu = %f\nabundancy of %llu = %f\n", a, abundancy(a),b, abundancy(b));
        }

        else if (!strcmp(key, "-isfriend"))
        {
            isfriends(a, b);
        }

        else if (!strcmp(key, "-between"))
        {
            between(a, b);
        }
        return 0;
    }
}

void check(char *key)
{
    char all_keys[4][30] = {"-help", "-isfriend", "-abu", "-between"};
    for (int i = 0; i <= 3; i ++)
    {
        if (strcmp(key, all_keys[i]) == 0)
        {
            return;
        }
    }
    std::cout << "unknown argument (" << key << "). type \"-help\" for documentation\n";
    exit(0);
}

void help(void)
{
    printf("format => ./fn key value1 value2\n\tkey =\n-help: show documentation.\n-isfriend: find if value1 and value2 friendly numbers or not with abundancy value.\n");
    printf("-abu: show abundancy value of value1 and value2.\n-between: show all the friendly numbers pain from value1 to value2");
}

double abundancy(ll a)
{
    // return abundancy a
    double abu = 0;
    for (ll i = 1, till = (ll)std::sqrt((double)a); i <= till; i ++)
    {
        if (a % i == 0)
        {
            if (a / i != i)
            {
                abu += (double)((double)a / i) / a;
                abu += (double) i / a;
            }
            else
            {
                abu += (double) i / a;
            }
        }
    }
    return abu;
}

void isfriends(ll a, ll b)
{
    double fst = abundancy(a), snd = abundancy(b);
    if (fst == snd)
    {
        printf("%llu and %llu are friendly numbers (abundancy = %f)\n", a, b, fst);
    }
    else
    {
        printf("%llu and %llu are not friendly numbers (abundancy = %f and %f)\n", a, b , fst, snd);
    }
}

double fgcd(double a, double b)
{
    // this code is aquired from geekforgeeks
	if (a < b)
	{
        return fgcd(b, a);
    }
	if (fabs(b) < 0.001)
	{
        return a;
    }
	else
    {
		return (fgcd(b, a - floor(a / b) * b));
    }
}

void between(ll a, ll b)
{
    if (a >= b)
    {
        std::cout << "b should be greater then a\n";
        exit(1);
    }
    
    for (ll j = a; j <= b; j ++)
    {
        // check if a number solitary or not
        if (fgcd(abundancy(j), j) == 1)
        {
            printf("\n%llu is solitary \n\n", j);
        }
        else
        {   
            double pzl1 = abundancy(j); // store abundancy for compare
            bool alone = true;
            printf("%llu", j);
            for (ll i = j + 1; i <= b; i ++)
            {
                double pzl2 = abundancy(i); // store abundancy for compare
                if (pzl1 == pzl2)
                {
                    alone = false; // if abundancy found then j is not alone in this range
                    printf(", %llu", i);
                }
            }
            if (alone)
            {
                // when j is alone in this range
                printf(" has no friendly number in this range !\n");
            }
            else
            {
                printf(" (frindly pair, abundancy = %f)\n\n", pzl1);
            }
        }
    }
}