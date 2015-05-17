#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node *next;
};

int main(){
	struct node *root;
	struct node *conductor; // this conductor point to nodes as it go through the list

	root = malloc(sizeof(struct node));
	root->next = 0;
	root->x = 12;
	conductor = root;
	if (conductor != 0){
		while(conductor->next != 0)
			conductor = conductor->next;
	} // done traversing!
	// create a node at the end of the list
	conductor->next = malloc(sizeof(struct node));
	conductor = conductor->next;

	if(conductor == 0) {
		printf("Out of memory!\n");
		return 0;
	}

	//add new momory
	conductor->next = 0;
	conductor->x = 42;

	return 0;
}