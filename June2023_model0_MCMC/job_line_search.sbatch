#!/bin/bash

#SBATCH --job-name=model0_MCMC
#SBATCH --account=pi-gdwyer
#SBATCH --error=error_meta_fvco_disp.txt
#SBATCH --time=36:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=28
#SBATCH --partition=broadwl
#SBATCH --mail-type=ALL
#SBATCH --mail-user=sophia.horigan@gmail.com

module load openmpi

mpiexec -n 28 ./metapopulation_fvco_disp