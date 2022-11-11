#include<stdio.h>
#include<math.h>

typedef struct coordenadas{
	
	float x;
	float y;

}COORDENADAS;

main(){
	COORDENADAS p1,p2;
	float comp,altura,area,comp_diag,h;
	printf("Escreva as coordenadas do ponto 1- ");
	scanf("%f %f",&p1.x,&p1.y);
	
	printf("Escreva as coordenadas do ponto 2- ");
	scanf("%f %f",&p2.x,&p2.y);
	
	comp=p2.x-p1.x;
	altura=p2.y-p1.y;
	
	area=comp*altura;
	printf("Area=%.2f",area);
	
	h=pow(comp, 2)+pow(altura, 2);
	comp_diag=sqrt(h);
	printf("\nO comprimento da diagonal =%.2f",comp_diag);
	
	
}
