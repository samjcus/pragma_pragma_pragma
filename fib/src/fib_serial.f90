PROGRAM fib_serial
  IMPLICIT NONE
  INTEGER :: fib
  INTEGER :: N, res
  REAL :: t_start, t_end
  N=44
  CALL cpu_time(t_start)
  res=fib(N)
  CALL cpu_time(t_end)

  WRITE(*,*) "result = ",res
  WRITE(*,*) "Expended wall clock time = ",t_end-t_start
  
END PROGRAM fib_serial
  
RECURSIVE FUNCTION fib(n) RESULT(res)
  IMPLICIT NONE

  INTEGER, INTENT(IN) :: n
  INTEGER :: res

  INTEGER :: x,y
  
  IF (n<2) THEN
     res=n
  ELSE
     x = fib(n-1)
     y = fib(n-2)
     res=x+y
  END IF
END FUNCTION fib
