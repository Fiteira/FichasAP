#include <stdio.h>
#include <locale.h>

	void main(){
    int a,min,hora;
	printf("Introduza um numero de minutos:\n");
	scanf("%d", &a);

	if(a<1440){
    hora= a/60;
    min= a%60;
    printf("%d:%d",hora,min);
 }else {
 
 	printf("Um dia nao tem mais de 1440 minutos");
}

}

