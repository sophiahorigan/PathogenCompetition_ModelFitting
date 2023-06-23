#!/bin/sh
#PBS -N test
#PBS -S /bin/sh
#PBS -d .
#PBS -V

for (( i=0; i<$1;i++)); do
	echo `sbatch run.sbatch`	
done
