#include <stdio.h>
#include <locale.h>

	void main(){
    int a,b;
	
	printf("Introduza dois numero inteiro:\n");
	scanf("%d %d", &a,&b);
    
   if(a==b){
   	printf("Os dois numeros sao iguais");
   	}
	else if(a>b){
	
	   		
			printf("O numero %d e maior que %d", a,b);
   }
	else if(a<b){
	
   		printf("O numero %d e maior que %d", b,a);
}
	


}

