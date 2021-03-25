#include<stdio.h>
#define ll long long

int bigmode(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    else if(!p % 2){
        ll half = bigmode(a, p/2, m);
        return ((half%m)*(half%m))% m;
    }
    else{
        ll half1 = bigmode(a, p-1, m);
        ll half2 = a%m;
        return ((half1%m)*(half2%m)) % m;
    }
}

int main()
{
    printf("%d", bigmode(2, 100, 7));
    return 0;
}
