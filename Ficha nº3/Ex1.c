#include <stdio.h>
#include <locale.h>

	int main(){
    int numero,multiplos;
    
    printf("Qual o seu numero: ");
    scanf("%d",&numero);
    
    multiplos=numero;
    
    while(multiplos<100){
    	
    	printf("%d\n",multiplos);
    	multiplos=multiplos+numero;
	}
return 0;
}
