#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define N 100

// Passing data to each thread via structure.
typedef struct 
    {
        long long start;
        long long end;
        long long sum;
    } ThreadData;

// Each thread will run this function.
void *calculate_sum(void *arg) 
{
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;
    for (long long i = data->start; i <= data->end; i++) 
    {
        data->sum += i;
    }
    pthread_exit(0);
}

int main() 
{
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    long long total_sum = 0;
    long long range = N / NUM_THREADS;

// Creating threads and assigning ranges
    for (int i = 0; i < NUM_THREADS; i++) 
    {
        thread_data[i].start = i * range + 1;
        thread_data[i].end = (i + 1) * range;
        pthread_create(&threads[i], NULL, calculate_sum, &thread_data[i]);
    }

// Waiting for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }
printf("Sum of first %d natural numbers using Pthreads is: %lld\n", N, total_sum);
return 0;
}