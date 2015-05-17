#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


node *run;
node *wait;


int getMenu(){
  int option;
  printf("\n1.Open a new program\n");
  printf("2.Kill a program\n");
  printf("3.Show running programs\n");
  printf("4.Show waiting programs\n");
  printf("0.Exit\n");
  printf("Your choice: ");  scanf("%d", &option);
  printf("\n");
  return option;
}

int main(int argc, char *argv[]){
  int a = 0 , b = 0;
  for(;;){
    switch(getMenu()){
    case 1: create_prog(&run,&wait);
      break;
    case 2: dequeue_run(&run);
      dequeue(&wait,&a,&b);

      printf("\n");
      if (b == 0) break;
      else {
        if (b + get_memory(&run) <= MAX_MEMORY) {
          enqueue(&run,a,b);
          printf("A waiting program is now running!\n");
        } else {
          enqueue(&wait,a,b);
        }
      }
      break;
    case 3: printQueue(&run);
      break;
    case 4: printQueue(&wait);
      break;
    case 0:
      return 0;
    default: printf("Enter an option!\n");
    }
  }
  return 0;
}
