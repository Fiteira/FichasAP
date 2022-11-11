#include<stdio.h>
#include <locale.h>

int leituraLimSup(){
	int n;
	do{
		printf("Limite superior da soma ");		
		scanf("%d",&n);
	
	}while(n<=0);
	
	return n;
}

int somatorio(int n)	//forma iterativa
{		
	int i, soma=0;
	for (i=1;i<=n;i++)
		soma+=i;
	return soma;						
}



int somatorio_r1(int n)		// calculo de forma recursiva(ordem decrescente de indice)
{
	if(n==1)
	return n;
	else
	return(n + somatorio_r1(n-1));
}

void main(){
	int l;
	l=leituraLimSup();
	printf("Somatorio (forma iterativa)= %d ",somatorio(l));
	printf("\nSomatorio (forma recursiva)= %d ",somatorio_r1(l));
		
	
}
