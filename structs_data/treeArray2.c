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

int flag=0;

void main(void){
	int i, c;
	char continuar;
	char palabra[TAM], aleatoria[TAM], original[TAM];
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
	strcpy(original, aleatoria);

	printf("\nPalabras::=> Entrada(%s), Generada(%s).\n", palabra, aleatoria);

	c = 0;
	arbol = crearNodo(aleatoria, palabra);

	while(c<12){ // Aqui se indica cuantos niveles del arbol se van a generar.
		generaNodos(&arbol, aleatoria, palabra);
		c++;
	}

	
	if(buscarNodo(arbol, palabra)) // Cuando hace la busqueda, va imprimiendo las palabras de cada nodo en Pre-Orden.
		printf("\nPalabra encontrada...\n");
	else
		printf("\nPalabra no encontrada...\n");
	printf("\nBuscada: (%s) -- Aleatoria: (%s)\n", palabra, original);
	borrarArbol(&arbol);
}


void mutarPalabra(char* cadena, char* origen){
	int i, j, dif=0, var=0;
	int igual=0, difP=0, difN=0, comp=0;
	float ejem=0.0;
	for(i=0; i<strlen(cadena); i++){
		dif = origen[i] - cadena[i];
		if(dif == 0)
			igual++;
		else if (dif > 0)
			difP++;
		else
			difN++;
	}
	for(i=0; i<strlen(cadena); i++){
		var = rand() % 100+1;
		if(var <= (strlen(cadena)-igual)*(float)(100/strlen(cadena))){
			var = rand() % 100+1;
			ejem = 100*(float)(difP/(float)(difP+difN));
			if(var <= ejem){
				if(cadena[i]==122)
					cadena[i] = 97;
				else
					cadena[i]++;
			}
			else{
				if(cadena[i]==97)
					cadena[i] = 122;
				else
					cadena[i]--;
			}
		}
	}
}

ARBOL* crearNodo(char* cadena, char* origen){
	ARBOL *nodo;
	nodo = (ARBOL*)malloc(sizeof(ARBOL));
	strcpy(nodo->palabra, cadena);
	nodo->subIzq = nodo->subCen = nodo->subDer = NULL;
	return nodo;
}

void generaNodos(ARBOL** raiz, char* cadena, char* origen){
	if(*raiz){
		mutarPalabra(cadena, origen);
		generaNodos(&((*raiz)->subIzq), cadena, origen);
		generaNodos(&((*raiz)->subCen), cadena, origen);
		generaNodos(&((*raiz)->subDer), cadena, origen);
	}
	else{
		*raiz = crearNodo(cadena, origen);
	}
}

int buscarNodo(ARBOL* raiz, char* cadena){
	if(!raiz)
		return 0;
	else{
		printf("(%s) ", raiz->palabra);
		if((strcmp(raiz->palabra, cadena))==0){
			return 1;
			flag = 1;
		}
		else{
			buscarNodo(raiz->subIzq, cadena);
			if(flag == 0){	
				buscarNodo(raiz->subCen, cadena);
				if(flag == 0)
					buscarNodo(raiz->subDer, cadena);
					
			}
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
