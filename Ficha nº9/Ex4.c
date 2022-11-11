#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include<stdio.h>
#include<stdlib.h>

typedef struct livro
{
	char titulo[30];
	char autor[30];
	char area[20];
	int ano;
	int ocupado;
}LIVRO;

void iniciarLivro(LIVRO *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		(*p).ocupado = 0;//p->ocupado=0;
		p++;
	}
}

void removerLivro(LIVRO *p, int n)
{
	int i;
	do
	{
		printf("\nQual o indice a remover? ");
		scanf("%d", &i);
	} while ((i < 0) || (i >= n));
	//p aponta para 1º elemento, ?ndice 0
	//p+i avança i casas, para índice i
	(p + i)->ocupado = 0;//(*(p + i)).ocupado = 0;
}

void inserirLivro(LIVRO *p, int n)
{
	//p aponta para 1º posição
	int i;
	i = 0;
	while ((p->ocupado != 0) && (i < n))
	{
		p++; i++;
	}
	if (i < n)//não percorri o vetor todo; encontrei ocup=0
	{
		//p aponta p posicao com ocup=0
		p->ocupado = 1;
		fseek(stdin, 0, 2);// fflush(stdin);
		printf("\nTitulo: ");
		gets(p->titulo);
		printf("\nAutor: ");
		gets(p->autor);
		printf("\nArea: ");
		gets(p->area);
		printf("\nAno: ");
		scanf("%d", &(p->ano));//scanf("%d",&(*p).ano);
	}
	else
		printf("\nVetor cheio!!\n");
}

void listarLivros(LIVRO *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (p->ocupado != 0)
		{
			printf("\nTitulo: %s", p->titulo);
			printf("\nAutor: %s", p->autor);
			printf("\nArea: %s", p->area);
			printf("\nAno: %d\n\n", p->ano);
		}
		p++;
	}
}


void gravarLivrosBin(int n,LIVRO *p){

FILE *f;
f=fopen("livros.dat", "wb"); //gravar em ficheiro binario

if (f==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	}else{
   	
   	fwrite(p,sizeof(LIVRO),n,f);	//grava todo o vetor no ficheiro binario
   	
	fclose(f);	
	}
}

void gravarLivrosBinOcup(int n,LIVRO *p){

FILE *f;
f=fopen("livrosOcup.dat", "wb"); //gravar em ficheiro binario
int i;

if (f==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	}else{
   	for (i=0;i<n;i++){
	   if((p+i)->ocupado)
   		fwrite(p+i,sizeof(LIVRO),1,f);	//grava cada elemento do vetor no ficheiro binario
	fclose(f);	
	}
}}


void lerLivrosBinOcup(LIVRO *p){

FILE *f;
f=fopen("livrosOcup.dat", "rb"); //gravar em ficheiro binario

if (f==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
}else{
   	  while(!feof(f)){	 
			fread(p,sizeof(LIVRO),1,f);	//le cada elemento do vetor no ficheiro binario
		p++;
	}  
}
	fclose(f);	
	}



void lerLivrosBin(int n,LIVRO *p){

FILE *f;
f=fopen("livros.dat", "rb"); //ler em ficheiro binario

if (f==NULL){
	fprintf(stderr,"Nao e possivel abrir o ficheiro");
	}else{
   	
   	fread(p,sizeof(LIVRO),n,f);	//ler todo o vetor no ficheiro binario
	fclose(f);	
	}


}


//-------------------------------------------------------------------------------------

void main()
{
	LIVRO biblio[MAX];
	int op;
	iniciarLivro(biblio, MAX);
	do
	{
		printf("\n\n\tMENU****\n");
		printf("1 - Inserir novo livro\n");
		printf("2 - Remover livro\n");
		printf("3 - Listar livros\n");
		printf("4 - gravar livro fileBin\n");
		printf("5 - ler livro fileBin\n");
		printf("6 - gravar livro fileBin(registos ocupados)\n");
		printf("7 - ler livro fileBin(registos ocupados)\n");
		printf("8 - Sair\n");
		printf("\nDigite opcao: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:inserirLivro(biblio, MAX); break;
		case 2:removerLivro(biblio, MAX); break;
		case 3:listarLivros(biblio, MAX); break;
		case 4:gravarLivrosBin(MAX,biblio); break;
		case 5:lerLivrosBin(MAX,biblio); break;
		case 6:gravarLivrosBinOcup(MAX,biblio); break;
		case 7:lerLivrosBinOcup(biblio); break;
		case 8:printf("\nAdeus\n"); break;
		default:printf("\nOpcao invalida!\n\n"); break;
		}
		system("pause");
	} while (op != 8);

}
