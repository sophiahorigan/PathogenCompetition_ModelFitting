#!/bin/sh
#PBS -N test
#PBS -S /bin/sh
#PBS -d .
#PBS -V
#SBATCH --mail-type=ALL
#SBATCH --mail-user=shorigan@uchicago.edu


for (( i=0; i<$1;i++)); do
	echo `sbatch job_line_search.sbatch`	
done
