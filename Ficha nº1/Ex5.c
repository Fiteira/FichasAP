#include <stdio.h>
#include <locale.h>

	void main(){
		setlocale(LC_ALL, "Portuguese");
		
		char caracter;
		
		printf("Introduza um caracter: ");
	    scanf("%c",&caracter);
	    
	    if(caracter>='a' && caracter<='z'){
		
       	 printf("O caracter � letra min�scula");
   		}else if(caracter>='A' && caracter<='Z'){
		   
       	 printf("O caracter � letra Mai�scula");
    	}
		else if(caracter>='0' && caracter<='9'){
			
		 printf("O caracter � um numero");
		 }else if(caracter=='!' || caracter=='.' || caracter==',' || caracter==';' || caracter=='?'){
	
		 printf("� um caracter de pontua��o");
	
	
		 }
	
		
	
	
	
}
