// sum.c (OpenMP version)
#include <stdio.h>
#include <omp.h>

#define N 100

int main() {
long long sum = 0;

#pragma omp parallel for reduction(+:sum) num_threads(10)
for (long long i = 1; i <= N; ++i) {
sum += i;
}

printf("Total Sum: %lld\n", sum);
return 0;
}