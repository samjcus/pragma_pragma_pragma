#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n)
{
  int x,y;

  if(n<2) return n;
  x= fib(n-1);
  y= fib(n-2);
  return x+y;
}

int main (int argc, char *argv[])
{
  int N;
  int res;
  clock_t t_start,t_end;
  
  N=44;

  t_start=clock();
  res=fib(N);
  t_end=clock();
  printf("res=%d\n",res);
  printf("Took %g s\n",(double)(t_end - t_start)/CLOCKS_PER_SEC);

  return EXIT_SUCCESS;
}
