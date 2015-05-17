#include <stdio.h>
#include <stdlib.h>

//---insertion sort----
void insertion_sort(int a[], int n){
  int k;
  for (k = 0; k < n; k++){
    int last = a[k];
    int j = k;
    while(j > 0 && (a[j-1] > last)){
      a[j] = a[j - 1];
      j--;
    }
    a[j] = last;
  }
}
//---selection sort----
swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *b = *a;
  *a = temp;
}
void selection_sort(int a[], int n){
  int k;
  for(k = 0; k < n; k++){
    int min = k;
    int i = 0;
    for(i = k+1; i < n; i++){
      if (a[min] > a[i]) min = i;
    }
    swap(&a[k],&a[min]);
  }
}
//---bubble sort----
void bubble_sort(int a[], int n){
  int swapped;
  do{
    int i;
    swapped = 0;
    for(i = 0; i < n; i++){
      if (a[i] > a[i+1]){
        swap(&a[i],&a[i+1]);
        swapped = 1;
      }
    }
  } while (swapped == 1);
}
//---merge sort----
void merge(int a[], int L, int M, int R){
  int i = L;
  int j = M+1;
  int k, *temp;
  temp = (int *)malloc((R-L+1)*sizeof(int));
  for(k = L; k <= R; k++){
    if(i > M){
      temp[k] = a[j]; j++;
    } else if (j > R){
      temp[k] = a[i]; i++;
    } else {
      if (a[i] < a[j]){
        temp[k] = a[i]; i++;
      } else {
        temp[k] = a[j]; j++;
      }
    }
  }
  for (k = L; k <= R; k++) a[k] = temp[k];
  free(temp);
}

void merge_sort(int a[], int L, int R){
  if (L < R){
    int M = (L+R)/2;
    merge_sort(a,L,M);
    merge_sort(a,M+1,R);
    merge(a,L,M,R);
  }
}

//---quick sort----
int partition(int a[], int L, int R, int indexPivot){
  int pivot = a[indexPivot];
  swap(a[indexPivot], a[R]);
  int storeIndex = L;

  int i;
  for(i = L; i <= R - 1; i++){
    if (a[i] < pivot){
      swap(a[storeIndex], a[i]);
      storeIndex++;
    }
  }
  swap(a[storeIndex], a[R]);
  return storeIndex;
}

int getMenu(){
  int option = 0;
  printf("\n1.Insertion sort\n");
  printf("2.Selection sort\n");
  printf("3.Bubble sort\n");
  printf("4.Merge Sort\n");
  printf("0.Exit\n");
  printf("Your option: "); scanf("%d", &option);
  return option;
}

int printA(int a[], int n){
  int i = 0;
  for (i = 0; i < n; i++){
    printf("%d, ",a[i]);
    if (i == 5) printf("%d\n", a[i]);
  }
}
int main(int argc, char *argv[])
{
  int array[6] = {5,3,6,2,1,9};
  int *temp;
  int i = 0;
  for (;;){
    switch(getMenu()){
    case 1: temp = (int*)malloc(sizeof(int) * 6);
      for (i = 0; i < 6; i++) temp[i] = array[i];
      insertion_sort(temp, 6);
      printA(temp, 6);
      free(temp);
      break;

    case 2: temp = (int*)malloc(sizeof(int) * 6);
      for (i = 0; i < 6; i++) temp[i] = array[i];
      selection_sort(temp, 6);
      printA(temp, 6);
      free(temp);
      break;

    case 3: temp = (int*)malloc(sizeof(int) * 6);
      for (i = 0; i < 6; i++) temp[i] = array[i];
      bubble_sort(temp, 6);
      printA(temp, 6);
      free(temp);
      break;

    case 4: temp = (int*)malloc(sizeof(int) * 6);
      for (i = 0; i < 6; i++) temp[i] = array[i];
      merge_sort(array,0,5);
      printA(temp, 6);
      free(temp);
      break;
    case 0: return 0;
    }
  }
  return 0;
}
