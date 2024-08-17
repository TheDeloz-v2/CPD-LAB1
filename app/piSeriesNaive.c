#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    double start, end;
    double factor = 1.0;
    double sum = 0.0;
    int n, thread_count;

    if (argc != 3) {
        printf("Usage: %s <n> <thread_count>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    thread_count = atoi(argv[2]);

    start = omp_get_wtime();

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        sum += factor/(2*k+1);
        factor = factor * -1.0;
    }
    double pi_approx = 4.0*sum;

    end = omp_get_wtime();

    printf("PI approximation %.10f\n", pi_approx);
    printf("- Threads: %d\n- N value: %d\n", thread_count, n);
    printf("Execution time: %f s\n", end - start);
    return 0;
}


