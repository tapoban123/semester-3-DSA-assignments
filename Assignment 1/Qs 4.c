/// Write a C program to remove the specified element from an array.

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

void selectionSort(int A[], int n)
{
    int min, temp;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = 1 + i; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

int binarySearch(int A[], int n, int key)
{
    int start, end, mid;

    selectionSort(A, n);

    start = 0;
    end = n;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key > A[mid])
        {
            start = mid + 1;
        }
        else if (key < A[mid])
        {
            end = mid - 1;
        }
    }

    return -1;
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

int *deletionController(int A[], int n, int key)
{
    int foundKey, *newArr;

    foundKey = binarySearch(A, n, key);
    if (foundKey == -1)
    {
        newArr = NULL;
        return newArr;
    }
    else
    {
        newArr = removeFromArray(A, n, foundKey);
        return newArr;
    }
}

int main()
{
    int n = 10, deleteValue, *hasDeletedValue;
    int arr[n];

    createArray(arr, n);
    printf("The given array: ");
    displayArray(arr, n);

    printf("\nEnter the value you want to remove: ");
    scanf("%d", &deleteValue);

    hasDeletedValue = deletionController(arr, n, deleteValue);
    if (hasDeletedValue == NULL)
    {
        printf("Wrong input! The input value does not exist.");
    }
    else
    {
        printf("The new array: ");
        displayArray(hasDeletedValue, n - 1);
    }
}