CC = gcc
CXX = g++
FC = gfortran
MPICC = mpicc
MPIF90 = mpif90
CFLAGS = -Wall -std=c99 -pedantic-errors -ftrapv
FFLAGS = -Wall -Wextra -Wconversion -std=f2008 -fbounds-check -fbacktrace -ffpe-trap=zero,overflow,underflow
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
C_PTHREADS_FLAG = -pthread
CXX_THREADS_FLAGS = -Wall -pedantic-errors -ftrapv -std=c++11 -pthread
I_MPI = 
L_MPI = 

ifeq (${HOSTNAME},Samuels-MacBook-Air.local)
# if clang is already specified
ifeq (${C_OPT},clang)
CC = clang-omp
CXX = clang-omp++
FC = gfortran-6
MPICC = /Users/samjcus/builds/mpi_clang/bin/mpicc
MPIF90 = /Users/samjcus/builds/mpi_clang/bin/mpif90
CFLAGS = -Weverything -std=c99 -Wconversion -fsanitize=undefined
FFLAGS = -Wall -Wextra -Wconversion -std=f2008 -fbounds-check -fbacktrace -ffpe-trap=zero,overflow,underflow
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
I_MPI = -I/Users/samjcus/builds/mpi_clang/include
L_MPI = -L/Users/samjcus/builds/mpi_clang/lib
endif
# else
ifneq (${C_OPT},clang)
CC = gcc-6
CXX = g++-6
FC = gfortran-6
MPICC = /opt/openmpi/bin/mpicc
MPIF90 = /opt/openmpi/bin/mpif90
CFLAGS = -Wall -std=c99 -pedantic-errors -ftrapv
FFLAGS = -Wall -Wextra -Wconversion -std=f2008 -fbounds-check -fbacktrace -ffpe-trap=zero,overflow,underflow
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
I_MPI = -I/opt/openmpi/include
L_MPI = -L/opt/openmpi/lib
endif



endif