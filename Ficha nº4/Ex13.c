#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,d;
    
    printf("Qual o valor de n que seja um número dentro 0 a 100:");
    scanf("%d",&n);
    
    if(0<=n && n<=100){
	
	do{
    printf("\n Qual o numero:");
    scanf("%d",&d);
    
	if(d>n){
    	printf("\n O numero é maior doque o numero a encontrar.");
	}else if(d<n){
		printf("\n O numero é menor doque o numero a encontrar.");
	}else
	printf("Acertou!");
		
	}while(d!=n);
	

	}else{
	printf("O número nao está dentro 0 a 100");
   }
        

}
