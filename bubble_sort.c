/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 
* Practica: Algoritmos de Ordenamiento: Ordenamiento por Burbuja(BubbleSort).
******************************************************************************/

#include <stdio.h>
#include <time.h>

#define MAX 1000 // Macro para el numero maximo de elementos en el arreglo.

void ordenaBurbuja(int a[], int n); // Declaracion de la funcion de ordenamiento.

void main(void){
	int i, arreglo[MAX];
	double duracion, inicio, final; // Variables para medir el delay del ordenamiento.

	srand(time(NULL)); // Generacion de la semilla para generar los numeros aleatorios.

	for(i=0;i<MAX;i++) // Bucle para llenar el arreglo con numeros aleatorios en el intervalo[1-1000].
		arreglo[i] = rand() % 1000+1;

	inicio = clock();
	ordenaBurbuja(arreglo, MAX); // Llamada de la funcion de ordenamiento.
	final = clock();

	duracion = (double)((final-inicio))/CLOCKS_PER_SEC; // Calculo del delay del ordenamiento.
	
	printf("\n\nDuracion: %lf\n\n", duracion);
}

void ordenaBurbuja(int a[], int n){ // Definicion de la funcion de ordenamiento. Ordena de menor a mayor.

	int i,j,aux; // aux: variable auxiliar para almacenar temporalmente un elemento del arreglo.
	
	for(i=0;i<(n-1);i++){ // Bucle para iterar del elemento 1 al elemento n-1 del arreglo.
	
		for(j=i+1;j<n;j++){ // Bucle para iterar del elemento i+1 al elemento n del arreglo. (2<=j<=n)
	
			if(a[i]>a[j]){ // Comparacion entre dos elementos contiguos del arreglo.
	
				aux = a[i]; // Respaldo del elemento [i] a ser ordenado en el arreglo.

				a[i] = a[j]; // Reasignacion del elemento [j] a la posicion i en el arreglo.
				
				a[j] = aux; // Asignacion del elemento [i] a la posicion j en el arreglo.
	
			}
		}
	}
}