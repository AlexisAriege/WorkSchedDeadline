#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <unistd.h>
/* Crée un processus fils exécutant un nouveau programme. PROGRAM est le nom
   du programme à exécuter ; le programme est recherché dans le path.
   ARG_LIST est une liste terminée par NULL de chaînes de caractères à passer
   au programme comme liste d'arguments. Renvoie l'identifiant du processus
   nouvellement créé. */
int spawn (char* program, char** arg_list)
{
  pid_t child_pid;
  /* Duplique ce processus. */
  child_pid = fork ();
  if (child_pid != 0)
     /* Nous sommes dans le processus parent. */
     return child_pid;
  else {
     /* Exécute PROGRAM en le recherchant dans le path. */
     execvp (program, arg_list);
     /* On ne sort de la fonction execvp uniquement si une erreur survient. */
     fprintf (stderr, "une erreur est survenue au sein de execvp\n");
     abort ();
  }
}
int main ()
{
  /* Liste d'arguments à passer à la commande "ls". */
  char* arg_list[] = {
    "sudo",
     "./Allocation.sh",     /* argv[0], le nom du programme. */
     NULL      /* La liste d'arguments doit se terminer par NULL.  */
  };
  /* Crée un nouveau processus fils exécutant la commande "ls". Ignore
      l'identifiant du processus fils renvoyé. */
  spawn ("sudo", arg_list);
  printf ("Fin du programme principal\n");
  return 0;
}
