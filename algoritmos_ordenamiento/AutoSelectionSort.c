/*
ESTRUCTURA DE DATOS 
Hanna Paola Ehrlich López
Programa de ordenamiento de datos
:::SELECTION SORT con Arreglo Dinámico:::
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int *dynArr;
	int size=10000,i,men,x,j;

	for(size=20000;size<=200000;size=size+20000){
		dynArr=(int*)malloc(size*sizeof(*dynArr));
		
		
		for(i=0;i<=size;i++){//Se llena el arreglo
			dynArr[i]=rand()%101;
		}
	
		long double duration;//Inicio del reloj
		clock_t start,finish;
		start=clock();

		for (i=0;i<size-1;i++){ //Se ordena
			men=i; 
			for(j=i+1;j<size;j++){
				if(dynArr[j]<dynArr[men]){
					men=j;
				}
			}
			x=dynArr[i]; 
			dynArr[i]=dynArr[men];
			dynArr[men]=x;
		}

		finish=clock();//Final del reloj
		duration=((long double)(finish-start))/CLOCKS_PER_SEC;
	
		printf("\n\nNumero de datos: %d \nTiempo de ejecucion del programa: %LG \n\n",size,duration);//Se imprimen los datos

		free(dynArr);
	}

	return 0;
}
