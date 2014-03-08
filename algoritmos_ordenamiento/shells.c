
#include <time.h>
#include <stdio.h>

int m[100000];
double duration;
clock_t start,finish;
//int rndm(int n){


//	if (n==19){
//		return 1;
//	}
//	else{
//		return rand(n)%10;
//	}

//}


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


int t,i,j;
int main(){
	
	srand(time(NULL));
	//system("cls");
	printf ("\n");
	for (i=0;i<100000;i++){
		m[i]=rand()%100;
		printf ("%d  ", m[i]);
	}
	printf ("\n");
	
	start=clock();	
	//shell sort
	int k=50000;
   while (k>=1)
   {
     for (i=k;i<100000;i++)
     {
       int v=m[i];
       int j=i-k;
       while ((j>=0)&&(m[j]>v))
       {
         m[j+k]=m[j];
         j-=k;
       }
       m[j+k]=v;
     }
   k/=2;
   }
	finish=clock();

	//imprime shell
   for (i=0;i<100000;i++){
		printf ("%d  ", m[i]);
	}
	printf ("\n");
	printf ("\n");




	duration=finish-start;
	int dn;
	dn=duration/CLOCKS_PER_SEC;
	printf("%d\n", dn);	
//	getchar();
	return 0;
}
