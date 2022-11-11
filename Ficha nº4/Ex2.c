#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int i,j,p,continua;
    for(i=2;i<=10;i++){
    
    printf("\n\nPara continuar degite 1:");
    scanf("%d" ,&continua);
	if(continua == 1){
	
		for(j=1;j<11;j++){
    	p=i*j;
    	printf("\n %d x %d = %d ",j,i,p);	
		}
   }else{
   	 printf("\nPara continuar degite 1:");	
   }
   
	}
	
	return 0;
}

