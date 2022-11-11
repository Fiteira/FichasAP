#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int n,i;
    float x,soma=0,media;
    printf("Qual o valor de n:");
    scanf("%d",&n);
        
	for(i=1;i<=n;i++){
	
	printf("\n Qual o valor %dº: ",i);
    scanf("%f",&x);
    
        soma+=x;

    }
    
    media=(soma/n);
    printf("A media dos %d é %.2f",n,media);


	
	return 0;

}
