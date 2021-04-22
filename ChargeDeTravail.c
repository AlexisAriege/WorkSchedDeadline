#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
//#include <time.h>
//#include <string.h>
#include <linux/sched.h>
#include "linux/sched/types.h"
#include <linux/kernel.h>
#include <linux/types.h>
#include <sys/types.h>




//simulation d'une charge de travail (à modifier vers basicmath qui consomme de la memmoire cache)
void* fonc(void* arg){
int a;
float b=0.5;
float c=50;

for(a=0;a<50000;a++){

  c=c*c*cos(b);
  b=sin(b)*sqrt(b);
  }
  printf("aaa \n");
}

int main(void)
{
    int LeId;
    pthread_t tache1; //déclaration des deux tâches
    //pid_t getpid(void);
    LeId=getpid();
    //int sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags);

    struct sched_attr infoTache = {
            .size = sizeof(infoTache),
            .sched_flags = 0,
            .sched_runtime=125,//x ms
            .sched_deadline=150, // x+delay ms
            .sched_period=150,
            .sched_policy=6,
        };

  //  infoTache.sched_policy=SCHED_DEADLINE;

    //flag   SCHED_FLAG_DL_OVERRUN
    // struct sched_attr {
    //               u32 size;              /* Size of this structure */
    //               u32 sched_policy;      /* Policy (SCHED_*) */
    //               u64 sched_flags;       /* Flags */
    //               s32 sched_nice;        /* Nice value (SCHED_OTHER,
    //                                         SCHED_BATCH) */
    //               u32 sched_priority;    /* Static priority (SCHED_FIFO,
    //                                         SCHED_RR) */
    //               /* Remaining fields are for SCHED_DEADLINE */
    //               u64 sched_runtime;
    //               u64 sched_deadline;
    //               u64 sched_period;
    //           };


    //verif=sched_setattr(LeId,,)



    pthread_create(&tache1, NULL, fonc, (void*) 1); //création effective de la tâche tache1
    pthread_join(tache1, NULL); //la fonction principale main(void), doit attendre la fin de l'exécution de la tâche tache1

    return 0;
}
/*
Utiliser Sched yield pour dire qu'on a termine

*/
