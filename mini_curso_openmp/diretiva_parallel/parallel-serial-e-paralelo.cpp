#include <iostream>
#include <omp.h>

int main() {
    int thread_num = 0;

    omp_set_num_threads(2);

    #pragma omp parallel
    {
        #if _OPENMP
            thread_num = omp_get_thread_num();
        #endif

        printf("Hello World from thread: %d \n", thread_num);
    }

    return 0;
}