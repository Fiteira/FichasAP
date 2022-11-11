#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i,p;
    printf("um número inteiro i: ");
    scanf("%d",&n);
    for(i=1;i<11;i++){
    
	p=i*n;
	printf("\n %di x %d = %di",n,i,p);	
    	
    	
	}
	
	return 0;
}

