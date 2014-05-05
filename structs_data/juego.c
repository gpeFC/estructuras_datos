/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 29 / Abril / 2014
* 
* Practica: Juego(LDE).
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void main(void){
	int i, num_nodos, pasos, sentido;
	tsNODO *lista=NULL, *actual=NULL;
	srand(time(NULL));
	num_nodos = rand() % 6+5;
	pasos = rand() % 3+7;
	sentido = rand() % 2;
	mostrar(lista);
	do{
		system("clear");
		printf("\nJuego...\n");
		if(lista == NULL){
			printf("\nNumInit: %d\n", num_nodos);
			for(i=0;i<num_nodos;i++){
				insercion(&lista, &actual, 65+i);
			}
			mostrar(lista);
		}
		else{
			extraccion(&actual, pasos, sentido, &pasos, &sentido);
			mostrar(lista);
		}
	}while(lista);
	mostrar(lista);
}

