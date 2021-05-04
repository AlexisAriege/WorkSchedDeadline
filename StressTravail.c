#include<stdio.h>
#include<stdlib.h>

#define N 3145728

typedef struct liste{
int data[N];
struct liste *suivant;
};


int main()
{
  // creation de la Liste
  int i;
  struct liste *Nouveau;
  struct liste *Actuel;
  struct liste *Tete;
  Tete = NULL;
      Nouveau = (struct liste *)malloc(sizeof(struct liste));
      Actuel = (struct liste *)malloc(sizeof(struct liste));
  Nouveau->suivant = Tete;
  Nouveau->data[0]=1;
  Tete = Nouveau;
  Tete->suivant = Actuel;
  Actuel->data[0]=2;
  for (i=1;i<5;i++){
    struct liste *Point;
    Point = (struct liste *)malloc(sizeof(struct liste));
    Actuel->suivant = Point;
    Point->data[0]=i+2;
    Actuel=Point;
  }
  //parcourir la liste
  Actuel = Tete;
  while(Actuel->suivant != NULL){
    printf("valeur %d \n",Actuel->data[0]);
    Actuel=Actuel->suivant;
  }
  printf("-- Boucle la chaine --");
  Actuel->suivant=Tete;
  i=1;
  while(Actuel->suivant != NULL){
    Actuel->data[i%3145727]=i%500000;
    Actuel=Actuel->suivant;
  }
  return 0;
}
