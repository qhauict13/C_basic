#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  int a = 1;
  int b = 2;
  float c = 3.5;

  node* top = NULL;

  push(&top,(void*)&a);
  push(&top,(void*)&b);

  printf("%d",*(int*)top->value);
  printf("%d",*(int*)top->next->value);
  
  return 0;
}
