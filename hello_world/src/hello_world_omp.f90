PROGRAM hello_f

  USE omp_lib
  
  IMPLICIT NONE
  
  INTEGER :: th_id
  INTEGER :: nthreads
  !$OMP PARALLEL private(th_id)
  th_id = omp_get_thread_num()
  WRITE (*,*) "Hello, World from thread", th_id
  !$OMP BARRIER

  IF (th_id == 0) THEN
     nthreads = omp_get_num_threads()
     WRITE (*,*) "There are", nthreads, "threads"
  END IF
  !$OMP END PARALLEL
  
END PROGRAM hello_f
