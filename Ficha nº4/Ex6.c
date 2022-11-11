#include <stdio.h>
#include <locale.h>


	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i,soma=0;
    printf("Qual o valor de n:");
    scanf("%d",&n);

        for(i=1;i<=n;i++){

        soma=soma+i;

        printf("\n -iteração %d,soma= %d", i,soma);
        }
    printf("\n Soma total=%d",soma);


	
	return 0;

}
