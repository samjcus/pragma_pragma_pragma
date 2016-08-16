#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <pthread.h>

void *print_msg(void *thread_id)
{
  int th_id;
  th_id = (intptr_t)thread_id;
  printf("Hello, World from thread %d\n", th_id);
  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  int i,rc;
  int nthreads=4;
  pthread_t threads[nthreads];

  // create threads individually
  for(i=0; i<nthreads; i++)
    {
      rc = pthread_create(&threads[i], NULL, print_msg, (void *) (intptr_t) i);
      assert(rc == 0);
    }
  
  printf("There are %d threads\n", nthreads);

  // wait for each thread to complete
  for (i=0; i<nthreads; i++)
    {
      // block until thread i completes
      rc = pthread_join(threads[i], NULL);
      printf("Thread %d has completed\n", i);
      assert(rc == 0);
    }

  pthread_exit(NULL);

  return EXIT_SUCCESS;
}
