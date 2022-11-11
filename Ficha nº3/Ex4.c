#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n;
    
    do{
	
	printf("Introduzir um número entre 0 e 9: ");
    scanf("%d",&n);
    
			
	}while(n<0||n>9);
	printf("O numero foi %d",n);
	
	
	
	return 0;
}
