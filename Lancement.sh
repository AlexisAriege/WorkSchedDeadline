#!/bin/bash

#L'objectif de ce scirpt est de lancer une charge de travail avec l'ordonnancement EDF disponnible sur linux.
# chrt -d -T <runtime> -D <deadline> -P <period> 0 <command> <command options>
echo "gcc -pthread -o Workload Travail.c -lm"
gcc -pthread Travail.c -o exec -lm
echo "------- Lancement du programme -----------"
#sudo perf stat -e syscalls:sys_exit_sched_yield,syscalls:sys_enter_sched_yield ./exec
#sudo strace ./exec
#./Workload
sudo perf record -e syscalls:sys_exit_sched_yield,syscalls:sys_enter_sched_yield ./exec
#stat peut etre utilisé pour voir le nombre de syscalls
#sudo perf script -F event,time
