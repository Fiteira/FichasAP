#include "func.c"
#include <stdio.h>

void main(){
	
	int n=2,i,soma;
	
	/*for(i=0;i<n;i++){
		
		printf("Elementos %d do vetor ",i);
		scanf("%d",&x[i]);
	
	}
	
	for(i=0;i<n;i++){
		
		printf("Elementos %d do vetor ",i);
		scanf("%d",&y[i]);
	
	}*/
	int x[2] ={2,4};
	int y[2] ={1,2};

	soma=produto_inteiro(n,x,y);

	printf("A soma é %d",soma);
}
