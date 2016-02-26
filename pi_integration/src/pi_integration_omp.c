#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[])
{
  int i,num_steps;
  double x, sum, step, pi;
  double t_start, t_end;
  
  num_steps=500000000;


  x=0;
  sum = 0.0;
  step = 1.0/(double) num_steps;
  t_start = omp_get_wtime();
#pragma omp parallel for reduction(+:sum) default(none) private(i,x) firstprivate(step, num_steps)
  //schedule(static)
  for (i=0; i < num_steps; i++)
    {
      x = (i+0.5)*step;
      sum = sum + 4.0/(1.0+x*x);
    }
  
  pi = step * sum;
  t_end = omp_get_wtime();
  printf("Value of pi = %g\n",pi);
  printf("Expended wall clock time = %.20f\n", t_end - t_start);
  printf("num proc = %d\n", omp_get_num_procs());
  return EXIT_SUCCESS;
    
}
