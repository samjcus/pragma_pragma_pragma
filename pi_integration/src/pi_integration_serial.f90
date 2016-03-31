PROGRAM pi_integration_serial
  IMPLICIT NONE
  INTEGER :: i
  REAL(kind=8) :: x, sum, step, pi
  REAL(kind=8) :: t_start, t_end

  INTEGER(kind=8), PARAMETER :: num_steps = 500000000

  sum=0.0
  step = 1.0/num_steps

  CALL cpu_time(t_start)

  DO i=0,num_steps
     x = (i+0.5)*step
     sum = sum + 4.0/(1.0+x*x)
  END DO

  pi = step * sum
  
  CALL cpu_time(t_end)

  WRITE(*,*) "Value of pi = ",pi
  WRITE(*,*) "Expended wall clock time = ",t_end-t_start
  
END PROGRAM pi_integration_serial
