#include<stdio.h>
#include <locale.h>

int main() {
	float base;
	float altura;
	float area;

 	printf("Introduza a base:");
	scanf("%f",&base);
	
	printf("Introduza a altura:");
	scanf("%f",&altura);
	
	area=(base*altura)/2;
	
	printf("Area= %0.2f",area);
 
}
