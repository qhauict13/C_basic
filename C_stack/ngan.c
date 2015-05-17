#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libStackListInt.h"

node *topInt;
node_c *topChar;

int getMenu(){
	int option;
	printf("\n1.Add a number into stack\n");
	printf("2.Print stack\n");
	printf("3.pop a number out of stack\n");
	printf("4.Undo last action\n");
	printf("5.Exit\n");
	printf("Your choice: "); scanf("%d",&option);
	printf("\n");
	return option;
}

void addStack(node** top1, node **top2, int e){
	char str[10];
	strcat(str,"PUSH ");
	strcat(str, (char)e);
	push(&(*top1), e);
	pushChar(&(*top2), str);
}

void removeStack(node **top1, node **top2){
	int popOut;
	char str[10];
	popOut = pop(&(*top1));
	strcat(str, "POP ");
	strcat(str, (char)popOut);
	pushChar(&(*top2), str);
	return popOut;
}

int main(){
	int input;
	int popOut;
	char *e;
	char *part1;
	int convert;
	for(;;){
		switch(getMenu()){
			case 1: printf("Enter an integer: ");
			scanf("%d", &input); 
			addStack(&topInt,&topChar,input);
			printf("pushed %d into stack!\n", input);
			break;

			case 2: printStack(&top1);
			break;

			case 3: popOut = removeStack(&top1);
			printf("popped %d out of stack!\n", popOut);
			break;

			case 4: e = popChar(&top2);
			part1 = strtok(e, " ");
			convert = atoi(e);
			if (!strcmp(part1,"POP")){
				push(&top1,convert);
			} else (!strcmp(part1,"PUSH")){
				convert = pop(&top1);
			}
			break;

			case 5: return 0;
		}
	}
}
