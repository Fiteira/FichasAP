#include "func.h"
#include <stdio.h>

void permutacao_circular(int x[],int tam){
	int i,aux;
	aux=x[0];
	
	for(i=0;i<tam-1;i++){	
		x[i]=x[i+1];
	}
	
	x[tam-1]=aux;
}
