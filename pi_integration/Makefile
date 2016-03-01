CC = gcc-5
FC = gfortran-5
CFLAGS = -Wall
FFLAGS =
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp

NAME = pi_integration


all: C_serial C_OMP

C_serial: bin/$(NAME)_serial_C.exe

F_serial: bin/$(NAME)_serial_F.exe

C_OMP: bin/$(NAME)_omp_C.exe

F_OMP: bin/$(NAME)_omp_F.exe

bin/$(NAME)_serial_C.exe: src/$(NAME)_serial.c
	$(CC) $^ $(CFLAGS) -o $@

bin/$(NAME)_serial_F.exe: src/$(NAME)_serial.f90
	$(FC) $^ $(FFLAGS) -o $@

bin/$(NAME)_omp_C.exe:  src/$(NAME)_omp.c
	$(CC) $^ $(CFLAGS) $(C_OMP_FLAG) -o $@

bin/$(NAME)_omp_F.exe:  src/$(NAME)_omp.f90
	$(FC) $^ $(FFLAGS) $(F_OMP_FLAG) -o $@

.PHONY: clean
clean:
	rm bin/*.exe
