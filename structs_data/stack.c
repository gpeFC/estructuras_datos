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
	int items[10];
}stack;

int emptyStack(stack *ps);
void pushStack(stack *ps, int item);
int popStack(stack *ps);


void main(void){
	int i, num_in, num_out;
	char continuar, control[2];
	stack *pStack;

	pStack = (stack*)malloc(sizeof(stack));
	pStack->top = -1;
	do{

		system("clear");
		printf("\t\tSTACK\n");
		printf("\n[1] Agregar numero a la pila.");
		printf("\n[2] Quitar numero de la pila.");
		printf("\n[3] Mostrar numeros en la pila.");
		printf("\n[4] Salir.");
		printf("\n>>Indica la opcion a realizar: ");
		scanf("%s", control);
		
		if(!strcmp(control, "1")){
			system("clear");
			printf("\nPUSH\n");
			printf("\nNumero a ingresar: ");
			scanf("%d", &num_in);
			pushStack(pStack, num_in);
			printf("Presiona <Enter> para continuar...");
			while(getchar() != '\n');
			continuar = getchar();
		}
		else if(!strcmp(control, "2")){
			system("clear");
			printf("\nPOP\n");
			num_out = popStack(pStack);
			if(num_out == -1)
				printf("\nLa pila esta vacia...\n");
			else
				printf("\nNumero quitado de la pila: %d\n", num_out);
			printf("Presiona <Enter> para continuar...");
			while(getchar() != '\n');
			continuar = getchar();
		}
		else if(!strcmp(control, "3")){
			system("clear");
			printf("\nPILA:\n");
			if(emptyStack(pStack))
				printf("\nLa pila esta vacia...\n");
			else
				for(i=(pStack->top);i>=0;i--)
					printf("%d\n", pStack->items[i]);
			printf("Presiona <Enter> para continuar...");
			while(getchar() != '\n');
			continuar = getchar();
		}
	}while(strcmp(control, "4"));
	free(pStack);
	system("clear");
	exit(0);
}

int emptyStack(stack *ps){
	if((ps->top == -1))
		return 1;
	else
		return 0;
}

void pushStack(stack *ps, int item){
	if(ps->top < 9){
		(ps->top)++;
		ps->items[ps->top] = item;
		printf("\nEl numero ha sido apilado.\n");
	}
	else{
		printf("\nLa pila esta llena.\n");
	}
}

int popStack(stack *ps){
	if(emptyStack(ps)){
		return ps->top;
	}
	else{
		return (ps->items[ps->top--]);
	}
}