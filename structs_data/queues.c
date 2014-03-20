/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 19 / Marzo / 2014
* 
* Practica: Aplicaciones de LE y Queues.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mislistas.h"

void main(void){
	int i, num, item=65;
	tsNODO *cabezaQ=NULL, *colaQ=NULL;
	tsNODO *lista=NULL;

	srand(time(NULL));

	num = rand() % 2+3;
	for(i=0;i<num;i++){
		insercionLista(&lista, 'Z', i+1);
	}
	num = rand() % 14+5;
	for(i=0;i<num;i++){
		insercionQueue(&cabezaQ, &colaQ, item+i, rand()%7+3);
	}

	printf("\n");
	mostrarLista(lista);
	printf("\n");

	printf("\n{ ");
	mostrarQueue(cabezaQ);
	printf("}\n");

	do{
		system("clear");

		printf("\n");
		mostrarLista(lista);
		printf("\n");

		printf("\n{ ");
		mostrarQueue(cabezaQ);
		printf("}\n");

		

	}while(*colaQ != NULL);
}