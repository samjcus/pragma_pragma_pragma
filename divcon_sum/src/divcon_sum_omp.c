#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double sum(const double *a, size_t n)
{
  size_t half = n / 2;
  double res1;
  double res2;

  // edge cases
  if (n == 0) return 0;
  
  if (n == 1) return *a;

  if (n<1000)
    {
      // revert to serial if n too small
      return sum(a,half) + sum(a + half, n - half);
    }
  else
    {
      // parallel recursive case
#pragma omp task shared(res1)
      res1=sum(a,half);
#pragma omp task shared(res2)
      res2=sum(a + half, n - half);
#pragma omp taskwait
      res1 = res1+res2;
      return res1;
    }
}

int main (int argc, char *argv[])
{
  int N,i;
  double *list,res,kgo;
  double t_start,t_end;
  
  N=400000000;
  list=malloc(N*sizeof(double));

  for(i=0;i<N;i++)
    {
      list[i] = (double) i;
    }
  t_start=omp_get_wtime();
#pragma omp parallel
  {
#pragma omp single nowait
    res=sum(list, N);
  }
  t_end=omp_get_wtime();
  kgo=0.5* N*(N-1);
  printf("error=%g\n",res-kgo);
  printf("Took %g s\n",t_end - t_start);
  free(list);

  return EXIT_SUCCESS;
}
