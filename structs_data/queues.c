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
	int i, num, tiempo=1, item=65, continua=1, num_cajas[3];
	char etq_cajas[3];
	tsNODO *cabezaQ=NULL, *colaQ=NULL;

	srand(time(NULL));

	num = rand() % 10+5;
	for(i=0;i<num;i++)
		insercionQueue(&cabezaQ, &colaQ, item+i, rand()%7+3);

	for(i=0;i<3;i++){
		num_cajas[i] = 0;
		etq_cajas[i] = '0';
	}

	while(continua){
		system("clear");
		printf("\nTiempo: [%d]\n", tiempo);

		for(i=0;i<3;i++)
			if((etq_cajas[i]=='0') && (cabezaQ))
				extraccionQueue(&cabezaQ, &etq_cajas[i], &num_cajas[i]);

		printf("\n");
		for(i=0;i<3;i++)
			printf("|CAJA(%d):CLIENTE(%c)|\t", i+1, etq_cajas[i]);
		printf("\n");

		printf("\n{ ");
		mostrarQueue(cabezaQ);
		printf("}\n");

		for(i=0;i<3;i++)
			num_cajas[i]--;

		for(i=0;i<3;i++)
			if(num_cajas[i]==0)
				etq_cajas[i] = '0';

		tiempo++;
		for(i=0;i<500000000;i++){}

		if(etq_cajas[0]=='0' && etq_cajas[1]=='0' && etq_cajas[2]=='0')
			continua = 0;
	}
	system("clear");
	printf("\nTiempo: [%d]\n", tiempo);
	printf("\n");
	for(i=0;i<3;i++)
		printf("|CAJA(%d):CLIENTE(%c)|\t", i+1, etq_cajas[i]);
	printf("\n");

	printf("\n{ ");
	mostrarQueue(cabezaQ);
	printf("}\n");
	printf("\n\n");
}