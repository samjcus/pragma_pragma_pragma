PROGRAM hello_f
  USE mpi
  IMPLICIT NONE
  INTEGER :: ierr
  INTEGER :: thistask
  INTEGER :: ntask
  
  CALL mpi_init(ierr)
  CALL mpi_comm_rank(MPI_COMM_WORLD, thistask, ierr)
  CALL mpi_comm_size(MPI_COMM_WORLD, ntask, ierr)
  
  WRITE (*,"(A,I0,A,I0)") "Hello, World! from task ", thistask, " of ",ntask 
  
  CALL mpi_finalize(ierr)
END PROGRAM hello_f
