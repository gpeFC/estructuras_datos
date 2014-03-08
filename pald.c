/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Palindromo.
******************************************************************************/

#include <stdio.h>
#include <string.h>

void main(void){
	char palabra[26], notspc[26];
	int i,j,bandera=1;

	printf("\nIngresa la palabra: ");
	gets(palabra);

	j = 0;
	for(i=0;palabra[i]!='\0';i++){
		if(palabra[i] != ' '){
			notspc[j] = palabra[i];
			j++;
		}
	}
	notspc[j] = NULL;
	for(i=0,j=(strlen(notspc))-1;i<=j;i++,j--){
		if(notspc[i]!=notspc[j]){
			bandera = 0;
			break;
		}
	}
	if(bandera){
		printf("\n<%s> si es un palindromo.\n", palabra);
	}
	else{
		printf("\n<%s> no es un palindromo.\n", palabra);
	}
}