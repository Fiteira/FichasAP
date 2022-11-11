#include<stdio.h>
#define MAX 4


void ler(int n, int x[MAX][MAX]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		printf("elementos [%d] [%d] do vetor ",i+1, j+1);
		scanf("%d",&x[i][j]);
		}
	}
	
}

void escrever(int n,int x[MAX][MAX]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		printf("%d\t",x[i][j]);
		}
		printf("\n");
	}
}
int minimo(int n,int x[MAX][MAX]){
	int i,j;
	int menor[0][0];
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			if(x[i][j]<menor[0][0]){
			menor[0][0]= x[i][j];
				
			}	
		}
	}
return menor;
}
	


main(){
	int v[MAX][MAX],n;
	
	do{
		printf("Numero nxn do vetor deve ser <=4x4 ");
		scanf("%d",&n);
	}while(n<1||n>4);
	ler(n,v);
	escrever(n,v);
	minimo(n,v);
		printf("O valor minimo é %d ",mininmo(n,v));
			
	}
	
	

