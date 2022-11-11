#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int anos,i;
    float CI,CA,j;
    printf("Qual o valor do capital inicial:");
    scanf("%f",&CI);
    printf("Qual o valor de anos:");
    scanf("%d",&anos);
	printf("Qual o valor de juros em %:");
    scanf("%f",&j);
	
	j=j/100;
	    
	CA=CI;   
	    
	for(i=1;i<=anos;i++){

        CA=CA*(1+j);

    }
    printf("Capital Acumulado=%.2f",CA);


	
	return 0;

}
