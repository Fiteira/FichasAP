#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,p=0,par=0;
    
    
	printf("Qual o seu valor de n: ");
    scanf("%d",&n);
    
			
	while(p<n){
	   	par=par+2;
	   	p=p + par;
	
	}
	printf("O maior numero par: %d",par-2);
	
	return 0;
}
