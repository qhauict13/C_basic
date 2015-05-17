#include <stdio.h>
#include <stdlib.h>
#define	MAX 100
#define BLOCK 50
typedef struct {
	char name[20];
	char tel[20];
} phone;

int fsize(FILE *file){
	int size = 0;
	int cur = ftell(file);
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, cur, SEEK_SET);
	return size;
}

int getNum(FILE *file){
	int n = 0;
	n = fsize(file)/sizeof(phone);
	return n;
}
void phoneRead(FILE *file){
	int n = getNum(file);
	int i = 0;
	phone *array;	
	array = (phone*)malloc(n*sizeof(phone));
	fread(array, sizeof(phone),n,file);
	for (i = 0; i < n; i++){
		printf("%s - ", array[i].name);
		printf("%s\n", array[i].tel);
	}
	free(array);
}

int main(int argc, char *argv[]){
	FILE *file1, *file2;
	if ((file1 = fopen(argv[1],"rb")) == NULL) printf("Error opening %s!\n", argv[1]);
	else {
		phoneRead(file1);
		fclose(file1);
	}
	return 0;
}