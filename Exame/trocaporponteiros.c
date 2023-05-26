#include<stdio.h>



void troca(int *x,int *y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
	
}

main(){
	int a,b;
	printf("Introduza 1 numero: ");
	scanf("%d",&a);
	
	printf("Introduza 2 numero: ");
	scanf("%d",&b);
	
	
	printf("Antes da troca: a=%d b=%d",a,b);	
	troca(&a,&b);
	printf("\nTroca: a=%d b=%d",a,b);
	
	
	}
