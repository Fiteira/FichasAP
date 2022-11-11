#include <stdio.h>
#include <locale.h>
#include <math.h>

	void main(){
    int a,b,c;
    float raiz,valor1,valor2;
    
	printf("Introduza a,b,c:\n");
	scanf("%d %d %d", &a,&b,&c);

    raiz= b*b-4*a*c;


	if(raiz>0){
		valor1=(-b+sqrt(raiz))/2*a;
		valor2=(-b-sqrt(raiz))/2*a;
		printf("X=%.2f ou X=%.2f",valor1,valor2);	
 }else {
 
 	printf("Nao existe raizes negativas");
}

}

