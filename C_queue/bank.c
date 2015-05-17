#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

node *line1;
node *line2;

int getMenu(){
  int option;
  printf("\n1.Enter current time and coming customers\n");
  printf("2.Print status\n");
  printf("0.Exit\n");
  printf("Your option: "); scanf("%d", &option);
  printf("\n");
  return option;
}

int main(int argc, char *argv[]){
  int count = 0;
  for(;;){
    switch(getMenu()){
    case 1: process(&line1,&line2,&count);
      break;

    case 2: print_status(&line1,&line2);
      break;

    case 0: return 0;

    default: printf("Enter an option!\n");
      break;
    }
  }
  return 0;
}
