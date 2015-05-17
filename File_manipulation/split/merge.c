#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define BLOCK 50

typedef struct {
	char name[20];
	char tel[20];
} phone;


void merge(FILE *f1, FILE *f2, FILE *file);
void binaryCopy(FILE *fin, FILE *fout);
int fsize(FILE *file);
int main(int argc, char *argv[]){
	FILE *file,*f1,*f2;
	printf("\n");
	if (argc != 1) printf("Argument error!\n");
	else if ((file = fopen("phonemerge.dat","w+b")) == NULL) printf("Cannot open %s\n", argv[2]);
	else if ((f1 = fopen("phone1.dat","rb")) == NULL) printf("error!\n");
	else if ((f2 = fopen("phone2.dat","rb")) == NULL) printf("error!\n");
	else {
		merge(f1,f2,file);
	}
	return 0;
}

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

void merge(FILE *f1, FILE *f2, FILE *file){
	int i = 0, j = 0;
	int numf1 = 0, numf2 = 0;

	numf1 = getNum(f1); numf2 = getNum(f2);
	phone *phonearr1; 	
	phone *phonearr2;
	phonearr1 = (phone*)malloc(numf1*sizeof(phone));
	phonearr2 = (phone*)malloc(numf2*sizeof(phone));
	
	fread(phonearr1, sizeof(phone),numf1,f1);
	fread(phonearr2, sizeof(phone),numf2,f2);
	
	fwrite(phonearr1, sizeof(phone),numf1,file);
	fwrite(phonearr2, sizeof(phone),numf2,file);
	free(phonearr1);free(phonearr2);
	fclose(file);
	fclose(f1);
	fclose(f2);
}
