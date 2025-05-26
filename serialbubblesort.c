#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define size
#define SIZE 1000

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // swap arr[j] and arr[j+1]
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

    // Fill array with random values
    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = rand() % 10000;
    }
    clock_t start = clock();
    bubbleSort(arr, SIZE);
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted %d elements in %f seconds using serial Bubble Sort.\n", SIZE, time_taken);

    return 0;
}