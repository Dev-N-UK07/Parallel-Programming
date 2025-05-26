#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//Define size
#define SIZE 10000

void parallelBubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int phase = i % 2;
    
        #pragma omp parallel for default(none) shared(arr, n, phase)
        for (int j = phase; j < n - 1; j += 2) 
        {
        if (arr[j] > arr[j + 1]) 
            {
            // swap arr[j] and arr[j + 1]
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{   
    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = rand() % 10000;
    }

    double start = omp_get_wtime();
    parallelBubbleSort(arr, SIZE);

    double end = omp_get_wtime();
    printf("Sorted %d elements in %f seconds using OpenMP parallel Bubble Sort.\n", SIZE, end - start);

    return 0;
}