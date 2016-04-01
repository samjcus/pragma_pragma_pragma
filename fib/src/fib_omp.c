#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n)
{
  int x,y;

  if (n<2) return n;
  //if n too small, sequence is too short and task creation dominates
  if (n<20) return fib(n-1)+fib(n-2);
  
#pragma omp task default(none) shared(x,n)
  x= fib(n-1);
#pragma omp task default(none) shared(y,n)
  y= fib(n-2);
#pragma omp taskwait
  return x+y;
}

int main (int argc, char *argv[])
{
  int N;
  int res;
  double t_start,t_end;
  
  N=44;

  t_start=omp_get_wtime();
#pragma omp parallel default(none) shared(res,N)
  {
#pragma omp single 
    res=fib(N);
  }
  t_end=omp_get_wtime();
  printf("res=%d\n",res);
  printf("Took %g s\n",t_end - t_start);

  return EXIT_SUCCESS;
}
