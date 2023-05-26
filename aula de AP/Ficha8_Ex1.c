# include <stdio.h>
# include<locale.h>
# include <stdlib.h>

typedef int tipo_dados;

//-----------------------------------------------------
tipo_dados *alocarMatriz (int nl, int nc)
//Aloca a memória necessária para armazenar uma matriz
{
	tipo_dados *ptr;
	ptr=(tipo_dados *)malloc(nl*nc*sizeof(tipo_dados));
	if (ptr==NULL)
	{
		printf("Memória insuficiente");
		return NULL;	
	}
	else
		return ptr;	
}

//-----------------------------------------------------
void lerMatriz(tipo_dados *M, int nl, int nc)
{

	int i,j;
	for (i=0;i<nl;i++)
		for (j=0;j<nc;j++)
		{
			printf("Introduza o elemento da matriz na linha %d e coluna %d ",i+1,j+1);
			scanf("%d",M++);
		}
}
 
//----------------------------------------------------- 
void escreverMatriz(tipo_dados *M, int nl, int nc)
{

	int i,j;
	for (i=0;i<nl;i++)
		for (j=0;j<nc;j++)
			printf("\nElemento da matriz na posição %d,%d = %d",i+1,j+1,*(M++));
}
 
//----------------------------------------------------- 
int verificarSimetrica(tipo_dados *M, int nl, int nc)
{

	int i,j;
	if (nl!=nc)
		return 0;
	for (i=1;i<nl;i++)
		for (j=0;j<i;j++)
			if (*(M+i*nc+j)!=*(M+j*nl+i))
				return 0;
	return 1;			
} 
 
//----------------------------------------------------- 
int calcularTraco(tipo_dados *M, int nl, int nc)
// Soma dos elementos da diagonal principal de uma matriz
{

	int i,t;
	if (nl!=nc)
	{
		printf("\n\nA matriz tem de ser quadrada!");
		return 0;
	}
	else
	{
		t=0;
		for (i=0;i<nl;i++)
			t+=*(M+i*nc+i);     // acesso aos elementos da diagonal principal
	}
	return t;			
} 


//----------------------------------------------------- 
void calcularProduto1(tipo_dados *A, tipo_dados *B, tipo_dados *C, int nlA, int ncA,int ncB)
//C=A*B  (numero colunas de A = numero linhas de B)
{
	int i,j,k;
	for (i=0;i<nlA;i++)
		for (j=0;j<ncB;j++)
		{
			*C=0;                  
			for (k=0;k<ncA;k++) 
				*C+=*(A+i*ncA+k)* *(B+k*ncB+j); 
			C++;	   		
		}
				
} 

//----------------------------------------------------- 
void calcularProduto2(tipo_dados *A, tipo_dados *B, tipo_dados *C, int nlA, int ncA,int ncB)
//C=A*B  (numero colunas de A = numero linhas de B)
{
	int i ,j,k;
	for (i=0;i<nlA;i++)
		for (j=0;j<ncB;j++)
		{
			*(C+i*ncB+j)=0;
			for (k=0;k<ncA;k++) 
				*(C+i*ncB+j)+=*(A+i*ncA+k)* *(B+k*ncB+j); 
		}
				
} 


//-----------------------------------------------------
void main()
{
	setlocale(LC_ALL, "Portuguese");//Dicionário de português
	tipo_dados *A, *B, *C;
	int m,n,traco,p;
	do
	{
		printf("Número de linhas da matriz A: ");
		scanf("%d",&m);
	}while(m<=0);
	do
	{
		printf("Número de colunas da matriz A: ");
		scanf("%d",&n);
	}while(n<=0);
	A=alocarMatriz(m,n);              // alinea a	
	lerMatriz(A,m,n);                 // alinea b
	escreverMatriz(A,m,n);            //alinea c
	
	if (verificarSimetrica(A,m,n))    //alinea d
		printf("\n\nSimétrica!");
	else
		printf("\n\nNão é Simétrica!");
		
	traco=calcularTraco(A,m,n);
	if (m==n)
		printf("\n\nTraço= %d",traco);	

    // Matriz B  (número de linhas de B = numero colunas de A) - exercicio 2
    do
	{
		printf("\nNúmero de colunas da matriz B: ");
		scanf("%d",&p);
	}while(n<=0);
		
	B=alocarMatriz(n,p);              
	lerMatriz(B,n,p);  
	
	C=alocarMatriz(m,p); 
	calcularProduto2(A,B,C,m,n,p);
	escreverMatriz(C,m,p);            
		
	free(A);
	free(B);
	free(C);

}
