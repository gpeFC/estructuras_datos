/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 06 / Mayo / 2014
* 
* Practica: Arbol(Binario).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Raiz{
	struct Raiz *subIzq;
	int numero;
	struct Raiz *subDer;
}ARBOL;

int buscar(ARBOL *raiz, int num);
int suma(ARBOL *raiz, int num);
void insertar(ARBOL **raiz, int num);
void reemplazar(ARBOL **raiz);
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
				if(buscar(arbol, numero)){
					printf("\nEl numero %d existe en el arbol.", numero);
					printf("\nSuma: %d", (suma(arbol, numero))-1);
				}
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
			system("clear");
			printf("\t\tEliminar...\n");
			if(arbol){
				printf("\nNumero a eliminar: ");
				scanf("%d", &numero);
				if(buscar(arbol, numero)){
					eliminar(&arbol, numero);
				}
				else
						printf("\nEl numero %d no existe en el arbol.", numero);
			}
			else
				printf("\nArbol vacio...");
			printf("\nPresione <Enter> para continuar...");
			while(getchar()!='\n');
			continuar = getchar();
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

int suma(ARBOL *raiz, int num){
	if(!raiz)
		return 0;
	else if(num == raiz->numero)
		return 1;
	else if(num < raiz->numero)
		return ((suma(raiz->subIzq, num))+1);
	else
		return ((suma(raiz->subDer, num))+1);
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

void reemplazar(ARBOL **raiz){
	ARBOL *aux, *temp;
	temp = *raiz;
	if((rand()%2)==0){
		aux = (*raiz)->subIzq;
		while(aux->subDer){
			temp = aux;
			aux = aux->subDer;
		}
		(*raiz)->numero = aux->numero;
		if(temp == (*raiz))
			temp->subIzq = aux->subIzq;
		else
			temp->subDer = aux->subIzq;
		(*raiz) = aux;
	}
	else{
		aux = (*raiz)->subDer;
		while(aux->subIzq){
			temp = aux;
			aux = aux->subIzq;
		}
		(*raiz)->numero = aux->numero;
		if(temp == (*raiz))
			temp->subDer = aux->subDer;
		else
			temp->subIzq = aux->subDer;
		(*raiz) = aux;
	}
}

void eliminar(ARBOL **raiz, int num){
	ARBOL *hoja;
	if((*raiz)){
		if(num < (*raiz)->numero)
			eliminar(&((*raiz)->subIzq), num);
		else if(num > (*raiz)->numero)
			eliminar(&((*raiz)->subDer), num);
		else{
			hoja = (*raiz);
			if(hoja->subIzq == NULL)
				(*raiz) = hoja->subDer;
			else if(hoja->subDer == NULL)
				(*raiz) = hoja->subIzq;
			else{
				reemplazar(&hoja);
			}
			free(hoja);
		}
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
		borrarArbol(&((*raiz)->subIzq));
		borrarArbol(&((*raiz)->subDer));
		free(*raiz);
		*raiz = NULL;
	}
}