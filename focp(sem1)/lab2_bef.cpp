#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int num;

    // Collatz conjecture

    for (i = 1; i <= 100; i++)
    {
        num = i;
        while (num > 1) {
            if (num % 2 == 0)
                num /= 2;
            else
                num = 3 * num + 1;
            printf("%d ", num);
        }
        printf("\n");
    }
    
    // Approximating Pi

    double Pi = (16.0 / 5.0 - 4.0 /239.0);
    bool next_pos = false;

    for (i = 3; i < 100000000; i += 2)
        if (next_pos)
        {
            Pi += (1.0 / i)*(16.0 / pow(5.0, i) - 4.0 / pow(239.0, i));
            next_pos = false;
        } 
        else 
        {
            Pi -= (1.0 / i)*(16.0 / pow(5.0, i) - 4.0 / pow(239.0, i));
            next_pos = true;
        }

    printf("%.16f", Pi);

    return 0;
}