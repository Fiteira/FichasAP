#include<stdio.h>

typedef struct fracao{
	
	int numerador;
	int denominador;

}FRACAO;


main(){

	FRACAO num1,num2;
	char operacao;
	float fracao1,fracao2,soma,sub,divisao,multi;
	
	
	printf("Escreva o 1 numerador e 1 denominador-");
	scanf("%d %d",&num1.numerador,&num1.denominador);
	
	printf("\nEscreva o 2 numerador e 2 denominador-");
	scanf("%d %d",&num2.numerador,&num2.denominador);

	fracao1=(num1.numerador/num1.denominador);
	fracao2=(num2.numerador/num2.denominador);
	
	
	printf("Operacoes '+','-','/','*'");
	scanf("%c",&operacao);
	
	switch(operacao)
	{
	case '+': 
	soma=fracao1+fracao2;
	printf("A soma das fracao e %f",soma);
	break;
	
	case '-': 
	sub=fracao1-fracao2;
	printf("A subtracao das fracao e %f",sub);
	break;

	case '/':
	divisao=fracao1/fracao2;
	printf("A divisao das fracao e %f",divisao);
	break;
	
	case '*':
	multi=fracao1*fracao2;
	printf("A divisao das fracao e %f",multi);
	break;	
	
	default:
		printf("Operacao invalida");
}
}
	
	

	


