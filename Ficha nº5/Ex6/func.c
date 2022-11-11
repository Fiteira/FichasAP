#include "func.h"
#include <stdio.h>

void ler(int n,int x[]){
	int i;
	for(i=0;i<n;i++){
		printf("Elementos %d do vetor ",i);
		scanf("%d",&x[i]);
	}
	
}
void escrever(int n,int x[]){
	int i;
	for(i=0;i<n;i++)
	{
		printf("x[%d]=%d \n",i,x[i]);
	}
}


int posmaior(int n, int x[]){
	
	int i,pos=0;
	
	for(i=1;i<n;i++){
		if(x[i]>x[pos]){
			pos=i;
		}
	}
	return pos;
}
