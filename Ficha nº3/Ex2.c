#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int ni,nf,par;
    
    printf("O 1�numero tem que ser menor que 2�numero \n");
    
	printf("Qual o seu 1� numero: ");
    scanf("%d",&ni);
    
    printf("\n Qual o seu 2� numero: ");
    scanf("%d",&nf);
    
    if(ni<nf){
	
	if(ni%2){
		par=ni+1;
		}else
		par=ni;	
   	printf("Os pares entre %d e %d sao:\n",ni,nf);
	while(par<=nf){
		printf("\t%d\n",par);
		par+=2;
	}
	}else{
		printf("O %d e maior ou igual que %d",ni,nf);
	}
return 0;
}
