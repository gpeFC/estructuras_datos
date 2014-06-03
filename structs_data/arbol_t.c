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

void mutarPalabra(char* cadena, char* origen);
ARBOL* crearNodo(char* cadena, char* origen);
void generaNodos(ARBOL** raiz, char* cadena, char* origen);
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

	strcpy(aleatoria, "crbml");
	printf("\nPalabras::=> Entrada(%s), Generada(%s).\n", palabra, aleatoria);

	c = 0;
	arbol = crearNodo(aleatoria, palabra);

	while(c < 10){ // Aqui se indica cuantos niveles del arbol se van a generar.
		generaNodos(&arbol, aleatoria, palabra);
		c++;
	}

	
	if(buscarNodo(arbol, palabra)) // Cuando hace la busqueda, va imprimiendo las palabras de cada nodo en Pre-Orden.
		printf("\nPalabra encontrada...\n");
	else
		printf("\nPalabra no encontrada...\n");
	printf("\nBuscada: (%s)\n", palabra);
	borrarArbol(&arbol);
}

// La funcion esta condicionada para solo modificar una letra equivocada.
void mutarPalabra(char* cadena, char* origen){
	int i, j;
	for(i=0;i<strlen(cadena);i++){
		if(cadena[i] != origen[i]){
			j = rand()%2;
			if(j == 1){
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

ARBOL* crearNodo(char* cadena, char* origen){
	ARBOL *nodo;
	nodo = (ARBOL*)malloc(sizeof(ARBOL));
	strcpy(nodo->palabra, cadena);
	mutarPalabra(nodo->palabra, origen);
	nodo->subIzq = nodo->subCen = nodo->subDer = NULL;
	return nodo;
}

void generaNodos(ARBOL** raiz, char* cadena, char* origen){
	if(*raiz){
		generaNodos(&((*raiz)->subIzq), (*raiz)->palabra, origen);
		generaNodos(&((*raiz)->subCen), (*raiz)->palabra, origen);
		generaNodos(&((*raiz)->subDer), (*raiz)->palabra, origen);
	}
	else{
		*raiz = crearNodo(cadena, origen);
		//return 1;
	}
}

int buscarNodo(ARBOL* raiz, char* cadena){
	if(!raiz)
		return 0;
	else{
		printf("(%s) ", raiz->palabra);
		if((strcmp(raiz->palabra, cadena))==0){
			return 1;
		}
		else{
			buscarNodo(raiz->subIzq, cadena);
			buscarNodo(raiz->subCen, cadena);
			buscarNodo(raiz->subDer, cadena);
		}
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