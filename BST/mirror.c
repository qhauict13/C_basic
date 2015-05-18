#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

void mirror(bnode *root){
  if(root == NULL) return;
  else {
    bnode *temp;
    mirror(root->left);
    mirror(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}
