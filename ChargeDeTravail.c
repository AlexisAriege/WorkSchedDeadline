#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
  int a;
  float b=0.5;
  float c=50;

  for(a=0;a<50000;a++){
    c=c*c*cos(b);
    b=sin(b)*sqrt(b);
  }
  printf("fini");


  return 0;
}
