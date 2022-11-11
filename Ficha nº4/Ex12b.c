#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int i=0;
    float x,soma=0,media;
    
	do{
		{
		printf("\n Qual o valor %dº: ",i+1);
    	scanf("%f",&x);
		if(x>=0){
			i++;
			soma=soma+x;
		}}
		
	}while(x>=0);        
    media=soma/i;
	printf("A media dos %d é %.2f",i,media);

	return 0;

}
    

	
