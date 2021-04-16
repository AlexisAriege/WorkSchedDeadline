#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <pthread.h>


int main(){
  int a;
  float b=0.5;
  float c=50;

  for(a=0;a<250000;a++){
    c=b*b*cos(b);
    b=sin(b)*sqrt(b);
    c=a;
  }
  printf("fini %d ca",a);


  return 0;
}
