#!/bin/bash

#SBATCH --job-name=m12-mcmc
#SBATCH --account=pi-gdwyer
#SBATCH --error=error_$A-%a.txt
#SBATCH --array=1-2
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=20:00:00

module load openmpi

#print the task id
echo "my SLURM_ARRAY_TASK ID: " $SlURM_ARRAY_TASK_ID
# input: MODEL ALGORITHM

# LINESEARCH # ntasks-per-node=28, array=1-20
#mpiexec -n 28 ./linesearch_mcmc 12 1 -input $SlURM_ARRAY_TASK_ID

# MCMC # ntasks-per-node=1, array=1-15 (num chains)
mpiexec -n 1 ./linesearch_mcmc 12 3 -input $SlURM_ARRAY_TASK_ID
