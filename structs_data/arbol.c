/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 06 / Mayo / 2014
* 
* Practica: Arbol(Binario).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Raiz{
	struct Raiz *subIzq;
	int numero;
	struct Raiz *subDer;
}ARBOL;

int buscar(ARBOL *raiz, int num);
void insertar(ARBOL **raiz, int num);
void eliminar(ARBOL **raiz, int num);
void mostrarArbolPreOrden(ARBOL *raiz);
void mostrarArbolEnOrden(ARBOL *raiz);
void mostrarArbolPostOrden(ARBOL *raiz);
void borrarArbol(ARBOL **raiz);

void main(void){
	int opcion=0, numero;
	char continuar;
	ARBOL *arbol=NULL;

	do{
		system("clear");
		printf("\t\tArbol Binario\n");
		printf("\n1) Buscar.");
		printf("\n2) Agregar.");
		printf("\n3) Eliminar.");
		printf("\n4) Mostrar.");
		printf("\n5) Salir.");
		if(opcion==-1)
			printf("\n\tOpcion invalida...");
		printf("\nOperacion a realizar: ");
		scanf("%d", &opcion);

		if(opcion==1){
			system("clear");
			printf("\t\tBuscar...\n");
			if(arbol){
				printf("\nNumero a buscar: ");
				scanf("%d", &numero);
				if(buscar(arbol, numero))
					printf("\nEl numero %d existe en el arbol.", numero);
				else
					printf("\nEl numero %d no existe en el arbol.", numero);
			}
			else
				printf("\nArbol vacio...");
			printf("\nPresione <Enter> para continuar...");
			while(getchar()!='\n');
			continuar = getchar();
		}
		else if(opcion==2){
			system("clear");
			printf("\t\tAgregar...\n");
			printf("\nNumero a agregar: ");
			scanf("%d", &numero);
			if(buscar(arbol, numero))
				printf("\nEl numero %d existe en el arbol.", numero);
			else
				insertar(&arbol, numero);
			printf("\nPresione <Enter> para continuar...");
			while(getchar()!='\n');
			continuar = getchar();
		}
		else if(opcion==3){
		}
		else if(opcion==4){
			system("clear");
			printf("\t\tMostrar...\n");
			if(arbol){
				printf("\nPreOrden: ");
				mostrarArbolPreOrden(arbol);
				printf("\nEnOrden: ");
				mostrarArbolEnOrden(arbol);
				printf("\nPostOrden: ");
				mostrarArbolPostOrden(arbol);
			}
			else
				printf("\nArbol vacio...");
			printf("\nPresione <Enter> para continuar...");
			while(getchar()!='\n');
			continuar = getchar();
		}
		else if(opcion==5){
			if(arbol)
				borrarArbol(&arbol);
		}
		else{
			opcion = -1;
		}
	}while(opcion != 5);
	if(arbol)
		borrarArbol(&arbol);
	else
		printf("\nArbol nulo...\n");
}


int buscar(ARBOL *raiz, int num){
	if(!raiz)
		return 0;
	else if(num == raiz->numero)
		return 1;
	else if(num < raiz->numero)
		return buscar(raiz->subIzq, num);
	else
		return buscar(raiz->subDer, num);
}

void insertar(ARBOL **raiz, int num){
	ARBOL *hoja;
	if(!(*raiz)){
		hoja = (ARBOL*)malloc(sizeof(ARBOL));
		hoja->numero = num;
		hoja->subIzq = NULL;
		hoja->subDer = NULL;
		*raiz = hoja;
	}
	else if(num < (*raiz)->numero)
		insertar(&((*raiz)->subIzq), num);
	else
		insertar(&((*raiz)->subDer), num);
}

void eliminar(ARBOL **raiz, int num){
	ARBOL *hoja, *reemplazo;
	if(*raiz){
	}
}

void mostrarArbolPreOrden(ARBOL *raiz){
	if(raiz){
		printf("%d ", raiz->numero);
		mostrarArbolPreOrden(raiz->subIzq);
		mostrarArbolPreOrden(raiz->subDer);
	}
}

void mostrarArbolEnOrden(ARBOL *raiz){
	if(raiz){
		mostrarArbolEnOrden(raiz->subIzq);
		printf("%d ", raiz->numero);
		mostrarArbolEnOrden(raiz->subDer);
	}
}

void mostrarArbolPostOrden(ARBOL *raiz){
	if(raiz){
		mostrarArbolPostOrden(raiz->subIzq);
		mostrarArbolPostOrden(raiz->subDer);
		printf("%d ", raiz->numero);
	}
}

void borrarArbol(ARBOL **raiz){
	if(*raiz){
		if((*raiz)->subIzq)
			borrarArbol(&((*raiz)->subIzq));
		if((*raiz)->subDer)
			borrarArbol(&((*raiz)->subDer));
		free(*raiz);
		*raiz = NULL;
	}
}