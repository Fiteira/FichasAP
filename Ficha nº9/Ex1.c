#include <stdio.h>
#define FILEMODE_w "w"
#include <string.h>
/*
main(){
	
char string[50];


FILE *f;
char *nome="dados.txt";
if ((f=fopen(nome, "w"))==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	//mostrarErro();
	}else{
	do{
		printf("Escreva uma string quando escrever um '.' termina o programa\n");
		fseek(stdin,0,2);
		gets(string);
		if ((".",string)){
			fputs(string,f);
			//fputs('\n',f);
			fflush(f);	//descarrega no ficheiro
		}
		
	}while(strcmp(".",string));//strcmp devolve e quando as strings sao iguais
	fclose(f);	
	}


}
*/

main(){
	char str[30];
	FILE *f;
	f=fopen("testo.txt","w+");
		do
		{
			printf("Estreva uma testo: ");
			fflush(stdin);
			gets(str);
			if(strcmp(str,".")!=0);
			fprintf(f,"s",str);
		} while (strcmp(str,".")!=0);
		
}