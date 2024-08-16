/// Write a C program to insert an element in a specific position of an unordered array. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int A[], int n)
{
    int randInt;

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        randInt = rand() % (100 - 50 + 1) + 50;

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

int *insertElement(int A[], int n, int pos, int element)
{
    int *newArr;
    newArr = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        newArr[i] = A[i];
    }

    free(A);

    A = newArr;
    newArr = NULL;

    for (int i = n; i > pos; i--)
    {
        A[i] = A[i - 1];
    }
    A[pos] = element;

    return A;
}

int main()
{
    int n = 10, insertionIndex, newElement;
    int arr[n];
    int *newArr;

    createArray(arr, n);
    printf("The given array: ");
    displayArray(arr, n);

    printf("\nEnter index to insert element: ");
    scanf("%d", &insertionIndex);

    printf("Enter new element: ");
    scanf("%d", &newElement);

    newArr = insertElement(arr, n, insertionIndex, newElement);

    printf("\nThe new array: ");
    displayArray(newArr, n + 1);
}