#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct student_t{
  int stt;
  char mssv[9];
  char name[20];
  char tel[10];
  int grade;
} student;

int fsize(FILE *file);
int get_size(FILE *file);
void swap(student *a, student *b);
void selection_sort(student array[], int n);
void verify(FILE *file1, FILE *file2);
void append(student *a, student *b);
int binary_search(student *a, char *target, int low, int high);
void printArray(student *a);

int main(int argc, char *argv[]){
  FILE *file1, *file2;
  if((file1 = fopen("bd1.txt","r")) == NULL) printf("Cannot open file 1!\n");
  else if((file2 = fopen("bd2.txt","r")) == NULL) printf("Cannot open file 2\n");
  else {
    verify(file1,file2);
  }
  fclose(file1); fclose(file2);
  return 0;
}

void selection_sort(student *array, int n){
  int i = 0,j = 0;
  for(i = 0; i < n; i++){
    int min = i;
    for (j = i+1; j < n; j++){
      if(strcmp(array[min].name,array[j].name) > 0) min = j;
    }
    swap(&array[i],&array[min]);
  }
}

void verify(FILE *file1, FILE *file2){
  char buff[MAX];
  int f= 0;
  int i = 0, n1 = 0, n2 = 0;
  n1 = get_size(file1);
  n2 = get_size(file2);

  student *array1;
  array1 = (student*)malloc(n1*sizeof(student));
  while(i < n1){
    fscanf(file1, "%d %s %s %s %d", &array1[i].stt, array1[i].mssv, array1[i].name, array1[i].tel, &array1[i].grade);
    i++;
  }
  i = 0;
  student *array2;
  array2 = (student*)malloc(n2*sizeof(student));
  while(i < n2){
    fscanf(file2, "%d %s %s %s %d", &array2[i].stt, array2[i].mssv, array2[i].name, array2[i].tel, &array2[i].grade);
    i++;
  }
  selection_sort(array1,n1);
  selection_sort(array2,n2);
  i = 0;

  printf("\nStudent(s) in file %s not in file %s is: \n","file1","file2");
  for (i = 0; i < n1; i++) {
    if((f = binary_search(array2,array1[i].name,0,n2-1)) == -1) printArray(&array1[i]);
  }

  printf("\nStudent(s) in file %s not in file %s is: \n","file2","file1");
  for (i = 0; i < n2; i++) {
    if((f = binary_search(array1,array2[i].name,0,n1-1)) == -1) printArray(&array2[i]);
  }

  free(array1); free(array2);
}

int binary_search(student *a, char *target, int low, int high){
  int f = 0;
  if(high == low)
    if(strcmp(a[high].name,target) == 0) return high;
    else return -1;
  if(low > high) return -1;
  int mid = (low+high)/2;
  if((f=strcmp(a[mid].name,target)) == 0) return mid;
  else if(f > 0) binary_search(a,target,low,mid-1);
  else if(f < 0) binary_search(a,target,mid+1,high);
}

void printArray(student *a){
  printf("%d - ",a->stt);
  printf("%s - ",a->mssv);
  printf("%s - ",a->name);
  printf("%s - ",a->tel);
  printf("%d\n",a->grade);
}

void append(student *a, student *b){
  a->stt = b->stt;
  strcpy(a->mssv,b->mssv);
  strcpy(a->name,b->name);
  strcpy(a->tel,b->tel);
  a->grade = b->grade;
}

void swap(student *a, student *b){
  student temp;
  append(&temp,b);
  append(b,a);
  append(a,&temp);
}


int get_size(FILE *file){
  int size = 0;
  int cur = ftell(file);
  fseek(file,0,SEEK_SET);
  char buff[MAX];
  while(fgets(buff,MAX,file) != NULL)
    size++;
  fseek(file,cur,SEEK_SET);

  return size;
}