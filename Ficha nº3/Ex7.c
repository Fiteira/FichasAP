#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,m,multiplos;
    
    printf("Qual o seu numero: ");
    scanf("%d",&m);
    
	printf("Qual o n 1º multiplos: ");
    scanf("%d",&n);
    
	
	multiplos=m;
    
    while(multiplos<n){
    	
    	printf("%d\n",multiplos);
    	multiplos=multiplos+m;

	}
	
	
	return 0;
}

