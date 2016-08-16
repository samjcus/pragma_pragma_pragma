PROGRAM primes_serial
  IMPLICIT NONE
  INTEGER(kind=8) ::  i, Nprimes
  REAL(kind=8) :: start_t, end_t
  LOGICAL, ALLOCATABLE :: primes(:)
  INTEGER, PARAMETER :: limit = 500000000

  CALL cpu_time(start_t)

  ! Initialise 
  ALLOCATE(primes(limit))
  primes=.true.
  primes(1)=.false.
  
  ! Sieve of Eratosthenes
  DO i=2,limit
     IF (primes(i)) THEN
        primes(i*i : limit : i) = .false.
     END IF
  END DO

  ! Count up number of primes
  Nprimes=0
  DO i=1,limit
     IF (primes(i)) Nprimes = Nprimes+1
  END DO
  CALL cpu_time(end_t)

  WRITE(*,*) "Number of primes = ",Nprimes
  WRITE(*,*) "Expended wall clock time = ",end_t-start_t  
  
END PROGRAM primes_serial
