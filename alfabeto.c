/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 
* Programa 0. (Incompleto)
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0
#define SUP 20
#define MAX 26

typedef struct{
  /* Coordenadas de un Elemento */
  int x;
  int y;
}elemento;

void main(void){
  int i, j, k, n, m;
  char matriz[SUP][SUP];
  elemento numeros[MAX];

  for(i=0;i<SUP;i++)
    for(j=0;j<SUP;j++)
	  matriz[i][j] = '*';

  srand(time(NULL));

  numeros[0].x = rand() % SUP;
  numeros[0].y = rand() % SUP;
  matriz[numeros[0].x][numeros[0].y] = 65;

  for(i=1;i<MAX;i++){
    j = rand() % 4;
	if(j==0){
	  if((numeros[i-1].x - 1) < INF){
	    numeros[i].x = SUP;
	  }
	  else{
	    numeros[i].x = numeros[i-1].x - 1;
	  }
	  numeros[i].y = numeros[i-1].y;
	}
	else if(j==1){
	  numeros[i].x = numeros[i-1].x;
	  if((numeros[i-1].y - 1) < INF){
	    numeros[i].y = SUP;
	  }
	  else{
	    numeros[i].y = numeros[i-1].y - 1;
	  }
    }
	else if(j==2){
	  numeros[i].x = numeros[i-1].x;
	  if((numeros[i-1].y + 1) >= SUP){
	    numeros[i].y = INF;
	  }
	  else{
	    numeros[i].y = numeros[i-1].y + 1;
	  }
	}
	else if(j==3){
	  if((numeros[i-1].x + 1) >= SUP){
	    numeros[i].x = INF;
	  }
	  else{
	    numeros[i].x = numeros[i-1].x + 1;
	  }
	  numeros[i].y = numeros[i-1].y;
	}
	if(matriz[numeros[i].x][numeros[i].y]=='*'){
	  matriz[numeros[i].x][numeros[i].y] = i + 65;
	}
	else{
	  i--;
	 }
  }

  k=0;
  do{
  	system("clear");
  	printf("\n");

  	for(i=0;i<SUP;i++){
	    for(j=0;j<SUP;j++)
	    	printf("%c ", matriz[i][j]);
		printf("\n");
	 }
	 printf("\n");

  	k++;
  }while(k<(MAX*2));
}
