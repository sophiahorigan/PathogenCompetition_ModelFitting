#!/bin/sh
#PBS -N test
#PBS -S /bin/sh
#PBS -d .
#PBS -V

for FILE in *.sbatch; do echo "sbatch" $FILE; done
