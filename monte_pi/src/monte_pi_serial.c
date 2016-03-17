#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
  unsigned long long int i, num_points, count;
  double x, y, pi;
  clock_t t_start, t_end;
  
  num_points=300000000;
  count=0;
  t_start = clock();
  srand((unsigned) t_start);
  for(i=0;i<num_points;i++)
    {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      if (x*x + y*y <=1) count++;
    }
  
  pi = 4.0*count/num_points;
  
  t_end = clock();
  printf("Value of pi = %g\n",pi);
  printf("Expended wall clock time = %.5f\n", (double)(t_end - t_start)/CLOCKS_PER_SEC);

  return EXIT_SUCCESS;
    
}
