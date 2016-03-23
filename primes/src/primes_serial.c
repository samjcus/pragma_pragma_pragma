#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char *argv[])
{
  unsigned long long int i,j,limit,Nprimes;
  bool *primes;
  time_t start_t,end_t;

  limit=500000000;

  start_t=clock();

  primes = malloc(sizeof(bool)*limit);

  /* fill boolean array */
  for (i=2;i<limit;i++)
    {
      primes[i]=1;
    }
  primes[0]=0;
  primes[1]=0;
  /* Sieve of Eratosthenes */
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

  Nprimes=0;
  for(i=0;i<limit;i++)
    {
      if (primes[i]) Nprimes++;
    }
  
  end_t=clock();
  printf("Nprimes = %llu\n",Nprimes);
  printf("Took %g s\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
  return EXIT_SUCCESS;
}

