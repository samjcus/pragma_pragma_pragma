PROGRAM hello_f

  USE omp_lib
  
  IMPLICIT NONE
  
  INTEGER :: th_id
  INTEGER :: nthreads
  !$OMP PARALLEL private(th_id)
  th_id = omp_get_thread_num()
  WRITE (*,'(A,I0)') "Hello, World from thread ", th_id
  !$OMP BARRIER

  IF (th_id == 0) THEN
     nthreads = omp_get_num_threads()
     WRITE (*,'(A,I0,A)') "There are ", nthreads, " threads"
     WRITE (*,'(A,I6)') 'OpenMP Specification: ',openmp_version
  END IF
  !$OMP END PARALLEL
  
END PROGRAM hello_f
