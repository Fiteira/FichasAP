#include "func.c"
#include <stdio.h>


void main(){
	int v[5],n;
	do{
		
	printf("Numero de elementos do vetor deve ser <=5 ");
	scanf("%d",&n);
		
	}while(n<1 || n> 5);
	
	ler(n,v);	
	escrever(n,v);
	printf("Posicao do maior elemento %d",posmaior(n,v));
}



