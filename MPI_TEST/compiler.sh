#!/bin/bash
#PBS -S /bin/bash
#PBS -d .

module load openmpi

mpicc -o metapopulation_fvco_disp metapopulation_fvco_disp.c -lgsl -lgslcblas -lm

mpiexec -n 6 ./metapopulation_fvco_disp