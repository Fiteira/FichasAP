#include<stdio.h>
#define MAX 20


void ler(int n, int *x){
	int i;
	for(i=0;i<n;i++){
		printf("elementos [%d] do vetor ",i+1);
		scanf("%d",&x[i]);		
	}
	
}

void escrever(int n,int *x){
	int i;
	for(i=0;i<n;i++){
		
		printf("elementos [%d] ",i+1);
		printf("%d\n",x[i]);	
	}
}

void escreverI(int n,int *x){
		int i;
		printf("\n");
		for(i=n-1;i>=0;i--){
		printf("elementosI [%d] ",i+1);
		printf("%d\n",x[i]);	
	}
	
}

void max(int n,int *x){
	int i,max,pos;
	pos=0;
	for(i=1;i<n;i++){
		if(x[i]>x[pos]){
		pos=i;
		}
	}
printf("O maximo e %d", x[pos]);
}

void min(int n,int *x){
	int i,min,pos;
	pos=0;
	for(i=1;i<n;i++){
		if(x[i]<x[pos]){
		pos=i;
		}
	}
printf("\nO minimo e %d", x[pos]);
}


float soma(int n,int *x){
	
	int i;
	float soma=0;
	for(i=0;i<n;i++){
	soma=soma + x[i];
	}
	return soma;	
}

float media(int n,int *x){
	
	int i;
	float soma=0;
	float media=0;
	for(i=0;i<n;i++){
	soma=soma + x[i];
	}
	media=soma/n;
	return media;	
}



main(){
	int v[MAX],n;
	float num_soma,num_media;
	do{
		printf("Quantos elementos vai ter o vetor (MAX 20)");
		scanf("%d",&n);
	}while(n<1||n>20);
	ler(n,v);
	
	escrever(n,v);
	
	escreverI(n,v);
	
	max(n,v);
	min(n,v);
	
	num_soma=soma(n,&v);
	printf("\nA soma e %.2f",num_soma);
	
	num_media=media(n,&v);
	printf("\nA soma e %.2f",num_media);
	
	
	}
	

