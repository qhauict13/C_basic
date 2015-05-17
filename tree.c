#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void createtree(FILE *f){
  while (1) {
    int e;
    fscanf(f,"%d",&e);
    if(e == -1) break;

    Node *p = findNode(id,root);
    if(p == NULL){
      p = (node*)malloc(sizeof(node));
      p->value = e;
      p->rights = NULL;
      root = p;
    }
    int sz;
    fscanf(f,"%d",&sz);
    for (int i = 0; i < sz; i++) {
      int v;
      fscanf(f,"%d",&v);
      addChild(v,p);
    }
  }
  fclose(f);
}

int main(int argc, char *argv[])
{
  FILE *file;
  if ((file = fopen("")))
  return 0;
}
