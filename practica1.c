/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 23 / Enero / 2014
* 
* Practica 1: Matrices.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0
#define SUP 10

typedef struct{
  /* Coordenadas de un Elemento */
  int x;
  int y;
}elemento;

void main(void){
  int i, j;
  int matriz[SUP][SUP];
  elemento numeros[SUP];

  for(i=0;i<SUP;i++)
    for(j=0;j<SUP;j++)
	  matriz[i][j] = 0;

  srand(time(NULL));

  numeros[0].x = rand() % SUP;
  numeros[0].y = rand() % SUP;
  matriz[numeros[0].x][numeros[0].y] = 1;

  for(i=1;i<SUP;i++){
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
	if(matriz[numeros[i].x][numeros[i].y]==0){
	  matriz[numeros[i].x][numeros[i].y] = i + 1;
	}
	else{
	  i--;
	 }
  }
  
  for(i=0;i<SUP;i++){
    for(j=0;j<SUP;j++){
    	if(matriz[i][j] == 0){
    		printf(" · ");
    	}
    	else{
    		printf(" %d ", matriz[i][j]);
    	}
    }
	printf("\n");
  }
}