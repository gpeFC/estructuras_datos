/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Evaluacion de Expresiones.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"

void main(void){
	int i,j;
	double resultado, operando1, operando2;
	char infija[51], postfija[51];
	char operador;
	tsNODOC *stackChar=NULL;
	tsNODOF *stackFloat=NULL;
	
	printf("\nIngresa la expresion a evaluar: ");
	scanf("%s", infija);
	printf("\nExpresion: %s\n", infija);

	j = 0;
	for(i=0;infija[i]!='\0';i++){
		if(validaNumero(infija[i])){
			postfija[j] = infija[i];
			j++;
		}
		else if(infija[i]=='('){
			insercionStackChar(&stackChar, infija[i]);
		}
		else if(infija[i]==')'){
			do{
				if(stackChar==NULL){
					break;
				}
				else{
					operador = extraccionStackChar(&stackChar);
					if(operador=='('){
						break;
					}
					else{
						postfija[j] = operador;
						j++;
					}
				}
			}while(1);
		}
		else{
			if(stackChar==NULL){
				insercionStackChar(&stackChar, infija[i]);
			}
			else{
				while(1){
					if(stackChar==NULL){
						insercionStackChar(&stackChar, infija[i]);
						break;
					}
					else{
						if((validaPrioridad(stackChar->dato, infija[i])==3) || (validaPrioridad(stackChar->dato, infija[i])==5)){
							insercionStackChar(&stackChar, infija[i]);
							break;
						}
						else if((validaPrioridad(stackChar->dato, infija[i])==2) || (validaPrioridad(stackChar->dato, infija[i])==4) || (validaPrioridad(stackChar->dato, infija[i])==1)){
							operador = extraccionStackChar(&stackChar);
							postfija[j] = operador;
							j++;
						}
					}
				}
			}
		}
	}
	while(stackChar != NULL){
		operador = extraccionStackChar(&stackChar);
		postfija[j] = operador;
		j++;
	}
	postfija[j] = '\0';
	printf("\nInfija: %s \nPostfija: %s\n", infija, postfija);

	for(i=0;postfija[i]!='\0';i++){
		if(validaNumero(postfija[i])){
			resultado = obtenerNumero(postfija[i]);
			insercionStackFloat(&stackFloat, resultado);
		}
		else{
			operando2 = extraccionStackFloat(&stackFloat);
			operando1 = extraccionStackFloat(&stackFloat);
			resultado = obtenerResultado(postfija[i], operando1, operando2);
			insercionStackFloat(&stackFloat, resultado);
		}
	}
	resultado = extraccionStackFloat(&stackFloat);
	printf("\nResultado: %f\n", resultado);
}
