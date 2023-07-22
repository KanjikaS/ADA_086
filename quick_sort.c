#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[100];

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
      struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int n;
    printf("Enter the array size\n");
    scanf("%d", &n);
    printf("Enter the Elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    QuickSort(A, 0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    // end = clock();
    // float duration = ((float)(end - start)) / CLOCKS_PER_SEC;
       long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    double duration_seconds = (double)elapsed_ns / 1e9;
    printf("Time taken to execute in  nano seconds : %f", duration_seconds);
    return 0;
}