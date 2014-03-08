/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 13 / Febrero / 2014
* 
* Practica: Algoritmos de Ordenamiento(QuickSort).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 262144


void ordenaQuickSort(int v[], int min, int max);


long double metricaOrdenamiento(int num){
	int i, arreglo[num];
	long double start, finish, duracion;

	srand(time(NULL));

	for(i=0;i<num;i++)
		arreglo[i] = rand() % 1000+1;

	start = clock();
	ordenaQuickSort(arreglo, 0, num);
	finish = clock();
	duracion = (long double)((finish-start))/CLOCKS_PER_SEC;

	return duracion;
}


void main(void){
	int i,vector[MAX];
	long double duracion, start, finish;

	srand(time(NULL));

	for(i=20000;i<=200000;i=i+20000){
		duracion = metricaOrdenamiento(i);
		printf("\nDuracion[%d]elementos:%LF\n", i, duracion);
	}
}


void ordenaQuickSort(int v[], int min, int max){
	int i,j,temp,pivote;

	pivote = v[(min+max)/2];
	i = min;
	j = max;
	do{
		while(v[i]<pivote)
			i++;
		while(v[j]>pivote)
			j--;
		if(i<=j){
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(min < j)
		ordenaQuickSort(v, min, j);
	if(i < max)
		ordenaQuickSort(v, i, max);
}