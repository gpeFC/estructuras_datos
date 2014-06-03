/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 22 / Mayo / 2014
* 
* Practica: Arbol(Ternario).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 6

typedef struct Raiz{
	char palabra[TAM];
	struct Raiz *subIzq;
	struct Raiz *subCen;
	struct Raiz *subDer;
}ARBOL;

void mutarPalabra(char* cadena);
ARBOL* crearNodo(char* cadena);
int generaNodos(ARBOL** raiz, char* cadena);
int buscarNodo(ARBOL *raiz, char* cadena);
void imprimeNodos(ARBOL* raiz);
void borrarArbol(ARBOL **raiz);

void main(void){
	int i, c;
	char continuar;
	char palabra[TAM], aleatoria[TAM];
	ARBOL *arbol=NULL;

	srand(time(NULL));

	printf("\nGenerar palabra.\n");

	printf("\nIngresa una palabra de 5 letras: ");
	scanf("%s", palabra);

	for(i=0;i<strlen(palabra);i++){
		if(i == strlen(palabra)-1){
			aleatoria[i] = rand() % 25+97;
			aleatoria[i+1] = '\0';
		}
		else
			aleatoria[i] = rand() % 25+97;
	}

	printf("\nPalabras::=> Entrada(%s), Generada(%s).\n", palabra, aleatoria);

	c = 0;
	arbol = crearNodo(aleatoria);
	while(c < 8){
		generaNodos(&arbol, aleatoria);
		printf("\n\nPresiona <Enter> para continuar...");
		continuar = getchar();
		imprimeNodos(arbol);
		c++;
	}
	if(buscarNodo(arbol, palabra))
		printf("\nPalabra encontrada...\n");
	else
		printf("\nPalabra no encontrada...\n");
	borrarArbol(&arbol);
}

void mutarPalabra(char* cadena){
	int i;
	for(i=0;i<strlen(cadena);i++){
		if((rand()%2) == 0){
			if((rand()%2) == 1){
				if(cadena[i] == 122)
					cadena[i] = 97;
				else
					cadena[i] = cadena[i] + 1;
			}
			else{
				if(cadena[i] == 97)
					cadena[i] = 122;
				else
					cadena[i] = cadena[i] - 1;
			}
		}
	}
}

ARBOL* crearNodo(char* cadena){
	ARBOL *nodo;
	nodo = (ARBOL*)malloc(sizeof(ARBOL));
	strcpy(nodo->palabra, cadena);
	mutarPalabra(nodo->palabra);
	nodo->subIzq = nodo->subCen = nodo->subDer = NULL;
	return nodo;
}

int generaNodos(ARBOL** raiz, char* cadena){
	if(*raiz){
		generaNodos(&((*raiz)->subIzq), (*raiz)->palabra);
		generaNodos(&((*raiz)->subCen), (*raiz)->palabra);
		generaNodos(&((*raiz)->subDer), (*raiz)->palabra);
	}
	else{
		*raiz = crearNodo(cadena);
		//printf("\n%s", (*raiz)->palabra);
		return 1;
	}
}

int buscarNodo(ARBOL* raiz, char* cadena){
	if(!raiz)
		return 0;
	else if((strcmp(raiz->palabra, cadena))==0)
		return 1;
	else{
		buscarNodo(raiz->subIzq, cadena);
		buscarNodo(raiz->subCen, cadena);
		buscarNodo(raiz->subDer, cadena);
	}
}

void imprimeNodos(ARBOL* raiz){
	if(raiz){
		printf("(%s) ", raiz->palabra);
		imprimeNodos(raiz->subIzq);
		imprimeNodos(raiz->subCen);
		imprimeNodos(raiz->subDer);
	}
}

void borrarArbol(ARBOL **raiz){
	if(*raiz){
		borrarArbol(&((*raiz)->subIzq));
		borrarArbol(&((*raiz)->subCen));
		borrarArbol(&((*raiz)->subDer));
		free(*raiz);
		*raiz = NULL;
	}
}