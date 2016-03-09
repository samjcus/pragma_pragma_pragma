CC = gcc-5
FC = gfortran-5
MPICC = mpicc
MPIF90 = /usr/local/bin/mpif90
CFLAGS = -Wall
FFLAGS =
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
I_MPI = -I/usr/local/include
L_MPI = -L/usr/local/lib

NAME = hello_world


all: C_serial F_serial C_OMP F_OMP C_MPI F_MPI

C_serial: bin/$(NAME)_serial_C.exe

F_serial: bin/$(NAME)_serial_F.exe

C_OMP: bin/$(NAME)_omp_C.exe

F_OMP: bin/$(NAME)_omp_F.exe

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

bin/$(NAME)_mpi_C.exe: src/$(NAME)_mpi.c
	$(MPICC) $^ $(CFLAGS) $(L_MPI) -o $@

bin/$(NAME)_mpi_F.exe: src/$(NAME)_mpi.f90
	$(MPIF90) $^ $(FFLAGS) $(I_MPI) $(L_MPI) -o $@


.PHONY: clean
clean:
	rm bin/*.exe
