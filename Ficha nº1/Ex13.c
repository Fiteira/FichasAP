#include <stdio.h>
#include <locale.h>

	void main(){
		int numero;	
	printf("Introduza o numero inteiro:");
	scanf("%d", &numero);
	
	printf("a) %-8d \n", numero);
	printf("b) %8d \n", numero);
	
}

