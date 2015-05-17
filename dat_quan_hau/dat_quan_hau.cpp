#include <stdio.h>
#include<stdlib.h>

#define MAX 100

int n,x[MAX],s[MAX],count;
bool found;

void printSolution(){
  count++;
  printf("%dth solution\n",count);
  for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
      if(x[j] == i) printf("1 ");
      else 
	printf("0 ");
    }
    printf("\n");
    s[i] = x[i];
  }
}

bool check(int i,int v){
  for(int j = 1;j <= i-1;j++){
    if(v == x[j]) return false;
    if(v - i == x[j] - j) return false;
    if(v + i == x[j] + j) return false;
  }
  return false;
}

void TRY(int i){   /*  try all value for x[i] being aware of x[1] ... x[i-1]  */
  int v;
  for(v=1;v <= n;v++){
    if(check(i,v)){
      x[i] = v;
      if(i == n){
	printSolution();
      }else{
	TRY(i+1);
      }
    }
  }
}

void writeHTML(char* fn){
  FILE *f = fopen(fn,"w");
  fprintf(f,"<table border = 1");
  for(int i = 1;i <= n;i++){
    fprintf(f,"<tr>");
    for(int j = 1;j <= n;j++ ){
      if(s[j] == i)
	fprintf(f,"<td width = 20 height = 20 bgcolor = 'red'>");
      else 
	fprintf(f,"</td>");
    }
    fprintf(f,"</tr>");;
  }
  fprintf(f,"</table>");
  fclose(f);
}

int main(int argc,char** argv){
  n = atoi(argv[1]);
  count = 0;
  found = false;
  TRY(1);
  writeHTML("queen.html");
}
