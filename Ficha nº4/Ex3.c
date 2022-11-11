#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int numero,i;
    printf("Escreva um numero inteiro ");
    scanf("%d",&numero);
    
    for(i=numero;i>=1;i--){
    if(numero%i==0){
    	printf("%d ",i);
	}
}
	
	return 0;
}
