PROGRAM vec_mat_multi_serial
  IMPLICIT NONE
  
  REAL(kind=8) :: t_start, t_end
  REAL(kind=8) :: temp
  INTEGER :: i, j
  INTEGER, PARAMETER :: len_vec=10000
  
  REAL(kind=8), ALLOCATABLE :: in_vector(:)
  REAL(kind=8), ALLOCATABLE :: out_vector(:)
  REAL(kind=8), ALLOCATABLE :: array(:,:)
  REAL(kind=8), ALLOCATABLE :: test_vec(:)
  
  CALL cpu_time(t_start)

  ! Allocate space for vector and array
  ALLOCATE(in_vector(len_vec))
  ALLOCATE(out_vector(len_vec))
  ALLOCATE(array(len_vec,len_vec))
  ALLOCATE(test_vec(len_vec))

  ! Initialise vector
  CALL RANDOM_NUMBER(in_vector)
  
  ! Initialise array
  CALL RANDOM_NUMBER(array)
  
  DO i=1,len_vec
     temp=0.0d+0
     DO j=1,len_vec
        temp = temp + in_vector(j)*array(j,i)
     END DO
     out_vector(i)=temp
  END DO

  test_vec = MATMUL(in_vector,array)

  test_vec = ABS(test_vec - out_vector)
  WRITE (*,'(A,3e10.5)') 'Max error: ', MAXVAL(test_vec)
  
  DEALLOCATE(in_vector)
  DEALLOCATE(array)
  DEALLOCATE(out_vector)
  DEALLOCATE(test_vec)
  
  CALL cpu_time(t_end)

  WRITE(*,'(A,f10.5)') "Expended wall clock time = ",t_end-t_start

END PROGRAM vec_mat_multi_serial
