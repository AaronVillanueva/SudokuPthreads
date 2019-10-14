#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

/*1 vertical, 1 horizontals, 9 for subgrids*/
typedef struct data{
  int num;
  int array[9]
}

int main(){
  
  int sudoku[9][9]={ {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};
  int results[11];
  

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
  
  if (count==9)
    
  
}


