/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 30 / Enero / 2014
* 
* Practica 4: Racionales.
******************************************************************************/

#include <stdio.h>

typedef struct{
	/* Racionales */
	int num;
	int den;
}racional;

int maxcodi(int num, int den);
racional imprime(raciona a, racional b);
racional suma(racional a, racional b);
racional resta(racional a, racional b);
racional multiplica(racional a, racional b);
racional divide(racional a, racional b);

void main(void){
	racional x, y, z;
	x.num = 3;
	x.den = 7;
	y.num = 6;
	y.den = 3;
	z = suma(x, y);
	printf("\nSuma: %d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
}


int maxcodi(int num1, int num2){
	int temp;
	while(num2){
		temp = num1;
		num1 = num2;
		num2 = temp % num2;
	}
	return num1;
}
racional suma(racional a, racional b){
	int mcd;
	racional r;
	r.num = a.num * b.den + b.num * a.den;
	r.den = a.den * b.den;
	mcd = maxcodi(r.num, r.den);
	r.num /= mcd;
	r.den /= mcd;
	return r;
}
racional resta(racional a, racional b){
	int mcd;
	racional r;
	r.num = a.num * b.den - b.num * a.den;
	r.den = a.den * b.den;
	mcd = maxcodi(r.num, r.den);
	r.num /= mcd;
	r.den /= mcd;
	return r;	
}
racional multiplica(racional a, racional b){
	int mcd;
	racional r;
	r.num = a.num * b.num;
	r.den = a.den * b.den;
	mcd = maxcodi(r.num, r.den);
	r.num /= mcd;
	r.den /= mcd;
	return r;
}
racional divide(racional a, racional b){
	int mcd;
	racional r;
	r.num = a.num * b.den;
	r.den = a.den * b.num;
	mcd = maxcodi(r.num, r.den);
	r.num /= mcd;
	r.den /= mcd;
	return r;
}