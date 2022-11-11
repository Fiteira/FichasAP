#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 50

int tamanhoByte(FILE *f)
{
	int pos;
	pos=ftell(f); //posicao do ficheiro (quando e abreto o ficheiro a posicao e zero)
	fseek(f,0,2);	//envia o ponteiro para o fim do ficheiro(seek_end ou 2)
	pos=ftell(f);
	fseek(f,pos,SEEK_CUR); //recolocar o ponteiro na posicao em que estava(SEEK_CUR ou 1)
	
	return pos;
}

main(){

FILE *f;
char nome[MAX];

printf("Introduza o nome do ficheiro: ");
fflush(stdin);
gets(nome);

f=fopen(nome, "r");

if (f==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	//mostrarErro();
	}else{
   	 printf("O ficheiro %s tem %d bytes\n",nome, tamanhoByte(f));
	 
	fclose(f);	
	}	
}
