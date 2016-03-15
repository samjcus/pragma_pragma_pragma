#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

int main(int argc, char *argv[])
{
  unsigned long long int i,j,limit;
  bool *primes;
  double start_t,end_t;

  limit=500000000;

  start_t=omp_get_wtime();

  primes = malloc(sizeof(bool)*limit);

#pragma omp parallel shared(primes) private(i,j) firstprivate(limit)
  {
    /* fill boolean array */
#pragma omp for
    for (i=2;i<limit;i++)
      {
	primes[i]=1;
      }
    /* Sieve of Eratosthenes */
#pragma omp for
    for (i=2;i<limit;i++)
      {
	if (primes[i])
	  {
	    for (j=i;i*j<limit;j++)
	      {
		primes[i*j]=0;
	      }
	  }
      }
  }
  
  end_t=omp_get_wtime();
  
  printf("Took %g s\n",end_t - start_t);
  return EXIT_SUCCESS;
}

