// 1. Use C malloc/free to:
// a) Allocate memory for an array of n integers, where n is a value taken from the user. Initialize the array with random numbers from 0 to 999. Write the array as a memory block to a file. Deallocate memory.
// b) Read the file back and create a singly-linked list with all numbers from the file, where single element type is:
// struct element {
//       int x;
//       element *next;
// };
// c) display all elements from the list.
// d) delete the list (free the memory).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("input a number: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * n);

    if (arr == NULL)
    {
        printf("Memory allocation problem");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    FILE *fp = fopen("numbers.bin", "wb");

    if (!fp)
    {
        printf("File handling error.");
        return 1;
    }

    fwrite(arr, sizeof(int), n, fp);

    fclose(fp);

    fp = fopen("numbers.txt", "rb");

    if (!fp)
    {
        printf("File handling error");
        return 1;
    }

    struct element {
        int x;
        element *next;
    };

    fclose(fp);

    free(arr);
    
    return 0;
}

// -----
// 2. Use C++ new/delete to:
// a) Allocate memory for an array of n integers, where n is a value taken from the user. Initialize the array with random numbers from 0 to 999. Write the array as a memory block to a file. Deallocate memory.
// b) Read the file back and create a singly-linked list with all numbers from the file, where single element type is:
// struct element {
//       int x;
//       element *next;
// };
// c) display all elements from the list.
// d) delete the list (free the memory).
