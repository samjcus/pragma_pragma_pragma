#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[])
{
  unsigned long long int i, num_points, count;
  double x, y, pi;
  double t_start, t_end;
  unsigned int seed;
  
  num_points=300000000;
  count=0;
  t_start = omp_get_wtime();

#pragma omp parallel default(none) private(x,y,seed) shared(count,num_points)
  {
    seed=omp_get_thread_num();
#pragma omp for reduction(+:count) 
    for(i=0;i<num_points;i++)
      {
	x = (double)rand_r(&seed)/RAND_MAX;
	y = (double)rand_r(&seed)/RAND_MAX;
	if (x*x + y*y <=1)
	  {
	    count++;
	  }
      }
  }
  pi = 4.0*count/num_points;
  
  t_end = omp_get_wtime();
  printf("Value of pi = %g\n",pi);
  printf("Expended wall clock time = %.5f\n", t_end - t_start);

  return EXIT_SUCCESS;
    
}
