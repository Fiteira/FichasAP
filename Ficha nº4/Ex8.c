#include <stdio.h>
#include <locale.h>
#define MAXL 20


	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i,j;
    char asterisco='*';
    do{
    printf("Qual o valor de n");
    printf(" sem exceder %d:",MAXL);
	scanf("%d",&n);	
	}while(n>MAXL);
	for(i=1;i<=n;i++){
	
		for(j=1;j<=MAXL-1;j++)
		printf(" ");
		for(j=1;j<=i;j++)
		printf("%2c",asterisco);
		printf("\n");
		
	}
	return 0;
	}
    
