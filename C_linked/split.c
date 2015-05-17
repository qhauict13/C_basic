#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct {
	char name[20];
	char tel[20];
} phone;

int main(int argc, char *argv[]){
	FILE *file,*f1,*f2;
	phone *phonearr;
	int n;
	printf("how many contact do you want to split?(<20) :");
	do {
		scanf("%d", &n);
		if (n >= 20) printf("\nplease reinput! :");
	} while (n >= 20);
	phonearr = (*phone)malloc(n*sizeof(phone));
	printf("\n");
	if (argc != 5) printf("Argument error!\n");
	else if ((file = fopen(argv[2],"r+b")) == NULL) printf("Cannot open %s\n", argv[2]);
	else if ((f1 = fopen(argv[3],"w+b")) == NULL) printf("error!\n");
	else if ((f2 = fopen(argv[4],"w+b")) == NULL) printf("error!\n");
	else {
		split(file, n, phonearr,f1,f2);
	}
	return 0;
}

void split(FILE *file, int n, phone phonearr[], FILE *f1, FILE *f2){
	int i = 0, j = 0;
	phone phonearr1[n], phonearr2[MAX-n];
	//read data from file to array
	fread(phonearr,sizeof(phone), MAX, file);	
	printf("Contact list: \n");
	for (i = 0; i < MAX; i++){
		printf("%s - ", phonearr[i].name);
		printf("%s\n", phonearr[i].tel);
	}
	
	for (i = 0; i < n; i++)
		phonearr1[i] = phonearr[i];
	for (int i = MAX - 1; i >= n; i--){
		for(j = 0; j < n; j++)
			phonearr2[j] = phonearr[i];
	}
	fwrite(phonearr1, sizeof(phone),n,f1);
	fwrite(phonearr2, sizeof(phone),n,f2);
	fclose(file);
	fclose(f1);
	fclose(f2);
}