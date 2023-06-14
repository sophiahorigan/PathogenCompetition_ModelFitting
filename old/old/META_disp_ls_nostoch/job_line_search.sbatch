#!/bin/bash

#SBATCH --job-name=long_term_logsiticf
#SBATCH --error=error_meta_fvco_disp.txt
#SBATCH --time=00:30:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --partition=broadwl
module load openmpi

mpiexec ./metapopulation_fvco_disp