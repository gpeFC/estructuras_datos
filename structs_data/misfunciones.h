/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Evaluacion de Expresiones(Funciones y procedimientos/TAD Stack).
******************************************************************************/

typedef struct NodoChar{
	char dato;
	struct NodoChar *sigNodo;
}tsNODOC;

typedef struct NodoFloat{
	double dato;
	struct NodoFloat *sigNodo;
}tsNODOF;


int validaNumero(char item){
	if(item=='0' || item=='1' || item=='2' || item=='3' || item=='4' || item=='5' || item=='6' || item=='7' || item=='8' || item=='9'){
		return 1;
	}
	else{
		return 0;
	}
}

int validaPrioridad(char cima, char actual){
	if((cima=='*' || cima=='/') && (actual=='*' || actual=='/')){
		return 1;
	}
	else if((cima=='*' || cima=='/') && (actual=='+' || actual=='-' || actual=='(')){
		return 2;
	}
	else if((cima=='+' || cima=='-') && (actual=='*' || actual=='/')){
		return 3;
	}
	else if((cima=='+' || cima=='-') && (actual=='+' || actual=='-' || actual=='(')){
		return 4;
	}
	else if(cima=='('){
		return 5;
	}
}

double obtenerNumero(char item){
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

double obtenerResultado(char item, double num1, double num2){
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


void insercionStackChar(tsNODOC **stack, char valor){
	tsNODOC *nodo;
	nodo = (tsNODOC*)malloc(sizeof(tsNODOC));
	nodo->dato = valor;
	nodo->sigNodo = NULL;
	if(*stack == NULL)
		*stack = nodo;
	else{
		nodo->sigNodo = *stack;
		*stack = nodo;
	}
}

void insercionStackFloat(tsNODOF **stack, double valor){
	tsNODOF *nodo;
	nodo = (tsNODOF*)malloc(sizeof(tsNODOF));
	nodo->dato = valor;
	nodo->sigNodo = NULL;
	if(*stack == NULL)
		*stack = nodo;
	else{
		nodo->sigNodo = *stack;
		*stack = nodo;
	}
}

char extraccionStackChar(tsNODOC **stack){
	char valor;
	tsNODOC *nodo;
	if(*stack == NULL)
		return '\0';
	else{
		nodo = *stack;
		*stack = (*stack)->sigNodo;
		valor = nodo->dato;
		free(nodo);
		return valor;
	}
}

double extraccionStackFloat(tsNODOF **stack){
	double valor;
	tsNODOF *nodo;
	if(*stack == NULL)
		return 0.0;
	else{
		nodo = *stack;
		*stack = (*stack)->sigNodo;
		valor = nodo->dato;
		free(nodo);
		return valor;
	}
}

void mostrarStackChar(tsNODOC *stack){
	tsNODOC *nodo;
	nodo = stack;
	while(nodo != NULL){
		printf("%c ", nodo->dato);
		nodo = nodo->sigNodo;
	}
}
void mostrarStackFloat(tsNODOF *stack){
	tsNODOF *nodo;
	nodo = stack;
	while(nodo != NULL){
		printf("%f ", nodo->dato);
		nodo = nodo->sigNodo;
	}
}

/*
void vaciarStackChar(tsNODOC **tad);
void vaciarStackFloat(tsNODOF **tad);
void mostrarStackChar(tsNODOC *tad);
void mostrarStackFloat(tsNODOF *tad);
*/