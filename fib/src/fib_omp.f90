PROGRAM fib_omp
  USE omp_lib
  IMPLICIT NONE
  INTEGER :: fib
  INTEGER :: N, res
  REAL(kind=8) :: t_start, t_end
  N=44
  t_start = omp_get_wtime()
  !$OMP PARALLEL DEFAULT(none) SHARED(N,res)
  !$OMP SINGLE
  res=fib(N)
  !$OMP END SINGLE
  !$OMP END PARALLEL
  t_end = omp_get_wtime()

  WRITE(*,*) "result = ",res
  WRITE(*,*) "Expended wall clock time = ",t_end-t_start
  
END PROGRAM fib_omp
  
RECURSIVE FUNCTION fib(n) RESULT(res)
  IMPLICIT NONE

  INTEGER, INTENT(IN) :: n
  INTEGER :: res

  INTEGER :: x,y
  
  IF (n<2) THEN
     res=n
  ELSE IF (n<20) THEN
     x = fib(n-1)
     y = fib(n-2)
     res=x+y
  ELSE
     !$OMP TASK DEFAULT(none) SHARED(x,n)
     x = fib(n-1)
     !$OMP END TASK
     !$OMP TASK DEFAULT(none) SHARED(y,n)
     y = fib(n-2)
     !$OMP END TASK
     !$OMP TASKWAIT     
     res=x+y
  END IF
END FUNCTION fib
