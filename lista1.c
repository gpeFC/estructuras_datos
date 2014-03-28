/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 19 / Marzo / 2014
* 
* Practica: Aplicaciones de LE y Queues.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo{
	int num;
	struct Nodo *siguiente;
}tNODO;

void insercion(tNODO **inicio, tNODO **final, int n, char c);
int extraccion(tNODO **inicio);
void imprimir(tNODO *inicio);
void borrar_lista(tNODO **inicio);

void main(void){
	tNODO *iniLista=NULL, *finLista=NULL;
	int i, vector[10];
	for(i=1;i<11;i++){
		if(i%2==0){
			insercion(&iniLista, &finLista, i, 'i');
		}
		else{
			insercion(&iniLista, &finLista, i, 'f');
		}
	}
	imprimir(iniLista);
	printf("\n");
	for(i=0;i<10;i++){
		vector[i] = extraccion(&iniLista);
		printf("%d ", vector[i]);
	}
	imprimir(iniLista);
	printf("\n");
	borrar_lista(&iniLista);
}


void insercion(tNODO **inicio, tNODO **final, int n, char c){
	tNODO *nodo;
	nodo = (tNODO*)malloc(sizeof(tNODO));
	nodo->num = n;
	nodo->siguiente = NULL;
	if(*inicio == NULL){
		*inicio = nodo;
		*final = nodo;
	}
	else{
		if(c=='i'){
			nodo->siguiente = *inicio;
			*inicio = nodo;
		}
		else if(c=='f'){
			(*final)->siguiente = nodo;
			*final = nodo;
		}
	}
}

int extraccion(tNODO **inicio){
	tNODO *nodo;
	int dato;
	if(*inicio == NULL){
		return -1;
	}
	else{
		nodo = *inicio;
		*inicio = (*inicio)->siguiente;
		dato = nodo->num;
		free(nodo);
		return dato;
	}
}

void imprimir(tNODO *inicio){
	tNODO *nodo;
	nodo = inicio;
	if(inicio == NULL){
		printf("\n No hay elementos en la lista...DA! \n");
	}
	else{
		while(nodo){
			printf("\n%d", nodo->num);
			nodo = nodo->siguiente;
		}
	}
}

void borrar_lista(tNODO **inicio){
	tNODO *nodo;
	if(*inicio != NULL){
		nodo = *inicio;
		while(nodo){
			*inicio = (*inicio)->siguiente;  // nodo->siguiente;
			free(nodo);
			nodo = *inicio;
		}
	}
}