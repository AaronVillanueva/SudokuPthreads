#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

/*1 vertical, 1 horizontals, 9 for subgrids*/
typedef struct par{
  int num;
  int row;
  int col;
  int (*sudoku)[9];
    
} par;

int results[11];

void *column(void *arg);
void *row(void *arg);
void *subgrid(void *arg);

int main(){
  
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
 
  data[0]->sudoku=sudoku;
  pthread_t threads[11];
  
    
  pthread_create(&threads[0],NULL,column,(void *)data[0]);
  
  
  
  pthread_join(threads[0],NULL);
  if(results[0]==1){
    printf("yay");
  }
  
  return 0;
}

void *column(void *data){
    
  par *params=(par*)data;
    
  
  int i,j,k;
  int countColumn;
  int count;
  
  for (i=0;i<9;i++){
    count=0;
    for (j=0;j<9;j++){
      
      for (k=0;k<=9;k++){
        
        if( params->sudoku[k][i]==j ){
          countColumn+=1;
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
