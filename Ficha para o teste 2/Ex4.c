#include<stdio.h>
#define MAX_V 20


typedef struct caract{
 float percAlc; 
 short cor; 
 char tpVinho; 
 char nome[50];
}CARACT;

typedef struct garrafa
{
 int ano;
 CARACT def;
 float preco;
}GARRAFA;

void lerGarr(GARRAFA *ptr,int n){
	int i;
	for (i=0;i<n;i++){
	printf("\nGarrafa %d: ",i+1);
	printf("\nAno: ");
	scanf("%d",&(ptr+i)->ano);
	
	printf("\n Percentagem de alcool: ");
	scanf("%d",&(ptr+i)->def.percAlc);
	
	printf("\nCor do Vinho(1-tinto; 2-branco, 3-rosé; 4-ruby;): ");
	scanf("%d",&(ptr+i)->def.cor);
	
	printf("\n Tipo de vinho(M-mesa, G-generoso, E-Espumante, C-Champanhe): ");
	fflush(stdin);
	gets((ptr+i)->def.tpVinho);
		
	printf("\nNome: ");
	fflush(stdin);
	gets((ptr+i)->def.nome);
	
	printf("\npreco: ");
	scanf("%f",&(ptr+i)->preco);
  }	
}

void minMaxGarrafeira(GARRAFA *ptr,int n,float *min,float *max){
	int i;
	*min=ptr->preco;
	*max=ptr->preco;
	
	for (i=1;i<n;i++){
		if(ptr[i].preco<*min)
			*min=ptr[i].preco;
	}
	for (i=1;i<n;i++){
		if(ptr[i].preco>*max)
			*max=ptr[i].preco;
	}
}

void marcaGVelha(GARRAFA *ptr,int n,float *preco,char *marca){
	int i, anoMin=0;
	anoMin=ptr->ano;
	strcpy(marca, ptr->def.nome);
	*preco=ptr->preco;

	for(i=1;i<n;i++){
		if(ptr[i].ano < anoMin){
			anoMin=(ptr+i)->ano;
			strcpy(marca, (ptr+i)->def.nome);
			*preco=(ptr+i)->preco;
		}
	}
	
}

main(){
	GARRAFA garrafeira[MAX_V];
	int n,antiga;
	float max,min,preco;
	char marca;
	
	do{
		printf("Numero de garrafas(MAX 20)");
		scanf("%d",&n);
	}while(n<1||n>20);	
	
	lerGarr(garrafeira,n);
	minMaxGarrafeira(garrafeira,n,&min,&max);
	printf("\nPreco maximo:%.2f ,preco minimo:%.2f",max,min);
	
	marcaGVelha(garrafeira,n,&preco,marca);
	printf("\nA marca:%c com um preco de:%.2f ",marca,preco);


	
}
