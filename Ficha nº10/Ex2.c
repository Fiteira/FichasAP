#include<stdio.h>
#include <locale.h>

int leituraInteiroPositivo(){
	int n;
	do{
		printf("Inteiro positivo ");		
		scanf("%d",&n);
	
	}while(n<=0);
	
	return n;
}


int fatorial(int n)	//forma iterativa
{		
	int i, prod=1;
	for (i=1;i<=n;i++)
		prod*=i;
	return prod;						
}

int fatorial_r1(int n)	// calculo de forma recursiva(ordem decrescente de indice)
{

	if (n==1)
		return n;
	else 
	return (n * fatorial_r1(n-1));
}





void main(){
	int l;
	l=leituraInteiroPositivo();
	
	printf("Fatorial (forma iterativa) de %d = %d ",l,fatorial(l));
	printf("\nFatorial (forma recursiva) de %d = %d ",l,fatorial_r1(l));
		
	
}
