#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100
#define BLOCK 100

typedef struct {
	int size;
	char author[30];
	char date[12];
} header;

int fsize(FILE *file);
void binaryCopy(FILE *fin, FILE *fout);
void makeHeader(FILE *file);
void readHeader(FILE *file);

int main(int argc, char *argv[]){
	FILE *file;
	if(argc != 3) printf("Insufficient arguments!\n");
	else if ((file = fopen(argv[2],"r+b")) == NULL) printf("Error!\n");
	else {
		switch(argv[1][1]){
			case 'm':makeHeader(file);	fclose(file); break;
			case 'r':readHeader(file); 	fclose(file); break;
			default :printf("format: ./header <option> <file>\n");
					printf("option: m for make header; r for read header\n"); fclose(file); break;
		}
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
void binaryCopy(FILE *fin, FILE *fout){
	int cur = ftell(fin);
	while(!feof(fin)){
		char *buff;
		buff = (char*)malloc(BLOCK*sizeof(char));
		int n = fread(buff,sizeof(char),BLOCK,fin);
		fwrite(buff,sizeof(char),n,fout);
		free(buff);
	}
	fseek(fin,cur,SEEK_SET);
}

void makeHeader(FILE *file){
	char headerStart[] = "---FileHeader---";
	FILE *ftemp;
	header *fheader;
	fheader = (header*)malloc(sizeof(header));
	ftemp = tmpfile();
	binaryCopy(file, ftemp);

	//compute date time
	time_t current_time;
	char *time_string;
	current_time = time(NULL);
	if (current_time == ((time_t) -1)) printf("Failed to compute time!\n");
	time_string = ctime(&current_time);
	if (time_string == NULL) printf("Failed to convert time!\n");
	strcpy(fheader->date, time_string);
	rewind(ftemp);

	fheader->size = fsize(file);

	printf("Enter author's name: "); scanf("%[^\n]",fheader->author);
	fwrite(headerStart,sizeof(char),sizeof(headerStart),file);
	fwrite(fheader,sizeof(header),1,file);

	binaryCopy(ftemp,file);
	free(fheader);
	fclose(ftemp);
}

void readHeader(FILE *file){
	char headerStart[] = "---FileHeader---";
	char buff[25];
	header *fheader;
	fheader = (header*)malloc(sizeof(header));
	fread(buff,sizeof(char),sizeof(headerStart),file);
	if (!strcmp(buff,headerStart)){
		fread(fheader,sizeof(header),1,file);
		printf("Size of file: %d bytes\n",fheader->size);
		printf("Author: %s\n",fheader->author);
		printf("Date: %s\n",fheader->date);
	} else {
		printf("File doesn't have header!\n");
	}
	free(fheader);
}