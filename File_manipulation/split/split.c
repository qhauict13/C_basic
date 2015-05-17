#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define BLOCK 50

typedef struct {
	char name[20];
	char tel[20];
} phone;


void split(FILE *file, int n, FILE *f1, FILE *f2);


int main(int argc, char *argv[]){
	FILE *file,*f1,*f2;
	int n = atoi(argv[1]);
	printf("\n");
	if (argc != 2) printf("Argument error!\n");
	else if ((file = fopen("phone.dat","rb")) == NULL) printf("Cannot open %s\n", argv[2]);
	else if ((f1 = fopen("phone1.dat","w+b")) == NULL) printf("error!\n");
	else if ((f2 = fopen("phone2.dat","w+b")) == NULL) printf("error!\n");
	else {
		split(file,n,f1,f2);
	}
	return 0;
}

void split(FILE *file, int n, FILE *f1, FILE *f2){
	int i = 0, j = 0;
	phone phonearr[MAX];
	phone phonearr1[n], phonearr2[MAX-n]; 
	fread(phonearr,sizeof(phone), MAX, file);	
	printf("Contact list: \n");
	for (i = 0; i < MAX; i++){
		printf("%s - ", phonearr[i].name);
		printf("%s\n", phonearr[i].tel);
	}
	
	for (i = 0; i < n; i++)
		phonearr1[i] = phonearr[i];
	for (i = n ; i < MAX; i++){
			phonearr2[j] = phonearr[i];
			j++;
	}
	fwrite(phonearr1, sizeof(phone),n,f1);
	fwrite(phonearr2, sizeof(phone),MAX-n,f2);
	fclose(file);
	fclose(f1);
	fclose(f2);
}
