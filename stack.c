/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Estructura de Datos(PILA).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	int items[100];
}stack;

int emptyStack(stack *ps);
void pushStack(stack *ps, int item);
int popStack(stack *ps);


void main(void){
	int x=0, y=0, z=0, w=0;
	char control[2];

	/*
	stack *pStack;
	pStack = (stack*)malloc(sizeof(stack));
	pStack->top = -1;

	if(emptyStack(pStack))
		printf("\nPila vacia\n");

	pushStack(pStack, 2);
	pushStack(pStack, 3);
	pushStack(pStack, 5);

	printf("\nTope:%d\n", pStack->top);

	x = popStack(pStack);
	printf("\nValor:%d\n", x);
	printf("\nTope:%d\n", pStack->top);

	y = popStack(pStack);
	printf("\nValor:%d\n", y);
	printf("\nTope:%d\n", pStack->top);

	z = popStack(pStack);
	printf("\nValor:%d\n", z);
	printf("\nTope:%d\n", pStack->top);

	w = popStack(pStack);
	printf("\nValor:%d\n", w);
	printf("\nTope:%d\n", pStack->top);

	free(pStack);*/

	do{
		system("clear");
		printf("\t\tSTACK\n");
		printf("\n[1] Agregar numero a la pila.");
		printf("\n[2] Quitar numero de la pila.");
		printf("\n[3] Mostrar numeros en la pila.");
		printf("\n[4] Salir.");
		printf("\n>>Indica la opcion a realizar: ");
		scanf("%s", control);
	}while(strcmp(control, "4"));
}

int emptyStack(stack *ps){
	if((ps->top == -1))
		return 1;
	else
		return 0;
}

void pushStack(stack *ps, int item){
	(ps->top)++;
	ps->items[ps->top] = item;
}

int popStack(stack *ps){
	if(emptyStack(ps)){
		printf("\nStack vacio\n");
		return ps->top;
	}
	else{
		return (ps->items[ps->top--]);
	}
}