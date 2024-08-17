#include <stdio.h>
#include <time.h>

int main() {
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    double factor = 1.0;
    double sum = 0.0;
    int n = 1000;

    for (int k = 0; k < n; k++) {
        sum += factor / (2 * k + 1);
        factor = -factor;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    double pi_approx = 4.0 * sum;
    printf("PI aproximation: %.15f\n", pi_approx);
    
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}
