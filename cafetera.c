/******************************************************************************
* Estructura de Datos
* Emanuel GP
* 30 / Enero / 2014
* 
* Practica 2: Cafetera.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void coffe();
void cambio(int *m1, int *m2, int *m5, int *m10, int vuelto);
int producto(int *cafe, int *leche, int *agua, int *azucar, int c, int l, int a, int *m1, int *m2, int *m5, int *m10, int precio);

void main(void){
	int mnda1=10, mnda2=7, mnda5=5, mnda10=5, cmbo;
	int agua=500, cafe=50, leche=30, azucar=20, bandera=1;
	char cnt, opcion[2]="S";
	do{
		system("clear");
		printf("\t\t\t\tCOFFE\n");
		printf("\nPorciones/Actuales: Agua(%dml)  Cafe(%dgr)  Azucar(%dgr)  Leche(%dgr)", agua, cafe, azucar, leche);
		printf("\nUnidades/Actuales: $1.00(%du) $2.00(%du) $5.00(%du) $10.00(%du)\n", mnda1, mnda2, mnda5, mnda10);
		printf("\n|----------------------------------------------------------|");
		printf("\n| Producto   | Precio | Ingredientes/Porciones             |");
		printf("\n|----------------------------------------------------------|");
		printf("\n|[E]xpreso   | $ 7.00 | (Cafe: 5 gr), (Azucar: 3, 2, 1 gr) |");
		printf("\n|            |        | (Leche: 2 gr), (Agua: 10 ml)       |");
		printf("\n|----------------------------------------------------------|");
		printf("\n|[A]mericano | $ 5.00 | (Cafe: 7 gr), (Azucar: 3, 2, 1 gr) |");
		printf("\n|            |        | (Leche: 3 gr), (Agua: 20 ml)       |");
		printf("\n|----------------------------------------------------------|");
		printf("\n|[C]apuchino | $ 9.00 | (Cafe: 5 gr), (Azucar: 3, 2, 1 gr) |");
		printf("\n|            |        | (Leche: 5 gr), (Agua: 15 ml)       |");
		printf("\n|----------------------------------------------------------|");
		printf("\n|[L]atte     | $ 10.00| (Cafe: 5 gr), (Azucar: 3, 2, 1 gr) |");
		printf("\n|            |        | (Leche: 10 gr), (Agua: 15 ml)      |");
		printf("\n|----------------------------------------------------------|");
		printf("\n|[S]alir del programa.                                     |");
		printf("\n|----------------------------------------------------------|");
		if(!strcmp(opcion, "I"))
			printf("\n>>>Opcion Invalida...");
		printf("\n\nIndica la operacion a realizar: ");
		scanf("%s", opcion);

		if(!strcmp(opcion, "s") || !strcmp(opcion, "S") || ((mnda1*1) + (mnda2*2) + (mnda5*5) + (mnda10*10)) < 5){
			system("clear");
			bandera--;
		}
		else if(!strcmp(opcion, "e") || !strcmp(opcion, "E")){
			system("clear");
			if((cafe < 5) || (leche < 2) || (agua < 10) || (azucar < 3)){
				printf("\nPorciones de ingredientes insuficientes para el producto deseado.");
				printf("\nPresione <Enter> para continuar...");
				cnt = getchar();
			}
			else{
				cmbo = producto(&cafe, &leche, &agua, &azucar, 5, 2, 10, &mnda1, &mnda2, &mnda5, &mnda10, 7);
				system("clear");
				printf("\n\t!>>EXPRESO LISTO<<¡\n");
				coffe();
				cambio(&mnda1, &mnda2, &mnda5, &mnda10, cmbo);
				printf("\nPresione <Enter> para continuar...");
				while(getchar()!='\n');
				cnt = getchar();
			}
		}
		else if(!strcmp(opcion, "a") || !strcmp(opcion, "A")){
			system("clear");
			if((cafe < 7) || (leche < 3) || (agua < 10) || (azucar < 3)){
				printf("\nPorciones de ingredientes insuficientes para el producto deseado.");
				printf("\nPresione <Enter> para continuar...");
				cnt = getchar();
			}
			else{
				cmbo = producto(&cafe, &leche, &agua, &azucar, 7, 3, 10, &mnda1, &mnda2, &mnda5, &mnda10, 5);
				system("clear");
				printf("\n\t!>>AMERICANO LISTO<<¡\n");
				coffe();
				cambio(&mnda1, &mnda2, &mnda5, &mnda10, cmbo);
				printf("\nPresione <Enter> para continuar...");
				while(getchar()!='\n');
				cnt = getchar();
			}
		}
		else if(!strcmp(opcion, "c") || !strcmp(opcion, "C")){
			system("clear");
			if((cafe < 5) || (leche < 5) || (agua < 15) || (azucar < 3)){
				printf("\nPorciones de ingredientes insuficientes para el producto deseado.");
				printf("\nPresione <Enter> para continuar...");
				cnt = getchar();
			}
			else{
				cmbo = producto(&cafe, &leche, &agua, &azucar, 5, 5, 15, &mnda1, &mnda2, &mnda5, &mnda10, 9);
				system("clear");
				printf("\n\t!>>CAPUCHINO LISTO<<¡\n");
				coffe();
				cambio(&mnda1, &mnda2, &mnda5, &mnda10, cmbo);
				printf("\nPresione <Enter> para continuar...");
				while(getchar()!='\n');
				cnt = getchar();
			}
		}
		else if(!strcmp(opcion, "l") || !strcmp(opcion, "L")){
			system("clear");
			if((cafe < 5) || (leche < 10) || (agua < 15) || (azucar < 3)){
				printf("\nPorciones de ingredientes insuficientes para el producto deseado.");
				printf("\nPresione <Enter> para continuar...");
				cnt = getchar();
			}
			else{
				cmbo = producto(&cafe, &leche, &agua, &azucar, 5, 10, 15, &mnda1, &mnda2, &mnda5, &mnda10, 10);
				system("clear");
				printf("\n\t!>>LATE LISTO<<¡\n");
				coffe();
				cambio(&mnda1, &mnda2, &mnda5, &mnda10, cmbo);
				printf("\nPresione <Enter> para continuar...");
				while(getchar()!='\n');
				cnt = getchar();
			}
		}
		else{
			strcpy(opcion, "I");
		}
	}while(bandera);
}

void coffe(){
	printf("\n |======================|");
	printf("\n|========================|");
	printf("\n|########################|");
	printf("\n |######################|");
	printf("\n |######################|");
	printf("\n  |####################|");
	printf("\n  |####################|");
	printf("\n   |##################|");
	printf("\n   |##################|");
	printf("\n    |################|");
	printf("\n    |################|");
	printf("\n     |##############|");
	printf("\n      --------------\n");
}

void cambio(int *m1, int *m2, int *m5, int *m10, int vuelto){
	while(vuelto > 0){
		if(vuelto >= 10 && *m10 > 0){
			printf("\n>>Cambio: 10");
			*m10 -= 1;
			vuelto-=10;
		}
		else if(vuelto >= 5 && *m5 > 0){
			printf("\n>>Cambio: 5");
			*m5 -= 1;
			vuelto-=5;
		}
		else if(vuelto >= 2 && *m2 > 0){
			printf("\n>>Cambio: 2");
			*m2 -= 1;
			vuelto-=2;
		}
		else if(vuelto >= 1 && *m1 > 0){
			printf("\n>>Cambio: 1");
			*m1 -= 1;
			vuelto-=1;
		}
	}
}

int producto(int *cafe, int *leche, int *agua, int *azucar, int c, int l, int a, int *m1, int *m2, int *m5, int *m10, int precio){
	int total=0, cant_azucar, pago;
	printf("\nIndica la porcion de azucar en gr ( 1 | 2 | 3 ) a agregar: ");
	scanf("%d", &cant_azucar);
	while(total < precio){
		printf("\nIngresa tu pago. Denominaciones(1|2|5|10): ");
		scanf("%d", &pago);
		if((pago!=1) && (pago!=2) && (pago!=5) && (pago!=10)){
			printf("\nDenominacion de moneda invalida...");
		}
		else{
			if(pago == 1){ 
				*m1 += 1;
			}
			else if(pago == 2){ 
				*m2 += 1;
			}
			else if(pago == 5){ 
				*m5 += 1;
			}
			else if(pago == 10){ 
				*m10 += 1;
			}
			total += pago;
		}
	}
	*cafe -= c;
	*leche -= l;
	*agua -= a;
	*azucar -= cant_azucar;
	return (total - precio);
}