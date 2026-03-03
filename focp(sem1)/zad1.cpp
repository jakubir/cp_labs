// Example program
#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    // task 1
    for (i = 32; i <= 126; i++)
    {
        char c = i;
        printf("%d\t%c\n", i, c);
    }
    //task 2
    int num = 25;
    bool con = true;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            con = false;
            break;
        }
    }
    if (con)
        printf("Liczba %d jest pierwsza", num);
    else
        printf("Liczba %d nie jest pierwsza", num);
    // task 3
    long long int n;
    long long int num;
    n = 6321289474823LL;
    num = n;
    long long int l;
    bool con = true;
    for (l = 2; l<= sqrt(n); l++)
    {
        if (n % l== 0)
        {
            con = false;
            break;
        }
    }
    if (con)
        printf("Liczba %lld jest pierwsza \n", n);
    else {
        printf("Liczba %lld nie jest pierwsza \n", n);
        printf("1 ");
        l = 2;
        while (n > 1)
        {
            if (n % l == 0) {
                printf("%lld ", l);
                n /= l;
            }
            else 
                l++;
        }
        printf("%lld", num);
    }
    // task 4
    double x = 1000.0;
    double xi;

    while (true) {
        xi = (x + 1000.0 / x) / 2.0;
        if (x - xi < 0.0001)
            break;
        x = xi;
    }

    printf("Approximate square root of 1000: %.4f\n", xi);
    return 0;
    
}
