/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 
* Practica: Algoritmos de Ordenamiento.
******************************************************************************/

#include <stdio.h>
#include <time.h>

void ordenaBubbleSort(int a[], int n);
void ordenaSelectionSort(int a[], int n);
void ordenaQuickSort(int a[], int min, int max);

void main(void){
}


void ordenaBubbleSort(int a[], int n){
	int i,j,aux;
	for(i=0;i<(n-1);i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void ordenaSelectionSort(int a[], int n){
	int i, j, index, aux;
	for(i=0;i<n-1;i++){
		index = i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[index])
				index = j;
		}
		aux = a[i];
		a[i] = a[index];
		a[index] = aux;
	}
}

void ordenaQuickSort(int a[], int min, int max){
	int i,j,temp,pivote;
	pivote = a[(min+max)/2];
	i = min;
	j = max;
	do{
		while(a[i]<pivote)
			i++;
		while(a[j]>pivote)
			j--;
		if(i<=j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(min < j)
		ordenaQuickSort(a, min, j);
	if(i < max)
		ordenaQuickSort(a, i, max);
}