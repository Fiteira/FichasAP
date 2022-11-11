#include<stdio.h>
#include <locale.h>

#include <time.h> // para usar gettimeofday
#include <sys/time.h> 

int leituraInteiro(){
// leirtura de um inteiro nao negativo(n>=0)
int n;

	do{
		printf("valor de n: ");
		scanf("%d",&n);
	}while(n<0);
	
	return n;
	
}

int fibonacci(int n){ //alinea a)
// versao recursiva simples
	if (n==0 || n==1)
		return n; // criterio de paragem (regra base)
	else
		return (fibonacci(n-2)+fibonacci(n-1)); // criterio de paragem (regra recursiva)
		
}


int fibonacci_i(int n){ //alinea b)
// versao iterativa (a - termo n-2; b- termo n-1; c - termo n)

	int a,b,c;
	a=0; //n=0 
	b=1; //n=1
	c=0;
	int i;
		
	for(i=2; i<=n; i++){
		
		c=a+b;
		a=b;
		b=c;	
	}

  return c;
}


int fibonacci_pro(int i,int v[]){ //alinea c)
	
// versao recursiva melhorada (usa um vetor para guardar os numeros fibonacci calculados)
	if (i==0)
		v[0]=0;
	if(i==1)
		v[1]=1;	
		else if(i>1)
			{
				if (v[i-2] == -1)
					v[i-2] == fibonacci_pro(i-2,v);
				if (v[i-1] == -1)
					v[i-1] == fibonacci_pro(i-1,v);
		  	    v[i]=v[i-2] + v[i-1];
			}
		
	return v[i];
}


void main(){
	int m;
	int i;
	int v[100];
	
	struct timeval t1, t2; // tempos de inicio e fim
	double elapsedTime;
	
	m=leituraInteiro();
	
	// inicializacao do vetor para guardar os numeros de fibonacci
	for (i=0;i<m;i++)
		v[i]=-1;
	
	
	// iniciar o cronometro
 	gettimeofday(&t1, NULL);
	
	printf("Recirsova simples: f(%d)= %d",m,fibonacci(m));
	
	// finalizar o cronometro
	gettimeofday(&t2, NULL);
	
	// Calcular e mostrar o tempo decorrido em milisegundos
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; //s para ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; //us para ms

	printf("O tempo(ms) %f",elapsedTime);
	
	//Versao Iterativa--------------------------
	// iniciar o cronometro
 	gettimeofday(&t1, NULL);
	
	printf("\n\nVersao Iterativa: f(%d)= %d",m,fibonacci_i(m));
	
	// finalizar o cronometro
	gettimeofday(&t2, NULL);
	
	// Calcular e mostrar o tempo decorrido em milisegundos
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; //s para ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; //us para ms

	printf("O tempo (ms) %f",elapsedTime);
	
	
	
	//Versao recursiva melhorada--------------------------
	// iniciar o cronometro
 	gettimeofday(&t1, NULL);
	
	printf("\n\nVersao recursiva melhorada: f(%d)= %d",m,fibonacci_pro(m,v));
	
	// finalizar o cronometro
	gettimeofday(&t2, NULL);
	
	// Calcular e mostrar o tempo decorrido em milisegundos
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; //s para ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; //us para ms

	printf("O tempo (ms) %f",elapsedTime);
	
}


