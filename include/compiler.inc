CC = gcc
FC = gfortran
MPICC = mpicc
MPIF90 = mpif90
CFLAGS = -Wall
FFLAGS =
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
I_MPI = 
L_MPI = 

ifeq (${HOSTNAME},Samuels-MacBook-Air.local)
CC = gcc-5
FC = gfortran-5
MPICC = /opt/openmpi/bin/mpicc
MPIF90 = /opt/openmpi/bin/mpif90
CFLAGS = -std=c99 -pedantic-errors -Wall
FFLAGS =
C_OMP_FLAG = -fopenmp
F_OMP_FLAG = -fopenmp
I_MPI = -I/opt/openmpi/include
L_MPI = -L/opt/openmpi/lib
endif