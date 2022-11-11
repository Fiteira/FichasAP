#include <stdio.h>
#include <locale.h>

	void main(){
		
		int mes,dia,ano,dias;
		
		printf("Introduza um dia, mes e ano:\n");
		scanf("%d" "%d" "%d", &dia , &mes ,&ano);
	

		
		switch (mes){
			case 1:
				dias=31-dia;
		   		printf("%d", dias);
			break;
		
			case 2:	
		 		if(ano%4 == 0 && ano%100!=0){
       				dias=29-dia;
       				printf("%d",dias);
       				
      			  }else(ano%400 == 0){
					dias=29-dia;
       				printf("%d",dias);
       				
					}
        		else{
         			dias=28-dia;
       				printf("%d",dias);
	   			}
        	break;
        	case 3:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
			case 4:
        		dias=30-dia;
		   		printf("%d",dias);
			break;
			case 5:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
			case 6:
        		dias=30-dia;
		   		printf("%d",dias);
			break;
			case 7:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
			case 8:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
			case 9:
        		dias=30-dia;
		   		printf("%d",dias);
			break;
			case 10:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
			case 11:
        		dias=30-dia;
		   		printf("%d",dias);
			break;
			case 12:
        		dias=31-dia;
		   		printf("%d",dias);
			break;
    }
	}
