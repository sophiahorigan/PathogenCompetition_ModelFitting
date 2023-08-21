#!/bin/bash

#SBATCH --job-name=m21_MCMC
#SBATCH --account=pi-gdwyer
#SBATCH --error=error_$A-%a.txt
#SBATCH --array=1-5
#SBATCH --time=02:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --partition=broadwl
#SBATCH --mail-type=ALL
#SBATCH --mail-user=sophia.horigan@gmail.com

module load openmpi

#print the task id
echo "my SLURM_ARRAY_TASK ID: " $SlURM_ARRAY_TASK_ID
#call model
mpiexec -n 1 ./linesearch_mcmc 21 3 -input $SlURM_ARRAY_TASK_ID

# FOR LINESEARCH
# -n 28, ntasks-per-node=28, array=1-11 (total=1540 linesearches)

# FOR MCMC
# -n 1, ntasks-per-node=1, array=1-5 (num chains)
# might need to do the chains 1x1 for some reason! 