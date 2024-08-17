#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    double start, end;
    double sum_even = 0.0, sum_odd = 0.0;
    int n, thread_count;

    if (argc != 3) {
        printf("Usage: %s <n> <thread_count>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    thread_count = atoi(argv[2]);

    start = omp_get_wtime();

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum_even, sum_odd)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_even += 1.0 / (2 * i + 1);
        } else {
            sum_odd += 1.0 / (2 * i + 1);
        }
    }

    end = omp_get_wtime();

    double pi_approx = 4.0 * (sum_even - sum_odd);
    printf("PI approximation: %.15f\n", pi_approx);
    printf("- Threads: %d\n- N value: %d\n", thread_count, n);
    printf("Execution time: %f s\n", end - start);

    return 0;
}
