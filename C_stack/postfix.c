#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libStackList.h"

node *top;

double calculate(node **topList, char *argv){
	double result;
	double a = pop(&(*topList));
	double b = pop(&(*topList));

	switch(*argv){
		case '+': result = a + b;
		break;
		case '-': result = b - a;
		break;
		case '*': result = b * a;
		break;
		case '/': result = b / a;
		break;
	}
	return result;
}

void main(int argc, char *argv[]){
	double result;
	int i;
	for (i = 1; i < argc; i++){
	 	if ((strcmp(argv[i],"*") == 0) || (strcmp(argv[i],"+") == 0) || (strcmp(argv[i],"-") == 0) || (strcmp(argv[i],"/") == 0)){
	 		push(&top,calculate(&top, argv[i]));
	 	} else {
	 		result = (double)atof(argv[i]);
	 		push(&top, result);
	 	}
	}
	printStack(&top);
	//freeAll(&top);
}