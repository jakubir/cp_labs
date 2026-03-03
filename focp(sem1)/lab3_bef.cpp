#include <stdio.h>
#include <limits.h>

int main() {
    
    // #define N   3
    
    // int i, tab[10];
    
    // for (i = 0; i < N; i++)
    // {
    //     printf("Enter the number: ");
    //     scanf("%d", &tab[i]);
    // }
    
    // for (i = N-1; i >= 0; i--)
    //     printf("%d ", tab[i]);
        
    // int max = INT_MIN;
    // for (i = 0; i < N; i++)
    //     if (tab[i] > max)
    //         max = tab[i];
    
    // printf("Max: %d", max);
    
    // int tab[26] = {0};
    // int ch;
    // while ((ch = getchar()) != EOF)
    //     if (ch >= 'a' and ch <= 'z')
    //         tab[ch-'a']++;
    //     else if (ch >= 'A' and ch <= 'Z')
    //         tab[ch-'A']++;
            
    // for (int i = 0; i < 26; i++)
    //     printf("%d ", tab[i]);
    
    bool tab[201] = {0};
    for (int i = 2; i < 201; i++)
        tab[i] = 1;

    for (int i = 2; i*i < 200; i++)
    {
        if (tab[i] == 0)
            continue;

        for (int j = i+i; j <= 200; j+=i)
            tab[j] = 0;
    }

}