#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int b,i;
    float a,valor=1;
    printf("Qual o valor de a:");
    scanf("%f",&a);
    printf("Qual o valor de b:");
    scanf("%d",&b);
	    
	for(i=1;i<=b;i++){

        valor=valor*a;

    }
    printf("Valor=%.2f",valor);


	
	return 0;

}
