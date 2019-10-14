#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

/*1 vertical, 1 horizontals, 9 for subgrids*/
typedef struct data{
  int num;
} data;

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
  
  int results[11];
  
 
  data datC,datR;
  pthread_t threads[11];
  
  datC.num=0;
  pthread_create(&threads[0],NULL,column,(void *)datC);
  
  
  
  pthread_join(threads[0]);
  printf(results[0]);
  
  return 0;
}

void column(void *arg){
  int i,j,k;
  int countColumn;
  
  for (i=0;i<9;i++){
    count=0;
    for (j=0;j<9;j++){
      
      for (k=0;k<=9;k++){
        
        if( sudoku[k][i]==j ){
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
    results[num]=1;
  }
  else{
    results[num]=0;
  }
    
  
}


