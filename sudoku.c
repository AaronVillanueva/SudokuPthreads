#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

/*1 vertical, 1 horizontals, 9 for subgrids*/
typedef struct par{
  int (*sudoku)[9];
  int col;
  int row;
  int number;
} par;

int results[11]={0,0,0,0,0,0,0,0,0,0,0};

void *column(void *arg);
void *row(void *arg);
void *grid(void *arg);

int main(void){
  pthread_t threads[11];
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
    
    int index=0;
    for (int j=0;j<9;j=j+3){
        for (int k=0;k<9;k=k+3){
            data[index]->col=j;
            data[index]->row=k;
            data[index]->number=index;
            pthread_create(&threads[index],NULL,grid,(void *)data[index]);
            index++;
        }
    }
  pthread_create(&threads[index],NULL,column,(void *)data[0]);
  index++;
  pthread_create(&threads[index],NULL,row,(void *)data[0]);
  
  int final=0;
  for (int i=0; i<11;i++){
        pthread_join(threads[i],NULL);
        if(results[i]==1){
            final++;    
        }
        
  }

  
  if(final==11){
    printf("yay the sudoku is solved \n");
    }else{
        printf("nay the sodoku has a problem \n");
    }
  
  return 0;
}

void *grid(void *data){
    par *params=(par*)data;
    int i,j,k;
    int count=0;
    
    for(i=1;i<=9;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                /*printf("i=%d  row=%d col=%d sudoku=%d \n",i,(params->row)+j,(params->row)+k,params->sudoku[(params->row)+j][(params->row)+k]);*/
                if(params->sudoku[(params->row)+j][(params->col)+k]==i){
                    count++;
                }
            }      
        }  
    }
    
    if(count==9){
        results[params->number]=1;
       
    }else{
        results[params->number]=0;
        
    }
    pthread_exit(NULL);
    
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
    results[10]=1;
  }
  else{
    results[10]=0;
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
    results[9]=1;
  }
  else{
    results[9]=0;
  }
  pthread_exit(NULL);
}
