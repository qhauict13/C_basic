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

void readFile(FILE *fin, FILE *fout);

int main(int argc, char *argv[]){
	FILE *file1, *file2;
	if (argc != 1) printf("insufficient arguments!\n");
	else if ((file1 = fopen("bd.txt","r")) == NULL) printf("Error!\n");
	else if ((file2 = fopen("grade.dat","w+b")) == NULL) printf("Error!\n");
	else {
		readFile(file1,file2);
	}
	fclose(file1); fclose(file2);
	return 0;
}

void readFile(FILE *fin, FILE *fout){
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
	for(i = 0; i < size; i++){
		printf("%d - ",array[i].stt);
		printf("%s - ",array[i].mssv);
		printf("%s - ",array[i].name);
		printf("%s - ",array[i].tel);
		printf("%d\n",array[i].grade);
	}
	fwrite(array, sizeof(student), size, fout);
	free(array);
}
