#include<stdio.h>


void troca_valores(int *ptr1, int *ptr2){
	int aux;
	
	aux=*ptr1;
	*ptr1=*ptr2;
	*ptr2=aux;
}


main(){
	int n1,n2;
	printf("Introduza o numero 1 e o numero 2:");
	scanf("%d %d",&n1,&n2);
	troca_valores(&n1,&n2);
	printf("%d %d",n1,n2);
	
	
	}
