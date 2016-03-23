#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

double sum(const double *a, size_t n)
{
  size_t half;
  // edge cases
  if (n == 0) return 0;
  if (n == 1) return *a;
    
  // recursive case
  half = n / 2;
  return sum(a, half) + sum(a + half, n - half);
}

int main (int argc, char *argv[])
{
  int N,i,ThisN,ThisStart;
  int ThisTask,NTask;
  double *list,Thisres,res,kgo;
  double t_start,t_end;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&ThisTask);
  MPI_Comm_size(MPI_COMM_WORLD,&NTask);

  t_start=MPI_Wtime();
  N=100000000;

  ThisN=N/NTask;
  ThisStart=ThisTask*ThisN;
  if(ThisTask==NTask-1)
    {
      ThisN+=N%NTask;
    }
  
  list=malloc(ThisN*sizeof(double));
  
  for(i=0;i<ThisN;i++)
    {
      list[i] = (double) (i+ThisStart);
    }

  Thisres=sum(list, ThisN);
  MPI_Reduce(&Thisres,&res,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
  t_end=MPI_Wtime();
  kgo=0.5* N*(N-1);
  if(ThisTask==0)
    {
      printf("error=%g\n",res-kgo);
      printf("Took %g s\n",t_end - t_start);
    }
  free(list);

  MPI_Finalize();
  
  return EXIT_SUCCESS;
}
