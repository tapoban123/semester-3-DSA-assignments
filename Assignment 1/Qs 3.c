/// Write a C program to remove an element from a specified position in an array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int A[], int n)
{
    int randInt;
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        randInt = rand() % (100 - 10 + 1) + 10;
        A[i] = randInt;
    }
}

void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int *removeFromArray(int A[], int n, int pos)
{
    int *newArr, temp;
    newArr = (int *)(malloc((n - 1) * sizeof(int)));

    for (int i = pos; i < n - 1; i++)
    {
        temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
    }

    for (int j = 0; j < n - 1; j++)
    {
        newArr[j] = A[j];
    }

    free(A);
    A = newArr;
    newArr = NULL;

    return A;
}

int main()
{
    int n = 10, deletionPosition;
    int arr[n];
    int *newArr;

    createArray(arr, n);
    printf("The given array: ");
    displayArray(arr, n);

    printf("\nEnter the index to be removed: ");
    scanf("%d", &deletionPosition);

    newArr = removeFromArray(arr, n, deletionPosition);

    printf("The new array: ");
    displayArray(newArr, n - 1);
}