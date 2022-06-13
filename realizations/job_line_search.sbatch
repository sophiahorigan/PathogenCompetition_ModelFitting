#!/bin/bash

#SBATCH --job-name=long_term_logsiticf
#SBATCH --error=error_meta_fvco_disp.txt
#SBATCH --time=36:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=28
#SBATCH --partition=broadwl
module load openmpi

mpiexec -n 28 ./metapopulation_fvco_disp