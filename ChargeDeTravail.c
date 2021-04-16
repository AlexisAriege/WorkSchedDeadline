#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include <pthread.h>

void* fonc(void* arg){
int a;
float b=0.5;
float c=50;

for(a=0;a<250000;a++){

  c=c*c*cos(b);
  b=sin(b)*sqrt(b);
  }
}

int main(void)
{
    pthread_t tache1; //déclaration des deux tâches
    pthread_create(&tache1, NULL, fonc, (void*) 1); //création effective de la tâche tache1
    pthread_join(tache1, NULL); //la fonction principale main(void), doit attendre la fin de l'exécution de la tâche tache1
    return 0;
}
