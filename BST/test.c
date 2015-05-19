#include <stdio.h>

typedef struct node_b{
  void *value;
  struct node_b *left, *right;
} bnode;


int main(int argc, char *argv[])
{
  printf("%lu\n",sizeof(char *));
  printf("%lu\n",sizeof(int  *));
  printf("%lu\n",sizeof(float *));
  printf("%lu\n",sizeof(double *));
  printf("%lu\n",sizeof(bnode *));
  return 0;
}
