#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    float n;
    
    
	
 do{
	
	printf("Introduzir um número entre 10 e 15.5: ");
    scanf("%f",&n);
    
			
	}while(n<10||n>15.5);
	printf("O numero foi %.1f",n);
	
	
	
	
	
	return 0;
}

