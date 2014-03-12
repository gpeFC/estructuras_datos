/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Evaluacion de Expresiones.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
	char dato;
	struct Nodo *sigNodo;
}tsNODO;

typedef struct Nodo2{
	float dato;
	struct Nodo2 *sigNodo;
}tsNODO2;


int validaNumero(char item);
int validaPrioridad(char cima, char oper);

float obtenerNumero(char item);
float obtenerResultado(char item, float num1, float num2);

void insercionStack2(tsNODO2 **stack2, float valor);
float extraccionStack2(tsNODO2 **stack2);


void insercionStack(tsNODO **stack, char valor);
char extraccionStack(tsNODO **stack);

void vaciarTAD(tsNODO **tad);
void mostrarTAD(tsNODO *tad);



void main(void){
	int i,j;
	float r, a, b;
	char infija[51], postfija[51];
	char caract;
	tsNODO *stack=NULL;
	tsNODO2 *stack2=NULL;
	
	printf("\nIngresa la expresion a evaluar: ");
	scanf("%s", infija);
	printf("\nExpresion: %s\n", infija);

	j = 0;
	for(i=0;infija[i] != '\0';i++){
		if(validaNumero(infija[i])){
			postfija[j] = infija[i];
			j++;
		}
		else if(infija[i]=='('){
			insercionStack(&stack, infija[i]);
		}
		else if(infija[i] == ')'){
			do{
				if(stack != NULL){
					caract = extraccionStack(&stack);
					if(caract == '('){
						break;
					}
					else{
						postfija[j] = caract;
						j++;
					}
				}
				else{
					break;
				}
			}while(1);
		}
		else{
			if(stack == NULL){
				insercionStack(&stack, infija[i]);
			}
			else{
				while(1){
					if(stack != NULL){
						if( (validaPrioridad(stack->dato, infija[i])==1) || (validaPrioridad(stack->dato, infija[i])==3) || (validaPrioridad(stack->dato, infija[i])==5) ){
						insercionStack(&stack, infija[i]);
						break;
						}/*
						else if(){
							insercionStack(&stack, infija[i]);
							break;
						}*/
						else if( (validaPrioridad(stack->dato, infija[i])==2) || (validaPrioridad(stack->dato, infija[i])==4) ){
							caract = extraccionStack(&stack);
							postfija[j] = caract;
							j++;
						}/*
						else if(){
							caract = extraccionStack(&stack);
							postfija[j] = caract;
							j++;
						}*//*
						else if(){
							insercionStack(&stack, infija[i]);
							break;
						}*/
					}
					else{
						insercionStack(&stack, infija[i]);
						break;
					}
				}
			}
		}
	}

	while(stack != NULL){
		caract = extraccionStack(&stack);
		postfija[j] = caract;
		j++;
	}
	postfija[j] = '\0';
	printf("\nInfija: %s \nPostfija: %s\n", infija, postfija);

	for(i=0;postfija[i]!='\0';i++){
		if(validaNumero(postfija[i])){
			r = obtenerNumero(postfija[i]);
			insercionStack2(&stack2, r);
		}
		else{
			b = extraccionStack2(&stack2);
			a = extraccionStack2(&stack2);
			r = obtenerResultado(postfija[i], a, b);
			insercionStack2(&stack2, r);
			printf("\na(%.3f) [%c] b(%.3f) = %.3f", a, postfija[i], b, r);
		}
	}
	r = extraccionStack2(&stack2);
	printf("\nResultado: %f\n", r);
}

void insercionStack2(tsNODO2 **stack2, float valor){
	tsNODO2 *nuevoNodo;
	nuevoNodo = (tsNODO2*)malloc(sizeof(tsNODO2));
	nuevoNodo->dato = valor;
	nuevoNodo->sigNodo = NULL;
	if(*stack2 == NULL)
		*stack2 = nuevoNodo;
	else{
		nuevoNodo->sigNodo = *stack2;
		*stack2 = nuevoNodo;
	}
}

float extraccionStack2(tsNODO2 **stack2){
	float valor;
	tsNODO2 *auxNodo;
	if(*stack2 == NULL)
		return 0.0;
	else{
		auxNodo = *stack2;
		*stack2 = (*stack2)->sigNodo;
		valor = auxNodo->dato;
		free(auxNodo);
		return valor;
	}
}

int validaNumero(char item){
	if(item=='0'||item=='1'||item=='2'||item=='3'||item=='4'||item=='5'||item=='6'||item=='7'||item=='8'||item=='9')
		return 1;
	else
		return 0;
}

float obtenerNumero(char item){
	if(item=='0'){
		return 0.0;
	}
	else if(item=='1'){
		return 1.0;
	}
	else if(item=='2'){
		return 2.0;
	}
	else if(item=='3'){
		return 3.0;
	}
	else if(item=='4'){
		return 4.0;
	}
	else if(item=='5'){
		return 5.0;
	}
	else if(item=='6'){
		return 6.0;
	}
	else if(item=='7'){
		return 7.0;
	}
	else if(item=='8'){
		return 8.0;
	}
	else if(item=='9'){
		return 9.0;
	}
}

float obtenerResultado(char item, float num1, float num2){
	
	if(item=='+'){
		return num1 + num2;
	}
	else if(item=='-'){
		return num1 - num2;
	}
	else if(item=='*'){
		return num1 * num2;
	}
	else if(item=='/'){
		return num1 / num2;
	}
}

int validaPrioridad(char cima, char oper){
	if((cima=='*'||cima=='/') && (oper=='*'||oper=='/')){
		return 1;
	}
	else if((cima=='*'||cima=='/') && (oper=='+'||oper=='-'||oper=='(')){
		return 2;
	}
	else if((cima=='+'||cima=='-') && (oper=='*'||oper=='/')){
		return 3;
	}
	else if((cima=='+'||cima=='-') && (oper=='+'||oper=='-'||oper=='(')){
		return 4;
	}
	else if(cima=='('){
		return 5;
	}
}

void insercionStack(tsNODO **stack, char valor){
	tsNODO *nuevoNodo;
	nuevoNodo = (tsNODO*)malloc(sizeof(tsNODO));
	nuevoNodo->dato = valor;
	nuevoNodo->sigNodo = NULL;
	if(*stack == NULL)
		*stack = nuevoNodo;
	else{
		nuevoNodo->sigNodo = *stack;
		*stack = nuevoNodo;
	}
}

char extraccionStack(tsNODO **stack){
	char valor;
	tsNODO *auxNodo;
	if(*stack == NULL)
		return '\0';
	else{
		auxNodo = *stack;
		*stack = (*stack)->sigNodo;
		valor = auxNodo->dato;
		free(auxNodo);
		return valor;
	}
}

void vaciarTAD(tsNODO **tad){
	tsNODO *auxNodo;
	while(*tad != NULL){
		auxNodo = *tad;
		*tad = (*tad)->sigNodo;
		free(auxNodo);
	}
}

void mostrarTAD(tsNODO *tad){
	tsNODO *auxNodo;
	auxNodo = tad;
	while(auxNodo != NULL){
		printf("\n%c", auxNodo->dato);
		auxNodo = auxNodo->sigNodo;
	}
}