#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Función para dividir el arreglo y hacer los intercambio
int divide(int *lista, int inicio, int fin){
	int izq, der, pivote, temp;
	
	pivote = lista[inicio];	
	izq = inicio;
	der = fin;

	//Mientras no se cruzen los indices
	while (izq < der){
		while (lista[der] > pivote){
			der--;
		}

		while ((izq < der) && (lista[izq] <= pivote)){
			izq++;
		}

		//Si todavía no se cruzan
		if (izq < der){
			temp = lista[izq];
			lista[izq] = lista[der];
			lista[der] = temp;
		}
	}

	//Los indices ya se cruzaron, se pone el pivote
	temp = lista[der];
	lista[der] = lista[inicio];
	lista[inicio] = temp;

	//La nueva posicion del pivote
	return der;
}

//Funcion recursiva para hacer el ordenamiento
void quicksort(int *lista, int inicio, int fin){
	int pivote;

	if (inicio < fin){
		pivote = divide(lista, inicio, fin);
		
		//Ordena la lista de los menores
		quicksort(lista, inicio, pivote-1);

		//Ordena la lista de los mayores
		quicksort(lista, pivote+1, fin);
	}
}

int main(void){
	int size;
	int i;
	double duration;
	clock_t start, finish;

	start = clock();

	printf("Tamaño del arreglo \n");
	scanf ("%d", &size);

	int lista[size];

	srand(time(NULL));

	for (i=0; i<size; i++)
		lista[i] = rand() % 100;

	printf("Lista Desordenada \n");

    	for (i=0; i<size; i++) {
        	printf("%d", lista[i]);
        	if(i<size-1)
            		printf(",");
    	}

    	printf("\n");
    	quicksort(lista, 0, size-1);

	finish = clock();	

    	printf("Lista Ordenada \n");
    	for (i=0; i<size; i++) {
        	printf("%d", lista[i]);
        	if(i<size-1)
            		printf(",");
    	}
	printf("\n");

	duration = ((double)(finish - start))/CLOCKS_PER_SEC;
	printf ("duration: %lf", duration);
	printf("\n");

    	return 0;
}
