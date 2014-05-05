/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 29 / Abril / 2014
* 
* Practica: Juego(LDE, Funciones y TAD).
******************************************************************************/

#include <time.h>

typedef struct Nodo{
	struct Nodo *prevNodo;
	int pasos;
	int sentido;
	char etiqueta;
	struct Nodo *sigNodo;
}tsNODO;


void insercion(tsNODO **centinela, tsNODO **actual, int etiq){
	tsNODO *nodo;
	nodo = (tsNODO*)malloc(sizeof(tsNODO));
	srand(time(NULL));
	nodo->pasos = rand() % 3+7;
	nodo->sentido = rand() % 2;
	nodo->etiqueta = etiq;
	nodo->prevNodo = NULL;
	nodo->sigNodo = NULL;
	if(*centinela == NULL){
		printf("\nPrimero...\n");
		*centinela = nodo;
		*actual = *centinela;
		(*centinela)->prevNodo = *centinela;
		(*centinela)->sigNodo = *centinela;
	}
	else{
		printf("\nSegundo...\n");
		nodo->prevNodo = *centinela;
		((*centinela)->sigNodo)->prevNodo = nodo;
		nodo->sigNodo = (*centinela)->sigNodo;
		(nodo->sigNodo)->prevNodo = nodo;
	}
}

void extraccion(tsNODO **centinela, int pasos, int sentido, int *pas, int *sent){
	int i;
	tsNODO *nodo, *supr;
	nodo = *centinela;
	i=1;
	while(nodo && (i<pasos)){
		if(sentido == 0)
			nodo = nodo->sigNodo;
		else
			nodo = nodo->prevNodo;
	}
	if(sentido == 0){
		if( (nodo->sigNodo) == *centinela )
			*centinela = (*centinela)->sigNodo;
		supr = nodo->sigNodo;
		nodo->sigNodo = supr->sigNodo;
		(supr->sigNodo)->prevNodo = supr->prevNodo;
	}
	else{
		if((nodo->prevNodo) == *centinela)
			*centinela = (*centinela)->prevNodo;
		supr = nodo->prevNodo;
		nodo->prevNodo = supr->prevNodo;
		(supr->prevNodo)->sigNodo = supr->sigNodo;
	}
	*pas = supr->pasos;
	*sent = supr->sentido;
	free(supr);
}

void mostrar(tsNODO *centinela){
	tsNODO *nodo;
	if(centinela){
		nodo = centinela;
		do{
			printf("[(ETQA:%c)-(STDO:%d)-(PSS:%d)] ", nodo->etiqueta, nodo->sentido, nodo->pasos);
			nodo = nodo->sigNodo;
		}while(nodo != centinela);
	}
	else
		printf("\nLista vacia...\n");
}

void borrar(tsNODO **centinela){
	tsNODO *nodo;
	if(*centinela){
		nodo = (*centinela)->sigNodo;
	}
}
