/*
#include <stdio.h>
#include<string.h>


#define MAX_V 20
typedef struct caract
{
float percAlc; // % de alcool
short cor; // 1-tinto; 2-branco, 3-ros�; 4-ruby;
char tpVinho; // M-mesa, G-generoso, E-Espumante, C-Champanhe
char nome[50];
}CARACT;

typedef struct garrafa
{
int ano;
CARACT def;
float preco;
}GARRAFA


void leGarr(GARRAFA *g, int numero_garrafas)
{
	int posicao;
		for(posicao=0; posicao<numero_garrafas; posicao++)
			{
				printf("Insira os seguintes dados acerca da garrafa:\nAno: ");
				fflush(stdin);
				scanf("%d",&g[posicao].ano);
				printf("\nPercentagem de alcool: ");
				fflush(stdin);
				scanf("%f",&g[posicao].def.percAlc);
				printf("\nCor, 1-tinto; 2-branco, 3-ros�; 4-ruby: ");
				fflush(stdin);
				scanf("%d",&g[posicao].def.cor);
				printf("\nTipo de vinho, M-mesa, G-generoso, E-espumante, C-champanhe: ");
				fflush(stdin);
				scanf("%c",&g[posicao].def.tpVinho);
				printf("\nNome do vinho: ");
				fflush(stdin);
				gets(g[posicao].def.nome);
				printf("\nPreco: ");
				fflush(stdin);
				scanf("%f",&g[posicao].preco);
			}
}

void escreveGarr(GARRAFA *g, int numero_garrafas)
{
	int posicao;
		for(posicao=0; posicao<numero_garrafas; posicao++)
			{
				printf("\nA garrafa na posicao %d tem as seguintes caracteristicas: ", posicao+1);
				printf("\nAno: ");
				printf("%d",g[posicao].ano);
				printf("\nPercentagem de alcool: ");
				printf("%f",g[posicao].def.percAlc);
				printf("\nCor, 1-tinto; 2-branco, 3-ros�; 4-ruby: ");
				printf("%d",g[posicao].def.cor);
				printf("\nTipo de vinho, M-mesa, G-generoso, E-espumante, C-champanhe: ");
				printf("%c",g[posicao].def.tpVinho);
				printf("\nNome do vinho: ");
				printf("%s",g[posicao].def.nome);
				printf("\nPreco: ");
				printf("%f",g[posicao].preco);
			}
}

void minMaxGarrafeira(GARRAFA *g, int numero_garrafas, float* val_min, float* val_max)
{
	int posicao;
	float max=g[0].preco, min=g[0].preco;
	
		for(posicao=0; posicao<numero_garrafas; posicao++)
				if(g[posicao].preco>=max)
					max=g[posicao].preco;
				else
					min=g[posicao].preco;
	*val_min=min;
	*val_max=max;
}

void precMarcaGVelha(GARRAFA *g, int numero_garrafas, float* preco, char *nome)
{
	int posicao;
	GARRAFA velha;
	velha.ano=g[0].ano;
	strcpy(nome, g[0].def.nome);
		for(posicao=0; posicao<numero_garrafas; posicao++)
			{
				if(g[posicao].ano<=velha.ano)
				{
					velha=g[posicao];
					strcpy(nome, g[posicao].def.nome);
				}
			}
	*preco=velha.preco;
}

void main()
{
	int numero_garrafas;
	float valor_min, valor_max, precoGVelha;
	float *ptr_min=&valor_min, *ptr_max=&valor_max, *ptr_precoGVelha=&precoGVelha;
	char nomeGVelha[50];
	GARRAFA garrafeira[MAX_V];
	
	printf("Qual o numero de garrafas a considerar na garrafeira?");
	scanf("%d", &numero_garrafas);
	leGarr(garrafeira, numero_garrafas);
	escreveGarr(garrafeira, numero_garrafas);
	minMaxGarrafeira(garrafeira, numero_garrafas, ptr_min, ptr_max);
	printf("\nValor min: %f", valor_min);
	printf("\nValor max: %f", valor_max);
	precMarcaGVelha(garrafeira, numero_garrafas, ptr_precoGVelha, nomeGVelha);
	printf("\nO preco da garrafa mais velha e: %f", precoGVelha);
	printf("\n");
	puts(nomeGVelha);
}
*/
//Exerc�cio 5
#define MAX 15

typedef struct dvd
{
	char titulo[50];
	char atores_principais[MAX];
	char produtor[50];
	int ano;
	float preco;
	char tipo;
}DVD;




