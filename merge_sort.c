#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[100];


void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
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
    MergeSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

   gettimeofday(&end, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time in nanoseconds
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    double duration_seconds = (double)elapsed_ns / 1e9;

    printf("Time taken to execute in nano seconds: %f\n", duration_seconds);
    return 0;
}