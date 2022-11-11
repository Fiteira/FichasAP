#include <stdio.h>
#include <locale.h>

	void main(){
		setlocale(LC_ALL, "Portuguese");
		
		char caracter;
		
		printf("Introduza um caracter: ");
	    scanf("%c",&caracter);
	    
	    if(caracter>='a' && caracter<='z'){
		
       	 printf("O caracter é letra minúscula");
   		}else if(caracter>='A' && caracter<='Z'){
		   
       	 printf("O caracter é letra Maiúscula");
    	}
		else if(caracter>='0' && caracter<='9'){
			
		 printf("O caracter é um numero");
		 }else if(caracter=='!' || caracter=='.' || caracter==',' || caracter==';' || caracter=='?'){
	
		 printf("É um caracter de pontuação");
	
	
		 }
	
		
	
	
	
}
