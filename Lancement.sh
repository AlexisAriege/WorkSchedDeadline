#!/bin/bash

#L'objectif de ce scirpt est de lancer une charge de travail avec l'ordonnancement EDF disponnible sur linux.
# chrt -d -T <runtime> -D <deadline> -P <period> 0 <command> <command options>
echo" gcc -o -pthread Workload Travail.c -lm"
gcc -o -pthread Workload Travail.c -lm
echo "------- Lancement du programme -----------"
#./Workload
#sudo perf record -e syscalls:sys_exit_sched_yield,syscalls:sys_enter_sched_yield ./a.out
