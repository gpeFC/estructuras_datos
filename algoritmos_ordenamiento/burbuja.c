/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 13 / Febrero / 2014
* 
* Practica: Algoritmos de Ordenamiento(Burbuja).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenaBurbuja(int v[], int n);
void ordenaBurbujaB(int v[], int n);
long double metricaOrdenamiento(int num);

void main(void){
	int i;
	long double duracion;

	for(i=200000;i<=200000;i=i+20000){
		duracion = metricaOrdenamiento(i);
		printf("\nDuracion[%d]elementos:%LF\n", i, duracion);
	}

	printf("\n");
}


void ordenaBurbuja(int v[], int n){
	int i,j,temp;
	for(i=0;i<(n-1);i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

void ordenaBurbujaB(int v[], int n){
	int i,j,temp, bandera=1;
	for(i=0;i<(n-1)&&bandera;i++){
		bandera = 0;
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
				bandera = 1;
			}
		}
	}
}

long double metricaOrdenamiento(int num){
	int i, arreglo[num];
	long double start, finish, duracion;

	srand(time(NULL));

	for(i=0;i<num;i++)
		arreglo[i] = rand() % 1000+1;

	start = clock();
	ordenaBurbuja(arreglo, num);
	finish = clock();
	duracion = (long double)((finish-start))/CLOCKS_PER_SEC;

	return duracion;
}