# pragma_pragma_pragma
Examples of parallel code in multiple languages.
These examples are common in parallel programming tutorials and can be solved in a number of ways.
Each example problem here has been solved using either a shared memory model (OpenMP/multithreading) or message passing model (MPI/mpi4py) with C/fortran/python.

## Setup
Current requirements:
- C and Fortran compilers with OpenMP 3.0
- Python interpreter (tested with 2.7.10)
- MPI implementation (tested with OpenMPI 1.10.2)
- mpi4py

Compiler configs are set in include/compiler.inc

## Code styling
- C: lower case vars, explicit {}
- fortran: free form, lower case vars, upper case intrinsics
- python: PEP8, duh

## Ideas
- Vector-Matix Multiplication
- Matrix Multiplication
- mandlebrot set
- multigrid
- 1D wave equation
- simple heat equation
- pairwise interactions
- ring comm
- ping pong comm
