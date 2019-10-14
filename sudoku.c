/*
http://coliru.stacked-crooked.com/
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

/*1 vertical, 1 horizontals, 9 for subgrids*/
typedef struct par{
  int (*sudoku)[9];
    
} par;

int results[11]={0,0,0,0,0,0,0,0,0,0,0};

void *column(void *arg);
void *row(void *arg);
void *subgrid(void *arg);

int main(void){
  
  int sudoku[9][9]={{8,3,5,4,1,6,9,2,7},
                    {2,9,6,8,5,7,4,3,1},
                    {4,1,7,2,9,3,6,5,8},
                    {5,6,9,1,3,4,7,8,2},
                    {1,2,3,6,7,8,5,4,9},
                    {7,4,8,5,2,9,1,6,3},
                    {6,5,2,7,8,1,3,9,4},
                    {9,8,1,3,4,5,2,7,6},
                    {3,7,4,9,6,2,8,1,5}};
  
  par *data[9]; 
  for (int i=0;i<9;i++){
    data[i] = (par *)malloc(sizeof(par));
    data[i]->sudoku=sudoku;  
      }
  pthread_t threads[11];
  
    
  pthread_create(&threads[0],NULL,column,(void *)data[0]);
  pthread_create(&threads[1],NULL,row,(void *)data[0]);
  
  
  pthread_join(threads[0],NULL);
  pthread_join(threads[1],NULL);
  if(results[1]==1){
    printf("yay");
  }
  
  return 0;
}

void *row(void *data){
  par *params=(par*)data;
  int i,j,k;
  int countRow;
  int count=0;
  /* row iteration*/
  for (i=0;i<9;i++){
    countRow=0;
    /*for each number*/
    for (j=1;j<=9;j++){
      /*for each column within a row*/
      for (k=0;k<9;k++){
        if( params->sudoku[i][k]==j ){
          countRow+=1;
          /*printf("\n %d   %d",j,countColumn);*/
          break;
        }
      }
    }
    if(countRow==9){
    count+=1;
    }
  }
  
  if (count==9){
    results[1]=1;
  }
  else{
    results[1]=0;
  }
  pthread_exit(NULL);
}

void *column(void *data){
  par *params=(par*)data;
  int i,j,k;
  int countColumn;
  int count=0;
  /* column iteration*/
  for (i=0;i<9;i++){
    countColumn=0;
    /*for each number*/
    for (j=1;j<=9;j++){
      /*for each row within a column*/
      for (k=0;k<9;k++){
        if( params->sudoku[k][i]==j ){
          countColumn+=1;
          /*printf("\n %d   %d",j,countColumn);*/
          break;
        }
      }
    }
    if(countColumn==9){
    count+=1;
    }
  }
  
  if (count==9){
    results[0]=1;
  }
  else{
    results[0]=0;
  }
  pthread_exit(NULL);
}
