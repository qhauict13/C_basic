#include <stdio.h>
#include <stdlib.h>
#include "libStackList.h"
#define MAX 100

node *top1;
node *top2;
node *top;

int main(){
	FILE *file1, *file2;
	int size1 = 0, size2 = 0,i = 0;
	int *array1, *array2;
	int n1,n2,n;
	int odd;
	if ((file1 = fopen("testNum.txt","r")) == NULL) printf("Error opening test file!\n");
	else if((file2 = fopen("testNum1.txt","r")) == NULL) printf("Error opening test file!\n");
	else {
		char buff[MAX];
		while(fgets(buff,MAX,file1) != NULL) size1++;
		rewind(file1);
		while(fgets(buff,MAX,file2) != NULL) size2++;
		rewind(file2);
		array1 = malloc(size1*sizeof(int));
		array2 = malloc(size2*sizeof(int)); 

		for (i = 0; i < size1; i++){
			fscanf(file1, "%d", &array1[i]);
		}
		for(i = 0; i < size2; i++){
			fscanf(file2, "%d",&array2[i]);
		}

		top1 = makeNode(array1[0]);
		top2 = makeNode(array2[0]);
		i = 1;

		while(i < size1) {
			push(&top1,array1[i]);
			i++;
		}
		i = 1;
		while(i < size2) {
			push(&top2,array2[i]);
			i++;
		}

		i = 0;
		printStack(&top1);
		printf("\n");
		printStack(&top2);
		n = 0; n1 = pop(&top1); n2 = pop(&top2);
		n = n1+n2;

		if(n <= 9){
				push(&top,n);
				odd = 0;
			} else if(n > 9){
				n = n-10;
				push(&top,n);
				odd = 1;
		}
		while ((top1 != NULL) && (top2 != NULL)){
			n = 0;
			n1 = pop(&top1);
			n2 = pop(&top2);
			n=n1+n2+odd;
			if(n <= 9){
				push(&top,n);
				odd = 0;
			} else if(n > 9){
				n = n-10;
				push(&top,n);
				odd = 1;
			}
		}
		while (top1 != NULL){
			n=0;
			n1 = pop(&top1);
			n = n1+odd;
			if(n <= 9){
				push(&top,n);
				odd = 0;
			} else if (n > 9){
				n = n-10;
				push(&top,n);
				odd = 1;
			}
		}

		while (top2 != NULL){
			n=0;
			n2 = pop(&top2);
			n = n2+odd;
			if(n <= 9){
				push(&top,n);
				odd = 0;
			} else if (n > 9){
				n = n-10;
				push(&top,n);
				odd = 1;
			}
		}
		printf("\n");
		printStack(&top);
	}
}