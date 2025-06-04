#include <iostream>
#include <omp.h>

int main() {
	int thread_num = 0;

  #pragma omp parallel
  {
    #if _OPENMP
    	thread_num = omp_get_thread_num();
    #endif
    std::cout << "Hello World: " << thread_num << std::endl;
  }

  return 0;
}