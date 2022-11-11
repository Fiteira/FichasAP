#include <stdio.h>
#include <ctype.h> 
#include "func.h"

int isdigit1(char c){

	return (c >= '0' && c <= '9');

}

int isalpha1(char c) {

	return (c >= 'a' && c <= 'z' && c>='A' && c<='Z');

}

int isalnum1(char c) {
	return (isdigit1(c)||isalpha1(c));
}
char tolower1(char c){
	if(c>='A' && c<='Z')
		return c + 'a'-'A';
	else	
		return c;
}
char tolouper1(char c){
	if(c>='a' && c<='z')
		return c + 'A'-'a';
	else
		return c;	
}


int resto (int a, int b){
	
	return a%b;
	 
}
int impar (int x) {
	if(x % 2 != 0)
	return 1;
	else 
	return 0;
}
int perfeito (int n){
	int i,soma;
	for(i=1;i<=n/2;i++){
		if(n%i == 0)
		soma=soma+i;
	}
	if(soma==n)
	return 1;
	else
	return 0;
}
int primo(int n){
	if(n%1==0 || n%n==0)
		return 1;
	else
		return 0;
}

void classifica(int a,int b){
	
	int n,div,soma,meio;
	 int perfeito=0, reduzido=0, abundante=0;
	 n=a;
	 do{
	 	
	 	soma=0;
	 	meio=n/2;
	 	for(div=1; div<=meio;div++)
	 		if(resto(n,div)==0)
	 			soma +=div;
	 	if(n==soma){
	 		printf("\n \t %d \t Perfeito",n);
			perfeito++;		 
		 }
	 	else if(n>soma){
	 		printf("\n \t %d \t Reduzido",n);
		 	reduzido++;
		 }
		 else{
		 	printf("\n \t %d \t Abundante",n);
		 	abundante++;
		 }
		 n++;
	}while(n<=b);
	printf("\n");
	printf("\n Total Perfeito: %d ",perfeito);
	printf("\n Total Reduzido: %d ",reduzido);	 
	printf("\n Total Abundante: %d ",abundante);
	 	
	 }
	
	int pedirnum(int n){
		
		printf("Indroduza um numero:");
		scanf("%d",n);
		return n;
	}
	
	int cubo(int n){
		return (n*n*n);
		
	}
