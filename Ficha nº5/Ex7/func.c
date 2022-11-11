#include "func.h"
#include <stdio.h>

int produto_inteiro(int n,int x[],int y[]){
	
	int i,soma;
	soma=0;
	for(i=0;i<n;i++){
		soma+=x[i]*y[i];
	}
	return soma;
}
