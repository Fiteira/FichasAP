/*#include<stdio.h>
main(){  
    int x,y;  
    x=y=2;  
    printf("x=%d e y=%d\n",++x,y--);  
    printf("x=%d e y=%d\n",x,y);
}
---------------------------------------------------------------------
#include<stdio.h>

int maior(int x,int y);
int lerInteiro();

main(){  
    
    int x1,m;
    m=-9999;
    x1=lerInteiro();
        while (x1!=9999)
        {
            m=maior(m,x1);
            x1=lerInteiro();
        }
        printf("\n O maior e=%d",m);
}

int lerInteiro()
{
    int x;
    printf("introduza um numero: ");
    scanf("%d",&x);
    return x;
}
int maior(int x,int y)
{
    if(x>y)
        return x;
    else 
        return y;
}
---------------------------------------------------------------------
#include<stdio.h>
main(){

    printf("\nsizeof(char) 1: %d",sizeof(char));
    printf("\nsizeof(short) 2: %d",sizeof(short));
    printf("\nsizeof(int) 4: %d",sizeof(int));
    printf("\nsizeof(long) 4: %d",sizeof(long));
    printf("\nsizeof(long long) 8: %d",sizeof(long long));
    printf("\nsizeof(float) 4: %d",sizeof(float));
    printf("\nsizeof(double) 8: %d",sizeof(double));
    printf("\nsizeof(long double) 16: %d",sizeof(long double));

}

#include <stdio.h>
main(){
    int n,soma;
    soma=0;
    printf("Introduza um numero: ");
    scanf("%d",&n);

    for (int i=1; i<=n; i++){
        soma+=i;
        printf("\nadicionar %d, parcial %d", i, soma);
    }
    printf("\nTotal: %d",soma);
}
---------------------------------------------------------------------
#include <stdio.h>
main(){
    int hora,min,seg;

    
        printf("Hora: ");
        scanf("%d",&hora);
        printf("Minuto: ");
        scanf("%d",&min);
        printf("Segundos: ");
        scanf("%d",&seg);

    
    
    seg=(hora*60*60)+(min*60)+seg;
    printf("Numero de segundos desde o inicio do dia: %d",seg);

}
#include <stdio.h>
main(){
    int n,prod;
    prod=1;
    printf("Introduza um numero: ");
    scanf("%d",&n);

    for (int i=1; i<=n; i++){
         prod*=i;
        printf("\nFactorial (%d)= %d", i, prod);
    }
    printf("\nResultado: %d",prod);
}
---------------------------------------------------------------------
#include <stdio.h>
main(){
    int n,r,resl;
    resl=1;
    do
    {
        printf("\nIndique N: ");
        scanf("%d",&n);
        printf("\nIndique R: ");
        scanf("%d",&r);
        printf("O R tem de ser menor que N\n");
    } while (n<r);
        for (int i=n-r+1;i<=n; i++){
            resl=resl*i;
            printf("\ni=%d; arranjos=%d",i,resl);
            
        }
    printf("\nResultado: %d",resl);
}
-------------------------------------------------------------------------
#include <stdio.h>

main(){

    int divisor,n;
    printf("Funcao que verifica se um numero N e primo:\nIndique N:");
    scanf("%d",&n);

    divisor=2;
    while (divisor*divisor<n)
    {
        if(n%divisor == 0){
            printf("\n Numero divisivel por %d ",divisor);
            return;
        }
        printf("%d",divisor);
        divisor++;
    }
    printf("\n numero primo\n");
}
-----------------------------------------------
#include <stdio.h>
#include <string.h>

    
void inverte(char *str){
    int tam=strlen(str);
    int j=1;
        for (int i = 0; i < tam/2; i++)
        {
            char aux;
            aux=str[i];
            str[i]=str[tam-j];
            str[tam-j]=aux;
            j++;
            printf("\n%d: %s",i,str);
        }
    printf("\nTexto invertido: %s",str);
}

main(){
    char str[20];
    printf("Texto para inverter: ");
    fflush(stdin);
    gets(str);
    inverte(str);

}
------------------------------------------------
#include <stdio.h>

int find(int *v,int num){

    for (int i = 0; i < 1000; i++)
        if(v[i] == num)
            return i+1;

    return - 1;
}


main(){
    int v[1000];
        for (int i = 0; i < 1000; i++)
        {
            v[i]=rand()%10;
        }
        printf("Vector: ");
        for(int i=0; i<10;i++){
            printf("%d ",v[i]);
        }
        printf("\nPosicao de %d: %d",2,find(v,2));
}
----------------------------------------------------------------------------
#include <stdio.h>

int mdc(int x,int y){

    if( y == 0)
        return x;

    return mdc(y,x%y);
}

main(){

    int x,y,soma;

    printf("Indique x e y:");
    scanf("%d %d",&x,&y);
    printf("MDC: %d",mdc(x,y));

    soma=0;

    for (int i = 1; i < 100; i++)
    {
        for (int j = i+1; i <= 100; i++)
        {
            soma+=mdc(i,j);
        }
    }
    printf("\nA soma dos MDC dos numeros para de 1 ate 100: %d",soma);
}

-----------------------------------------------------------------

#include<stdio.h>
#include <stdlib.h>
typedef struct lista
{
   int valor;
   struct lista *seg;
}LISTA;


LISTA *adiciona(LISTA *lista,int valor){

    LISTA *m=(LISTA *) malloc(sizeof(LISTA));
    
    if(m== NULL){
        printf("Memoria insuficiente");
        return NULL;
    }else{
        m->valor=valor;
        m->seg=lista;
    }
    return m;
}
*/
/*
-------------------------------------------------------------------------------------------


#include<stdio.h>
#include<string.h>

int compararString(char str[20],char str2[20]){

    int s1,s2;

    s1=strlen(str);
    s2=strlen(str2);
    
    if(s1==s2)
        return 0;
    else if(s1>s2)
        return 1;
    else   
        return 2;
}


main(){

    char str[20],str2[20];
    printf("1-String: ");
    fflush(stdin);
    gets(str);
    printf("\n2-String: ");
    fflush(stdin);
    gets(str2);
    
    printf("Comparar String= %d",compararString(str,str2));

}
------------------------------------------------------------------------------

#include <stdio.h>
#define MAX 20

void escreverMatriz(int m[MAX][MAX],int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d]: ",i,j);
            scanf("%d",&m[i][j]);
        }
        
    }
    

}


void imprimirDiagonal(int m[MAX][MAX],int n){
     
     for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i == j)
                    printf("\n [%d][%d]: %d",i,j,m[i][j]);
            }
        
        }

}

int main(){
    int n;
    int m[MAX][MAX];

    printf("A matriz vai se de tamanho: ");
    scanf("%d",&n);
    escreverMatriz(m,n);
    imprimirDiagonal(m,n);


}




#include<stdio.h>

int misterio(int num){
    int x=0;
    while (num>0)
    {
        x=x + num % 10;
        num=num/10;
    }
    return x;
}
main(){

    int num;
    printf("Numero: ");
    scanf("%d",&num);
    printf("\n x= %d",misterio(num));


}
--------------------------------------------------------------
#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    int numero;
    char nome[20];
    int nota_tp;
    int nota_teste;
    char i[4];
}ALUNO;

ALUNO *alocarAluno(int n){

    ALUNO *p=(ALUNO*)malloc(n*sizeof(ALUNO));
        if (p==NULL)
        {
            printf("Nao tem memoria suficiente!");
            return NULL;
        }else
            return p;

}

void adicionarAluno(ALUNO *p,int n){

    for (int i = 0; i < n; i++)
    {
        printf("\n numero do %d",i+1);
        scanf("%d",&p[i].numero);
        printf("\n nota_tp: ");
        scanf("%d",&p[i].nota_tp);
        printf("\n nota_test: ");
        scanf("%d",&p[i].nota_teste);

        do
        {
        printf("\n O aluno quer incluir a nota_tp (sim/nao)?");
        fflush(stdin);\
        gets(p[i].i);
        } while ((strcmp("sim",p[i].i))!=0 && (strcmp("nao",p[i].i))!=0 );    
    }
}    

void notaFinal(ALUNO *p,int n){
    int nota_final;
    for (int i = 0; i < n; i++)
    {
        if(strcmp("sim",p[i].i) == 0){
            nota_final=0.20*p[i].nota_tp + 0.80*p[i].nota_teste;

        }else{
            nota_final=p[i].nota_teste;
        }
        printf("\nA nota do aluno n-%d: %d",p[i].numero,nota_final);
    }
}
main(){
    int n;
    printf("\nQuantos alunos tem: ");
    scanf("%d",&n);

    ALUNO *alunos;
    alunos=alocarAluno(n); 
    adicionarAluno(alunos,n);
    notaFinal(alunos,n);
}




-----------------------------------------------------------------------------

#include<stdio.h>

char rodar_letra(char ch){

    int num;
    num=ch;
        if(num== 90){
            return 'A';
        }else if(num==122){
            return 'a';
        }else{
            num=num+1;
            return num;
        }
}




main(){
    char ch;
    
    do
    {
    printf("\nUma letra: ");
    scanf(" %c",&ch);
    } while (('A' < ch > 'Z') || ('a' < ch > 'z'));
   
    printf("\nA letra seguinte e: %c",rodar_letra(ch));

}





----------------------------------------------------------------------------------------------------

#include <stdio.h>

void bubblesort(int vec[],int n){

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int aux;
                if(vec[i]>vec[j]){
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }


        } 
 
 
    }   



}




main(){

    int vec[4];
        
        for (int i = 0; i < 4; i++)
        {
            printf("\n%d- ",i);
            scanf("%d",&vec[i]);
        }
        bubblesort(vec,4);
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d - ",vec[i]);
        }
}

----------------------------------------------------------------------
#include<stdio.h>
#include<math.h>

int is_square(int x,int y){
    y*=y;
    if (x==y)
    {
        return 1;
    }else
        return 0;
    
}


main(){

   printf("%d",is_square(4,2));
    
    
}

----------------------------------------------------------------------------

#include<stdio.h>




float max(float v[],int n){

    float max=v[0];

        for (int i = 1; i < n; i++)
        {
            if(max < v[i]){
                max=v[i];
            }
        }

    return max;
}





main(){

    float v[4];
    for (int i = 0; i < 4; i++)
    {
       printf("\n %d-",i+1);
       scanf("%f",&v[i]);
    }
    printf("O maximo e %.2f",max(v,4));   
}

---------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#define  MAX 3

void transpor(int v[][MAX]){
    int tmp;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i+1; j < MAX; j++)
        {
            tmp=v[i][j];
            v[i][j]=v[j][i];
            v[j][i]=tmp;
        }
    }
}
void imprime(int v[][MAX]){
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
           printf("%d ",v[i][j]);
        }
        putchar('\n');
    }
}
main(){

    int x[][MAX]={{1,2,3},{4,5,6},{7,8,9}};

    puts("MATRIZ INICIAL");
    imprime(x);
    transpor(x);
    puts("DEPOIS DA INVERSAO");
    imprime(x);
}
----------------------------------------------------------------------------------------------

#include <stdio.h>
#include<string.h>
#include<ctype.h>

int strcounta(char *s){

    int tam=strlen(s);
    int count=0;
    for (int i = 0; i < tam; i++)
    {   
        if (isalpha(s[i]))    //ou s[i]>='a' && s[i]<='z'
        {
            count++;
        }
    }
  return count;
}

main(){
    
    printf("-> %d",strcounta("quinze (15) abacates"));


}
----------------------------------------------------------------------------------------------------



#include <stdio.h>
#include<string.h>
#include<ctype.h>

int ult_ind_chr(char *s,char c){

    int tam=strlen(s);
    int indice=0;
    for (int i = 0; i < tam; i++)
    {   
        if (s[i]==c)
        {   
            indice=i;
        }else
            indice=-1;
    }
  return indice; 
}

main(){
    
    printf("-> %d",ult_ind_chr("quinze (15) abacates",'a'));


}


-------------------------------------------------------------
#include<stdio.h>
main(){
    int num;
    int v[99];
    int n[1];
    printf("Num: ");
    scanf("%d",&num);
    vetor100(num,v,n);

    
    printf("\nforam guardados %d numeros",*n);
    printf("\n ");

    for (int i = 0; i < *n; i++)
    {
        printf("\n %d",v[i]);
    }
    
}
void vetor100(int num,int *v,int *n){
    int x=0;
    for (int i = 99; i > 0; i--)
    {
        if (i % num == 0)
        {
           v[x]=i;
            x++;   
        }
    }  
    *n=x;
}
----------------------------------------------

#include<stdio.h>

main(){
    int a[9];
    for (int i = 0; i < 9; i++)
        a[i]=8-i;
    for (int i = 0; i < 9; i++)
        a[i]=a[a[i]];
    
}
---------------------------------------------------
#include<stdio.h>

main(){
    int x,i,j;
    x=10; i=0;
    while (x>0)
    {
        for(j=x; j>=7; j--)
            if( j % 3 == 2)
                printf("\nj- %d",j);
            else 
                printf("\nx- %d",x);

        i+=1;   x-=2;
        printf("\ni - %d",i);
    }
    

}
-------------------------------------------------------
#include<stdio.h>

main(){
    int x,y,*p1,*p2;
    x=5;
    p1=&x;
    p2=&y;
    *p2=3;
    *p1=x + y + 2**p1 + (*p2)++ + y;
    printf("x = %d ; y= %d",x ,y);
    
}
--------------------------------------------------------------
#include<stdio.h>


float somatario(int num){
    
  float fat,soma;
  fat=1;

     for (int i = 1; i <= num ; i++){
         fat=fat*i;
         soma+=(1/fat)+fat;
     }
    return soma;
}

main(){

    printf("%0.2f",somatario(2));


}


-------------------------------------------------------------------------------------


#include<stdio.h>

int fun(int a[],int n){
    int x=0;
    if(n==1)
        return a[0];
    else
        x=fun(a,n-1);
    if(x>a[n-1])
        return x;
    else
        return a[n-1];
}




main(){
    int arr[]={12,10,30,50,100};
    printf(" %d",fun(arr,5));
    getchar();


}


--------------------------------------------------------


#include<stdio.h>
#include<string.h>
#include <stdlib.h>


char *strcopy(char *str){
    
    int x;
    x=strlen(str);
    char *str1=(char*)malloc(x*sizeof(char));
    
    int i;
    for (i = 0; str[i]!= '\0'; i++)
    {
        str1[i]=str[i];
    }
    str1[i]='\0';

    return str1;
}


main(){
    char str[10];
    printf("1- string ");
    fflush(stdin);
    gets(str);

    printf("\n%s",strcopy(str));

}

---------------------------------------------

main(){

    int a[99];
    for (int i = 0; i < 99; ++i)
    {
        a[i]=98-i;
    }
    for (int i = 0; i < 99; ++i)
    {
        a[i]=a[a[i]];
    }
    

}

---------------------------------------------

#include<stdio.h>

int conta(char *str,char c){

    int count,n;
    count =0; n=0;

        while (str[n]!='\0')
        {
            if (str[n] == c)
            {
                count+=1;
            }
            n+=1;
        }
    return count;

}

main(){

    printf(" %d",conta("ola todo bem",'o'));


}

-----------------------------------------------------------

#include <stdio.h>
#include <string.h>

    

void inverte(char *str){
    int tam=strlen(str);
    char aux;
    int j=tam-1;
        for (int i = 0; i < tam/2; i++)
        {
            aux=str[i];
            str[i]=str[j-i];
            str[j-i]=aux;
        }
    printf("\nTexto invertido: %s",str);
}


main(){
    char str[20];
    printf("Texto para inverter: ");
    fflush(stdin);
    gets(str);
    inverte(str);

}


-----------------------------------------------------------


#include<stdio.h>

float somatorio(int n){

    float soma=0;
    int x;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                x=i*i;
                soma += -1.0/x;
            }else{
                x=i*i;
                soma += 1.0/x;
            }
        }
    return soma;
}

main(){

    printf("\n%.2f",somatorio(4));

}

-------------------------------------------

#include<stdio.h>
char *oQueFaz(char *str){
    int j=0;
    for (int i = 0; str[i]!= '\0'; i++)
    {
        if (str[i]!=str[j])
        {
            str[++j]=str[i];
        }
       }
        str[++j]='\0';

    return str;
    
    
    
}

main(){

    char str[22];
    int x[20];
    printf("string: ");
    fflush(stdin);
    gets(str);

    printf("\n %s",oQueFaz(str));
}

-------------------------------------------

#include<stdio.h>

int fun(int a[],int n){
    int x;
    if (n == 1)
        return a[0];
    else
        x=fun(a,n-1);
    if(x > a[n-1])
        return x;
    else
        return a[n-1];
}

main(){
    int arr[]={12, 10, 100, 50, 40};
    
    printf(" %d",fun(arr,5));

}
-------------------------------------------
*/

#include <stdio.h>
void main()
{
 int n, i, j;
 char s[80];
 do {
 printf("palavra:");
 scanf("%s", s);
    if (strcmp(s,"sair"))
    printf("length = %d\n", strlen(s));
 } while (strcmp(s,"sair"));
}