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
double metricaOrdenamiento(int num);

void main(void){
	int i;
	int array[7] = {100, 1000, 10000, 100000, 1000000, 2000000, 5000000};
	double metricas[7];

	for(i=0;i<7;i++){
		metricas[i] = metricaOrdenamiento(array[i]);
		printf("\nDuracion[%d]elementos:%lf\n", array[i], metricas[i]);
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
	printf("\nIterBM:%d\n", i);
}

double metricaOrdenamiento(int num){
	int i, arreglo[num];
	double start, finish, duracion;

	srand(time(NULL));

	for(i=0;i<num;i++)
		arreglo[i] = rand() % 1000+1;

	start = clock();
	ordenaBurbuja(arreglo, num);
	finish = clock();
	duracion = (double)((finish-start))/CLOCKS_PER_SEC;

	return duracion;
}