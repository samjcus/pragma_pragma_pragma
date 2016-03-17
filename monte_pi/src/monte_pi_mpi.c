#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
  int ThisTask, NTask;
  unsigned long long int i, num_points, count, Thiscount, ThisPoints, ThisInitial;
  double x, y, pi;
  double t_start, t_end;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&ThisTask);
  MPI_Comm_size(MPI_COMM_WORLD,&NTask);

  t_start = MPI_Wtime();
  num_points=300000000;
  

  ThisPoints=num_points/NTask;
  ThisInitial=ThisTask*ThisPoints;
  if(ThisTask==NTask-1)
    {
      ThisPoints+=num_points%NTask;
    }
  
  Thiscount=0;

  srand((unsigned) t_start);
  for(i=ThisInitial;i<ThisInitial+ThisPoints;i++)
    {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      if (x*x + y*y <=1) Thiscount++;
    }

  MPI_Reduce(&Thiscount,&count,1,MPI_UNSIGNED_LONG_LONG,MPI_SUM,0,MPI_COMM_WORLD);
  
  if(ThisTask==0)
    {
      pi = 4.0*count/num_points;
  
      t_end = MPI_Wtime();
      printf("Value of pi = %g\n",pi);
      printf("Expended wall clock time = %.5f\n", t_end - t_start);
    }
  MPI_Finalize();
  
  return EXIT_SUCCESS;
    
}
