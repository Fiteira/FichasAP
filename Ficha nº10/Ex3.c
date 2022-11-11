#include<stdio.h>
#include <locale.h>

float fator(){
	int x;
	do{
		printf("real positivo x: ");		
		scanf("%d",&x);
	
	}while(x<=0);
	
	return x;
}

int expoente(){
	int n;
	do{
		printf("Inteiro positivo n: ");		
		scanf("%d",&n);
	
	}while(n<=0);
	
	return n;
}



double potencia(int n,float x)	//forma iterativa
{		
	int i, prod=1;
	for (i=1;i<=n;i++)
		prod*=x;
	return prod;						
}

double potencia_r1(int i,float x)	// calculo de forma recursiva(ordem decrescente de indice)
{
	
	if (i==1)
		return x;
	else 
	 return x*potencia_r1(i-1,x);
}





void main(){
	int n;
	float x;
	x=fator();
	n=expoente();
	
	printf("Fatorial (%.1f)^%d (forma iterativa)= %.1f ",x,n,potencia(n,x));
	printf("\nFatorial (%.1f)^%d (forma recursiva)= %.1f ",x,n,potencia_r1(n,x));
		
	
}
