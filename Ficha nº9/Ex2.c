#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 50

void mostrarErro(){
	fprintf(stderr,"Impossivel abrir o ficheiro");
	fprintf(stderr,"Codigo do erro %d", errno);
	perror("Descricao do erro");
	
}


main(){
	
char str[MAX];
FILE *f;
char *string;
if ((f=fopen("dados.txt", "r"))==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	//mostrarErro();
	}else{
	while (!feof(f)){
    	fgets(str, MAX, f);
    	printf("%s ",str);
	 }	
	fclose(f);	
	}
	

}
