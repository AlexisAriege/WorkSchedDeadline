#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<time.h>

static volatile int done;

typedef struct liste{
int *data;
struct liste *suivant;
}liste;

typedef struct donneeThread{
int * ListEtiquette;
int taille;
//...

}donneeThread;




void* fonctionThread(void* arg){
  struct donneeThread* Donnee;
  Donnee = (struct donneeThread*) arg;
  int i;
  struct liste* MaListe;
  MaListe = (struct liste *)malloc(7*sizeof(struct liste));// 7 changeable
  for(i=0;i<7;i++){
    MaListe[i].data = malloc((Donnee->taille)*sizeof(int));
  }
  //while !donne
  struct liste Actuel;
  Actuel=MaListe[0];
  while(done == 0){
  Actuel.data[i%(Donnee->taille)]=i;
  Actuel.suivant =&MaListe[Donnee->ListEtiquette[i%21]];
  Actuel=*(Actuel.suivant);
  i++;
  }
  for(i=0;i<7;i++){
    free(MaListe[i].data);
  }
  free(MaListe);
  return NULL;
}


int main(int argc, char *argv[])
{
  // Le role de ce script est de générer X thread qui vont accéder à des listes chainées aléatoirement pour remplir les caches mémoires d'un cpu.
  int i;
  done=0;
  int Flagtaille=0;
  int Flagthread=0;
  int Flagduree=0;
  for (i=1; i<argc; i++){
      if(strcmp(argv[i],"--help") == 0){
        printf("---------- Option pour le programme de stress ------- \n");
        printf("--taille (-t) pour la taille de la donnée dans la liste (défaut = 3MB) \n");
        printf("--thread (-T) pour le nombre de thread à génerer (défaut = 1)\n");
        printf("--duree (-d) pour le temps à appliquer les threads (défaut = 10s)\n");
        return 0;
      }
      if((strcmp(argv[i],"--taille") == 0) || (strcmp(argv[i],"-t") == 0)){
        Flagtaille=i;
      }
     if((strcmp(argv[i],"--thread") == 0) || (strcmp(argv[i],"-T") == 0)){
        Flagthread=i;
      }
      if((strcmp(argv[i],"--duree") == 0) || (strcmp(argv[i],"-d") == 0)){
         Flagthread=i;
       }
  }
  int taille=3145728; // taille par défaut
  int Nombrethread=1;
  int TempsDeStress=10;
  if(Flagtaille > 0){
    if( sscanf(argv[Flagtaille+1], "%d", &taille) != 1) {
        printf("\n Integer awaited after --taille \n");
        exit(EXIT_FAILURE);
      }
  }
  if(Flagthread > 0){
    if( sscanf(argv[Flagthread+1], "%d", &Nombrethread) != 1) {
        printf("\n Integer awaited after --thread \n");
        exit(EXIT_FAILURE);
      }
  }
  if(Flagduree > 0){
    if( sscanf(argv[Flagduree+1], "%d", &TempsDeStress) != 1) {
        printf("\n Integer awaited after --duree \n");
        exit(EXIT_FAILURE);
      }
  }

  pthread_t* tabThread;
  tabThread = malloc(Nombrethread*sizeof(pthread_t));
  int j;
  srand(time(NULL));
  struct donneeThread *TabDeDonnee;
  TabDeDonnee = (struct donneeThread *)malloc(Nombrethread*sizeof(struct donneeThread));
  for(i = 0; i < Nombrethread; i++){
        TabDeDonnee[i].ListEtiquette = malloc(7*3* sizeof(int));
        TabDeDonnee[i].taille=taille;
        for(j=0;j<21;j++){
          TabDeDonnee[i].ListEtiquette[j]=(rand()%7);
        }
  }

  for(i=0;i<Nombrethread;i++){
    pthread_create(&tabThread[i],NULL,fonctionThread,&TabDeDonnee[i]);
  }

  sleep(5);
  done=1;

  for(i=0;i<Nombrethread;i++){

     pthread_join (tabThread[i], NULL);
  }

//---- Affiche les étiquettes aleatoires
/*
  for(i = 0; i < Nombrethread; i++){
        for(j=0;j<21;j++){
        printf("valeur %d %d sont %d \n",i,j,TabDeDonnee[i].ListEtiquette[j]);
        }
  }
*/

/*
for(i = 0; i < Nombrethread; i++){//creation des threads

}
*/

  //  pthread_create(&(Tab[i]),NULL,fonction,structure);
  /*
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
  */
  for(i = 0; i < Nombrethread; i++){
      free(TabDeDonnee[i].ListEtiquette);
  }
  free(TabDeDonnee);
  free(tabThread);
  return 0;
}
