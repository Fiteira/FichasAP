#include <stdio.h>
#include <locale.h>
#include <math.h>


	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i,sinal;
    float soma;
    printf("Qual o valor de n:");
    scanf("%d",&n);
    
    sinal=1;
    soma=1;

        for(i=1;i<=n;i++){
		
		sinal=-sinal;
        soma=(soma+(float)sinal/(i*2));

        printf("\n -iteração %d,soma= %0.3f", i,(float)sinal/(i*2));
        
        }
    printf("\n Soma total=%0.3f",1-soma);


	
	return 0;

}
