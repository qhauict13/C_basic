#include <stdio.h>
#include <stdlib.h>

char pass[] = "ANSF";

void printPass(int pass[]);
void backtrack(int pass[], int pos);

int main(int argc, char *argv[])
{
  int i = 0;
  int password[4];
  backtrack(password,0);
  return 0;
}

void backtrack(int pass[], int pos){
  int i;

  for (i = 'A'; i <= 'Z'; i++) {
    pass[pos] = i;
    if(pos == 3) printPass(pass);
    else {
      backtrack(pass,pos+1);
    }
  }
}

void printPass(int pass[]){
  int i;
  for (i = 0; i < 4; i++) {
    printf("%c",pass[i]);
 }
  printf("\n");
}

