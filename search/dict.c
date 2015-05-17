#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct key_t{
  char value[50];
} key;

int binary_search(key *a, char *target, int low, int high);
int get_size(FILE *file);

int main(int argc, char *argv[]){
  FILE *file;
  char *target;
  int i = 0;
  int f = 0;
  if((file = fopen("american-english","r")) == NULL) printf("Cannot open text file!\n");
  else {
    int n = get_size(file);
    printf("Enter desired string: ");
    scanf("%s", target);
    key *array;
    array = (key*)malloc(n*sizeof(key));
    while(i < n){
      fscanf(file,"%s",array[i].value);
      i++;
    }

    int flag;
    if((f = binary_search(array,target,0,n-1)) != -1){
      flag = 1;
      printf("The string %s is found, it's on line %d\n",target,f+1);
    }
    if(flag == 0) printf("The string %s cannot be found\n",target);
  }
  fclose(file);
  return 0;
}

int binary_search(key *a, char *target, int low, int high){
  int f = 0;
  if(high == low)
    if(strcmp(a[high].value,target) == 0) return high;
    else return -1;
  if(low > high) return -1;
  int mid = (low+high)/2;
  if((f=strcmp(a[mid].value,target)) == 0) return mid;
  else if(f > 0) binary_search(a,target,low,mid-1);
  else if(f < 0) binary_search(a,target,mid+1,high);
}

int get_size(FILE *file){
  int size = 0;
  int cur = ftell(file);
  fseek(file,0,SEEK_SET);
  char buff[MAX];
  while(fgets(buff,MAX,file) != NULL) size++;
  fseek(file,cur,SEEK_SET);

  return size;
}
