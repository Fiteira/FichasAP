#include <stdio.h>
#include <locale.h>
#include <math.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i,soma=0,total=0,f=1,j;
    printf("Qual o valor de n:");
    scanf("%d",&n);




        for(i=1;i<=n;i++){

        f=f*i;

        soma=soma+pow(2,i)/f;
    }
    printf("soma=%d",soma);


	
	return 0;

}
