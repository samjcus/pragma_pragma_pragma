#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

typedef double complex dcomplex;

int fft_cooley_tukey(dcomplex *buffer, dcomplex *workspace, const int N, const int step)
{
  int i;
  dcomplex t;
  if (step < N)
    {
      fft_cooley_tukey(workspace,buffer,N, step*2);
      fft_cooley_tukey(workspace+step,buffer+step,N, step*2);

      for(i=0;i<N;i+=2*step)
	{
	  t=cexp(-I * M_PI * i / N) * workspace[i + step];
	  buffer[i/2]     = workspace[i] + t;
	  buffer[(i+N)/2] = workspace[i] - t;
	}
    }
  
  return EXIT_SUCCESS;
}

void print_output(const char *name, const dcomplex buf[], const int N)
{
  int i;
  
  printf("%s = [ (%g,%g)",name,creal(buf[0]),cimag(buf[0]));
  for (i=1; i< N; i++)
    {
      printf(", (%g,%g)",creal(buf[i]),cimag(buf[i]));
    }
  printf("]\n");
  
}

int main (int argc, char *argv[])
{
  int i;
  int N=8;
  dcomplex buf[] = {1,1,1,1,0,0,0,0};
  dcomplex *workspace;
  
  if (N<=2)
    {
      printf("N must be greater than 2\nN = %d\n",N);
      return EXIT_FAILURE;
    }
  if ((N & (~N + 1)) != N)
    {
      printf("N must be a power of 2\nN = %d\n",N);
      return EXIT_FAILURE;
    }

  print_output("before",buf,N);
  workspace = malloc(N*sizeof(dcomplex));
  for (i=0; i< N; i++)
    {
      workspace[i] = buf[i];
    }
  
  fft_cooley_tukey(buf,workspace,N,1);

  print_output("after",buf,N);

  free(workspace);
}
