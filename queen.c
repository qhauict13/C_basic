#include <stdio.h>

int board[20];
int count = 0;

void print_board(int n);
int isValid(int row, int n);
void try(int row, int n);

int main(){
  int n,i,j;
  printf("Enter number of queens: ");
  scanf("%d", &n);
  try(1,n);
  return 0;
}

int isValid(int row, int column){
  int i;
  for (i = 1; i <= row-1; i++){
    if(board[i] == column) return 0;
    else if (((board[i]-column) == (i-row)) || ((board[i]-column) == -(i-row))) return 0;
  }
  return 1;
}

void try(int row, int n){
  int column;
  for (column = 1; column <= n; column++){
    if(isValid(row,column)){
      board[row] = column;
      if (row == n) print_board(n);
      else try(row+1,n);
    }
  }
}

void print_board(int n){
  int i,j;
  printf("\n\n solution %d:\n\n",++count);

  for(i=1;i<=n;i++){
      printf("\t%d",i);
  }
  for(i=1;i<=n;i++){
    printf("\n\n%d",i);
    for(j=1;j<=n;j++){
      if(board[i]==j) printf("\tQ");
      else printf("\t-");
    }
  }
}
