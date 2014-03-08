#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000000

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);


long double metricaOrdenamiento(int num){
    int i, arreglo[num];
    long double start, finish, duracion;

    srand(time(NULL));

    for(i=0;i<num;i++)
        arreglo[i] = rand() % 1000+1;

    start = clock();
    partition(arreglo,0,num-1);
    finish = clock();
    duracion = (long double)((finish-start))/CLOCKS_PER_SEC;

    return duracion;
}


int main(){
    double duration;
	clock_t start,finish;
	start =clock();
    int i;
    long double duracion;

    for(i=20000;i<=200000;i=i+20000){
        duracion = metricaOrdenamiento(i);
        printf("\nDuracion[%d]elementos:%LF\n", i, duracion);
    }


    return 0;
}

void partition(int arr[],int low,int high){

    int mid;
    //Busca el de en medio y lo guarda en mid
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,a[MAX];
//l=i=low, m=mid+1
    l=low;
    i=low;
    m=mid+1;
//mientras (low) sea menor o igual al (numero medio) && el (numero medio mas uno) sea menor o igual al (mayor)
    while((l<=mid)&&(m<=high)){
//Si el arreglo en la posicion low(menor) es menor <= al arreglo en la posicion m(numero medio mas uno)
         if(arr[l]<=arr[m]){
//entonces el arreglo de (mayor) se colocara en el arreglo (mayor)principal 
             a[i]=arr[l];
             l++;
         }
         else{
//sino el arreglo de (mayor) se colocara en el arreglo (medio) principal 
             a[i]=arr[m];
             m++;
         }
         i++;
    }
//si el menor
    if(l>mid){
         for(k=m;k<=high;k++){
             a[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             a[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=a[k];
    }

}
