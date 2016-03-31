PROGRAM primes_omp
  USE omp_lib
  IMPLICIT NONE
  INTEGER(kind=8) ::  i, Nprimes
  REAL(kind=8) :: start_t, end_t
  LOGICAL, ALLOCATABLE :: primes(:)
  INTEGER, PARAMETER :: limit = 500000000

  start_t = omp_get_wtime()

  ! Initialise 
  ALLOCATE(primes(limit))
  primes=.true.
  primes(1)=.false.
  
  ! Sieve of Eratosthenes
  
  !$OMP PARALLEL DEFAULT(none)    &
  !$OMP SHARED(primes,Nprimes)
  !$OMP DO SCHEDULE(static)
  DO i=2,limit
     IF (primes(i)) THEN
        primes(i*i : limit : i) = .false.
     END IF
  END DO
  !$OMP END DO

  ! Count up number of primes
  Nprimes=0
  !$OMP DO SCHEDULE(static) REDUCTION(+:Nprimes)
  DO i=1,limit
     IF (primes(i)) Nprimes = Nprimes+1
  END DO
  !$OMP END DO
  !$OMP END PARALLEL
  
  end_t = omp_get_wtime()

  WRITE(*,*) "Number of primes = ",Nprimes
  WRITE(*,*) "Expended wall clock time = ",end_t-start_t  
  
END PROGRAM primes_omp
