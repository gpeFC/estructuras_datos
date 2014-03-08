/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 25 / Febrero / 2014
* 
* Practica: Expresiones.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaParent(char item);
int verificaOperador(char item);
int verificaNumero(char item);
int compruebaNumero(char num[]);
void evaluaExpresion(char expres[], int dim);

void main(void){
	int i,j;
	char entrada[26], expresion[26];

	printf("\nIngresa la expresion: ");
	gets(entrada);

	j = 0;
	for(i=0;entrada[i]!='\0';i++){
		if(entrada[i] != ' '){
			expresion[j] = entrada[i];
			j++;
		}
	}
	expresion[j] = '\0';

	printf("\nExpresion: %s --- Longitud: %d\n", expresion, strlen(expresion));

	evaluaExpresion(expresion, strlen(expresion));
}

int verificaParent(char item){
	if(item=='(' || item==')'){
		return 1;
	}
	else{
		return 0;
	}
}

int verificaOperador(char item){
	if(item=='+' || item=='-' || item=='*' || item=='/' || item=='%'){
		return 1;
	}
	else{
		return 0;
	}
}

int verificaNumero(char item){
	if(item=='0'||item=='1'||item=='2'||item=='3'||item=='4'||item=='5'||item=='6'||item=='7'||item=='8'||item=='9'){
		return 1;
	}
	else{
		return 0;
	}
}

int compruebaNumero(char num[]){
	if(num[0]=='0'||num[0]=='1'||num[0]=='2'||num[0]=='3'||num[0]=='4'||num[0]=='5'||num[0]=='5'||num[0]=='6'||num[0]=='7'||num[0]=='8'||num[0]=='9')
		return 1;
	else
		return 0;
}

void evaluaExpresion(char expres[], int dim){
	// ((2+9)-(5*4)+7)/3*4
	int i, indice, index=0, control=0, contador_parent=0;
	int num_c=0, num_i=0, oper_c=0, oper_i=0;
	char *token, matriz[dim][dim];
	while(control < dim){
		indice = 0;
		token = (char*)malloc(dim);
		for(i=control;1;i++){
			if(verificaParent(expres[i])){
				token[indice] = expres[i];
				control++;
				break;
			}
			else if(verificaOperador(expres[i])){
				token[indice] = expres[i];
				control++;
				break;
			}
			else if(verificaNumero(expres[i])){
				token[indice] = expres[i];
				indice++;
				control++;
				if(!verificaNumero(expres[control])){
					break;
				}
				else{
					continue;
				}
			}
		}
		strcpy(matriz[index], token);
		free(token);
		index++;
	}
	for(i=0;i<index;i++)
		printf("\nToken[%d]:%s", i, matriz[i]);
	printf("\n");

	for(i=0;i<index;i++){
		if(strlen(matriz[i]) == 1){
			if(verificaParent(matriz[i][0])){
				if(matriz[i][0]=='(')
					contador_parent++;
				else
					contador_parent--;
			}
			else if(verificaOperador(matriz[i][0])){
				if(i == 0){
					if(!(matriz[i][0]=='+') || !(matriz[i][0]=='-'))
						contador_oper--;
				}
				else{
					if((matriz[i][0]=='+') || !(matriz[i][0]=='-') && (matriz[i-1][0]=='(') && (compruebaNumero(matriz[i+1]))){
						num_c++;;
					}
					else if((compruebaNumero(matriz[i-1])) && (compruebaNumero(matriz[i+1]))){
						num_c++;
					}
					else if( (matriz[i-1][0]=='(') && () )
				}
			}
		}
	}
	compruebaNumero(matriz[10]);
	printf("\n%d\n", contador_parent);
}