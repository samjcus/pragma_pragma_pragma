#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n)
{
  int x,y;

  if (n<2) return n;
  //if n too small, sequence is too short and task creation dominates
  if (n<20) return fib(n-1)+fib(n-2);
  
#pragma omp task shared(x)
  x= fib(n-1);
#pragma omp task shared(y)
  y= fib(n-2);
#pragma omp taskwait
  return x+y;
}

int main (int argc, char *argv[])
{
  int N,i;
  int res;
  double t_start,t_end;
  
  N=44;

  t_start=omp_get_wtime();
#pragma omp parallel
  {
#pragma omp single nowait
    res=fib(N);
  }
  t_end=omp_get_wtime();
  printf("res=%d\n",res);
  printf("Took %g s\n",t_end - t_start);

  return EXIT_SUCCESS;
}
