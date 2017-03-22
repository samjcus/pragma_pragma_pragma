C_serial: bin/$(NAME)_serial_C.exe

F_serial: bin/$(NAME)_serial_F.exe

C_OMP: bin/$(NAME)_omp_C.exe

F_OMP: bin/$(NAME)_omp_F.exe

C_PTHREADS: bin/$(NAME)_pthreads_C.exe

CXX_THREADS: bin/$(NAME)_threads_CXX.exe

C_MPI: bin/$(NAME)_mpi_C.exe

F_MPI: bin/$(NAME)_mpi_F.exe

bin/$(NAME)_serial_C.exe: src/$(NAME)_serial.c
	$(CC) $^ $(CFLAGS) -o $@

bin/$(NAME)_serial_F.exe: src/$(NAME)_serial.f90
	$(FC) $^ $(FFLAGS) -o $@

bin/$(NAME)_omp_C.exe:  src/$(NAME)_omp.c
	$(CC) $^ $(CFLAGS) $(C_OMP_FLAG) -o $@

bin/$(NAME)_omp_F.exe:  src/$(NAME)_omp.f90
	$(FC) $^ $(FFLAGS) $(F_OMP_FLAG) -o $@

bin/$(NAME)_pthreads_C.exe: src/$(NAME)_pthreads.c
	$(CC) $^ $(CFLAGS) $(C_PTHREADS_FLAG) -o $@

bin/$(NAME)_threads_CXX.exe: src/$(NAME)_threads.cpp
	$(CXX) $^ $(CXX_THREADS_FLAGS) -o $@

bin/$(NAME)_mpi_C.exe: src/$(NAME)_mpi.c
	$(MPICC) $^ $(CFLAGS) $(L_MPI) -o $@

bin/$(NAME)_mpi_F.exe: src/$(NAME)_mpi.f90
	$(MPIF90) $^ $(FFLAGS) $(I_MPI) $(L_MPI) -o $@


.PHONY: clean
clean:
	rm bin/*.exe
