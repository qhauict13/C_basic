#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void header(FILE *fin){
	time_t current_time;
	char * time_string;
	long size;
	time_string = ctime(&current_time);

	fseek(fin, 0, SEEK_END);
	size = ftell(fin);
	rewind(fin);
	fputs("Size of file: ",MAX,fin);
	fputs((char)size,MAX,fin);
	fputs("\nAuthor: HauPQ, ICT58; this file is free to copy\n",MAX,fin);
	fputs("Added date time: ",MAX,fin);
	fputs(c_time_string,MAX,fin);
}

int main(int argc, char *argv[]){
	FILE *file;
	if(argc != 2) printf("Insufficient arguments!\n");
	else if ((file = fopen(argv[1],"r")) == NULL) printf("Error!\n");
	else {
		header(file);
	}
	fclose(fin);
	return 0;
}