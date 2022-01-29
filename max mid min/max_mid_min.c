#include<stdio.h>

int main()
{
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == b || b == c || c == a)
    {
        if (a == b && b == c & c == a)
        {
            printf("3 numbers are equal\n");
        }
        else
        {
        if (a == b)
        {
            if (a > c)
            {
                printf("%d and %d are same = max\n%d = min\n", a, b, c);
            }
            else
            {
                printf("%d = max\n%d and %d are same = min\n", c, a, b);
            }
        }
        else if (b == c)
        {
            if (b > a)
            {
                printf("%d and %d are same = max\n%d = min\n", b, c, a);
            }
            else
            {
                printf("%d = max\n%d and %d are same = min\n", a, b, c);
            }
        }
        else if (c == a)
        {
            if (c > b)
            {
                printf("%d and %d are same = max\n%d = min\n", c, a, b);
            }
            else
            {
                printf("%d = max\n%d and %d are same = min\n", b, c, a);
            }
        }
        }
    }
    else if (a > b)
    {
        if (a > c)
        {
            printf("%d = max\n", a);
            if (b > c)
            {
                printf("%d = mid\n%d = min\n", b, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, b);
            }
        }
        else if (a < c)
        {
            printf("%d = max\n", c);
            if (a > b)
            {
                printf("%d = mid\n%d = min\n", a, b);
            }
            else
            {
                printf("%d = mid\n%d = min\n", b, a);
            }
        }
    }
    else if (b > a)
    {
        if (b > c)
        {
            printf("%d = max\n", b);
            if (a > c)
            {
                printf("%d = mid\n%d = min\n", a, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, a);
            }
        }
        else if (b < c)
        {
            printf("%d = max\n", c);
            if (a > b)
            {
                printf("%d = mid\n%d = min\n", a, b);
            }
            else
            {
                printf("%d = mid\n%d = min\n", b, a);
            }
        }
    }
    else if (a > c)
    {
        if (a > b)
        {
            printf("%d = max\n", a);
            if (b > c)
            {
                printf("%d = mid\n%d = min\n", b, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, b);
            }
        }
        else if (a < b)
        {
            printf("%d = max\n", b);
            if (a > c)
            {
                printf("%d = mid\n%d = min\n", a, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, a);
            }
        }
    }
    else if (c > a)
    {
        if (c > b)
        {
            printf("%d = max\n", c);
            if (a > b)
            {
                printf("%d = mid\n%d = min\n", a, b);
            }
            else
            {
                printf("%d = mid\n%d = min\n", b, a);
            }
        }
        else if (c < b)
        {
            printf("%d = max\n", b);
            if (a > c)
            {
                printf("%d = mid\n%d = min\n", a, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, a);
            }
        }
    }
    else if (b > c)
    {
        if (b > a)
        {
            printf("%d = max\n", b);
            if (a > c)
            {
                printf("%d = mid\n%d = min\n", a, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, a);
            }
        }
        else if (b < a)
        {
            printf("%d = max\n", a);
            if (b > c)
            {
                printf("%d = mid\n%d = min\n", b, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, b);
            }
        }
    }
    else if (c > b)
    {
        if (c > a)
        {
            printf("%d = max\n", c);
            if (a > b)
            {
                printf("%d = mid\n%d = min\n", a, b);
            }
            else
            {
                printf("%d = mid\n%d = min\n", b, a);
            }
        }
        else if (c < a)
        {
            printf("%d = max", a);
            if (b > c)
            {
                printf("%d = mid\n%d = min\n", b, c);
            }
            else
            {
                printf("%d = mid\n%d = min\n", c, b);
            }
        }
    }

    return 0;
}
