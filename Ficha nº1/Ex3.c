#include<stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int a,b,c,maior;
	
	printf("Introduza 1�:");
	scanf("%d",&a);
	printf("Introduza 2�:");
	scanf("%d",&b);
	printf("Introduza 3�:");
	scanf("%d",&c);
	
	if(a>b){
	
		maior=a;	
	}
	else {
	
		maior=b;	
	}
	if(c>maior){
		maior=c;
	}
		
	printf("o n� maior � %d",maior);

}
