#!/bin/bash

#SBATCH --job-name=m45_ls
#SBATCH --account=pi-gdwyer
#SBATCH --error=error_$A-%a.txt
#SBATCH --array=1-11
#SBATCH --time=36:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=28
#SBATCH --partition=broadwl
#SBATCH --mail-type=ALL
#SBATCH --mail-user=shorigan@rcc.uchicago.edu

module load openmpi

#print the task id
echo "my SLURM_ARRAY_TASK ID: " $SlURM_ARRAY_TASK_ID
#call model

# LINESEARCH # ntasks-per-node=28, array=1-11 (total=1540 linesearches)
mpiexec -n 28 ./linesearch_mcmc 45 1 -input $SlURM_ARRAY_TASK_ID

# MCMC # ntasks-per-node=1, array=1-10 (num chains)
#mpiexec -n 1 ./linesearch_mcmc 21 3 -input $SlURM_ARRAY_TASK_ID
