#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int stt;
	char mssv[10];
	char name[20];
	char tel[11];
	int grade;	
} student;

int readFile(FILE *fin, FILE *fout);
void readBinary(FILE *fi, int n);

int main(int argc, char *argv[]){
	FILE *file1, *file2;
	if (argc != 1) printf("insufficient arguments!\n");
	else if ((file1 = fopen("bd.txt","r")) == NULL) printf("Error!\n");
	else if ((file2 = fopen("grade.dat","w+b")) == NULL) printf("Error!\n");
	else {
		int n = readFile(file1,file2);
		readBinary(file2, n);
	}
	fclose(file1); fclose(file2);
	return 0;
}

void readBinary(FILE *fin, int n){
	student *array;
	int i = 0;
	char buff[MAX]; 
	fseek(fin,0,SEEK_SET);
	array = (student*)malloc(n*sizeof(student));
	fread(array,sizeof(student),n,fin);

	for(i = 0; i < n; i++){
		printf("%d - ",array[i].stt);
		printf("%s - ",array[i].mssv);
		printf("%s - ",array[i].name);
		printf("%s - ",array[i].tel);
		printf("%d\n",array[i].grade);
	}
	free(array);
	rewind(fin);
}

int readFile(FILE *fin, FILE *fout){
	char buff[MAX];
	int i = 0, size = 0;
	student *array;
	while(fgets(buff,MAX,fin) != NULL)
		size++;

	fseek(fin,0,SEEK_SET);
	array = (student*)malloc(size*sizeof(student));
	while(i < size){
		fscanf(fin, "%d %s %s %s %d", &array[i].stt, &array[i].mssv, &array[i].name, &array[i].tel, &array[i].grade);
		i++;
	}
	fwrite(array, sizeof(student), size, fout);
	free(array);
	return size;
}
