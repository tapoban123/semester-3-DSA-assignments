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
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
}

void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int *insertIntoArray(int A[], int n, int pos, int newValue)
{
    int *newArr;
    newArr = (int *)(malloc((n + 1) * sizeof(int)));

    for (int i = 0; i < n; i++)
    {
        newArr[i] = A[i];
    }

    for (int j = n + 1; j > pos; j--)
    {
        newArr[j] = newArr[j - 1];
    }

    newArr[pos] = newValue;

    free(A);
    A = newArr;
    newArr = NULL;

    return A;
}

int main()
{
    int n = 10, newPos, newValue;
    int arr[n];
    int *newArr;

    createArray(arr, n);
    printf("The given array: ");
    displayArray(arr, n);

    selectionSort(arr, n);
    printf("The given array after sorting: ");
    displayArray(arr, n);

    printf("\nEnter position to insert element: ");
    scanf("%d", &newPos);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    newArr = insertIntoArray(arr, n, newPos, newValue);

    selectionSort(newArr, n + 1);
    printf("The new array: ");
    displayArray(newArr, n + 1);
}