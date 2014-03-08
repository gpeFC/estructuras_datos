#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeheap ( int x[ ], int n ){
	int i, val, s, f;
	for ( i = 1; i < n; i++ ){
        	val = x[i];
        	s = i;
        	f = ( s - 1 ) / 2;
        	while ( s > 0 && x[f] < val ){
            		x[s] = x[f];
            		s = f;
            		f = ( s - 1 ) / 2;
        	}
       	 	x[s] = val;
    	}
}

void heapsort ( int x[ ], int n ){
    	int i, s, f, ivalue;
    	for ( i = n - 1 ; i > 0 ; i-- ){
        	ivalue = x[i];
        	x[i] = x[0];
        	f = 0;

        	if ( i == 1 )
            		s = -1;
       		else
            		s = 1;

        	if ( i > 2 && x[2] > x[1] )
            		s = 2;

        	while ( s >= 0 && ivalue < x[s] ){
            		x[f] = x[s];
            		f = s;
            		s = 2 * f + 1;

            		if ( s + 1 <= i - 1 && x[s] < x[s + 1] )
                		s++;
            		if ( s > i - 1 )
                		s = -1;
        	}
        	x[f] = ivalue;
    	}
}

long double metricaOrdenamiento(int num){
    int i, arreglo[num];
    long double start, finish, duracion;

    srand(time(NULL));

    for(i=0;i<num;i++)
        arreglo[i] = rand() % 1000+1;

    start = clock();
    makeheap (arreglo, num);
    heapsort (arreglo, num);
    finish = clock();
    duracion = (long double)((finish-start))/CLOCKS_PER_SEC;

    return duracion;
}

void main( ){
    int i;
    long double start, finish, duracion;

    for(i=20000;i<=200000;i=i+20000){
        duracion = metricaOrdenamiento(i);
        printf("\nDuracion[%d]elementos:%LF\n", i, duracion);
    }

}
