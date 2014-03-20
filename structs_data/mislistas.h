/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 19 / Marzo / 2014
* 
* Practica: Aplicaciones de LE y Queues(Funciones y procedimientos/TAD Queue).
******************************************************************************/

typedef struct NodoQ{
	char etiqueta;
	int numero;
	struct NodoQ *sigNodo;
}tsNODO;

void insercionQueue(tsNODO **cabeza, tsNODO **cola, char etq, int num){
	tsNODO *nodo;
	nodo = (tsNODO*)malloc(sizeof(tsNODO));
	nodo->etiqueta = etq;
	nodo->numero = num;
	nodo->sigNodo = NULL;
	if(*cabeza == NULL){
		*cabeza = nodo;
		*cola = nodo;
	}
	else{
		(*cola)->sigNodo = nodo;
		*cola = nodo;
	}
}

void extraccionQueue(tsNODO **cabeza, char *etq, int *num){
	tsNODO *nodo;
	if(*cabeza == NULL){
		printf("\nQueue vacios...\n");
		*etq = '0';
		*num = 0;
	}
	else{
		nodo = *cabeza;
		*cabeza = (*cabeza)->sigNodo;
		*etq = nodo->etiqueta;
		*num = nodo->numero;
		free(nodo);
	}
}

void mostrarQueue(tsNODO *cabeza){
	tsNODO *nodo;
	nodo = cabeza;
	while(nodo != NULL){
		printf("[Cliente(%c):Delay(%d)] ", nodo->etiqueta, nodo->numero);
		nodo = nodo->sigNodo;
	}
}
