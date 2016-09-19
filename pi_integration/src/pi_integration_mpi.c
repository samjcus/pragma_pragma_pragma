#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
  int i,num_steps,ThisInitial,ThisSteps;
  int ThisTask,NTask;
  double x, local_sum=0.0, sum, step, pi;
  double t_start, t_end;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&ThisTask);
  MPI_Comm_size(MPI_COMM_WORLD,&NTask);
    
  num_steps=500000000;
  x=0;
  sum = 0.0;
  step = 1.0/(double) num_steps;
  t_start = MPI_Wtime();


  /* how many steps per task- last task picks up the slack */
  ThisSteps=num_steps/NTask;
  ThisInitial=ThisTask*ThisSteps;
  if(ThisTask==NTask-1)
    {
      ThisSteps+=num_steps%NTask;
    }

  for (i=ThisInitial; i < ThisInitial+ThisSteps; i++)
    {
      x = (i+0.5)*step;
      local_sum = local_sum + 4.0/(1.0+x*x);
    }

  MPI_Reduce(&local_sum,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

  t_end = MPI_Wtime();
  if(ThisTask==0)
    {
      pi = step * sum;
      printf("Value of pi = %g\n",pi);
      printf("Expended wall clock time = %.20f\n", t_end - t_start);
    }
  MPI_Finalize();
  return EXIT_SUCCESS;
}
