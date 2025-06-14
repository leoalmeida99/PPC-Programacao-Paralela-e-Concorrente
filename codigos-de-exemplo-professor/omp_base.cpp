#include <omp.h>
#include <iostream>

int main()
{
    int iThreads = 5;
    int a[100];

    #pragma omp parallel num_threads(iThreads)
    {
        int iThread = omp_get_thread_num();

        if (iThread == 0) //master
        {
            std::cout << "Executando Thread: " << iThread << std::endl;
            std::cout << omp_get_num_threads() << " threads executando!" << std::endl;
        } 
        else
        {
            std::cout << "Executando Thread: " << iThread << std::endl;
        }

        #pragma omp for 
        {
            for (int i=0; i<100; i++) a[i] = omp_get_thread_num() * i;
        }

        // JOIN

        #pragma omp master
        for (int i=0; i<100; i++) {
            std::cout << "a[" << i << "] = " << a[i] << std::endl;
        }

    }

    //JOIN

    return 0;

}