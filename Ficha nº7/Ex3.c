#include <stdio.h>
#define MAX 50

typedef struct aluno
{
    int numero;
    char nome[20];
    float nota;
}ALUNO;

void lerAluno(ALUNO *p,int n){
int i;
    for(i=0;i<n;i++){
        p[i].numero=i+1;
        
        printf("\nNome do aluno %d:",i+1);
        fflush(stdin);
        gets(p[i].nome);
        
        printf("\nNota do aluno %d:",i+1);
        scanf("%f",&p[i].nota);
    }
}

void mostrarAluno(ALUNO *p,int n){
    int i;
        for(i=0;i<n;i++){
            printf("\nNumero do Aluno: %d",p[i].numero);
            printf("\nNome do Aluno: %s",p[i].nome);
            printf("\nNota do Aluno: %f",p[i].nota);
            printf("\n------------------------------------");
        }
}

void pesquisarAluno(ALUNO *p,int n){
    int i,numero;
        do
        {
            printf("\nQual e o numero do aluno que quer pesquisar?");
            scanf("%d",&numero);
            
        } while (numero<0 || numero>n);
        
    for(i=0;i<n;i++){
        if(numero == p[i].numero){
            printf("\nNome do aluno %d: %s",numero,p[i].nome);
            printf("\nNota do aluno %d: %f",numero,p[i].nota);
        }
    }
}
main(){
    int N;
    ALUNO turma[MAX];
    do{
        printf("\nQuantos alunos tem a turma?");
        scanf("%d",&N);
        
    }while (N<1 || N>50);

    lerAluno(turma,N);
    mostrarAluno(turma,N);
    pesquisarAluno(turma,N);
}
