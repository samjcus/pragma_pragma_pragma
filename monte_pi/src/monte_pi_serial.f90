PROGRAM monte_pi_serial

  IMPLICIT NONE
  
  INTEGER(kind=4) :: i, count
  REAL(kind=8) :: x, y, pi
  REAL(kind=8) :: t_start, t_end
  INTEGER(kind=8), PARAMETER :: num_points = 300000000

  count=0

  CALL cpu_time(t_start)
  CALL random_seed()
  DO i=0,num_points
     CALL random_number(x)
     CALL random_number(y)
     IF (x*x + y*y <= 1)  count = count + 1
  END DO

  pi = 4.0*count/num_points
  
  CALL cpu_time(t_end)

  WRITE(*,*) "Value of pi = ",pi
  WRITE(*,*) "Expended wall clock time = ",t_end-t_start
  
END PROGRAM monte_pi_serial
