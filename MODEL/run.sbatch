#!/bin/bash

#SBATCH --job-name=LS_mcmc
#SBATCH --account=pi-gdwyer
#SBATCH --error=error.txt
#SBATCH --time=36:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --partition=broadwl
#SBATCH --mail-type=ALL
#SBATCH --mail-user=sophia.horigan@gmail.com

module load openmpi

mpiexec -n 1 ./linesearch_mcmc $1 $2