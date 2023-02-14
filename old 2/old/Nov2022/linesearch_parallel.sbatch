#!/bin/sh

#SBATCH --job-name=vf_fitting
#SBATCH --time=36:00:00
#SBATCH --account=pi-gdwyer
#SBATCH --error=error_meta_fvco.out
#SBATCH --ntasks=28
#SBATCH --partition=broadwl

#load default version of GNU parallel
module load parallel

#increase user process limit
ulimit -u 1000

#allocate a single core to each task
srun="srun --exclusive -N1 -n1"

#delay of 0.2 prevents overloading in controlling node
#j is number of tasks run simultaneously
#joblog and resume create a task log that can be used to monitor progress
parallel="parallel --delay 0.2 -j $SLURM_NTASKS --joblog runtask.log --resume"

#run script using GNU parallel and srun
#final number is total runs
$parallel -n0 "$srun ./metapopulation_fvco_disp > output.{1}" ::: {1..128}