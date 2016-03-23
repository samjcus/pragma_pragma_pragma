#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

int main(int argc, char *argv[])
{
  unsigned long long int i,j,limit,Nprimes;
  bool *primes;
  double start_t,end_t;

  limit=500000000;
  Nprimes=0;
  start_t=omp_get_wtime();

  primes = malloc(sizeof(bool)*limit);
  primes[0]=0;
  primes[1]=0;
#pragma omp parallel default(none) shared(primes,Nprimes) private(j) firstprivate(limit)
  {
    /* fill boolean array */
#pragma omp for schedule(static)
    for (i=2;i<limit;i++)
      {
	primes[i]=1;
      }
    /* Sieve of Eratosthenes */
#pragma omp for schedule(static)
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
#pragma omp for reduction(+:Nprimes) schedule(static)
    for(i=2;i<limit;i++)
      {
	if (primes[i]) Nprimes++;
      }
  }
  
  end_t=omp_get_wtime();
  printf("Nprimes = %llu\n",Nprimes);
  printf("Took %g s\n",end_t - start_t);
  return EXIT_SUCCESS;
}

