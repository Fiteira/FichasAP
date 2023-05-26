#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Data
{
   int DIA, MES, ANO;
}Data;

typedef struct Individuo
{
    //char CC[10]; //['1''2''8''0''3''5'2']
    int CC;
    float ALTURA;
    float PESO;
    char GENERO;
    Data DT_NASCIMENTO;
    char pagina_web_pessoal[50];
}Individuo;

//----------------------------
Individuo *CriarVectorIndividuos(int N)
{
    Individuo *M = (Individuo *)malloc(N*sizeof(Individuo));
    if (!M) return NULL;
    for (int i = 0; i < N; i++)
    {
        M[i].CC = 10000 + rand() % 5000;
        M[i].ALTURA = (150 + rand() % 51)/100.0; // Est� em m
        M[i].DT_NASCIMENTO.ANO = 2000 + rand() % 21;
        M[i].DT_NASCIMENTO.MES = rand() % 12;
        M[i].DT_NASCIMENTO.DIA = rand() % 31;
        if (rand() % 2 == 0)
            M[i].GENERO = 'F';
        else M[i].GENERO = 'M';

        M[i].PESO = 50 + rand() % 51;
        sprintf(M[i].pagina_web_pessoal,"www.pag_%d_%d.pt", M[i].CC, M[i].DT_NASCIMENTO.ANO);
    }
    return M;
}
//----------------------------
void Mostrar_Vector(Individuo *V, int N)
{
    if (!V) return;
    for(int i = 0; i < N; i++)
    {
        printf("Individuo\n");
        printf("\tCC = %d\n", V[i].CC);
        printf("\tALTURA = %0.3f\n", V[i].ALTURA);
        printf("\tPESO = %0.3f\n", V[i].PESO);
        printf("\tGENERO = %c\n", V[i].GENERO);
        printf("\tDATA_NASC = %d-%d-%d\n", V[i].DT_NASCIMENTO.ANO,
               V[i].DT_NASCIMENTO.MES,V[i].DT_NASCIMENTO.DIA);
        printf("\tPAG_WEB = [%s]\n", V[i].pagina_web_pessoal);
    }
}
//----------------------------
int Ind_Saudaveis(Individuo *V, int N)
{
    float IMC;
    int Cont = 0;
    for (int i = 0; i < N; i++)
    {
        IMC = V[i].PESO / (V[i].ALTURA * V[i].ALTURA);
        if ((IMC > 18.5) && (IMC < 24.9))
            Cont++;
    }
    return Cont;
}

//----------------------------
float Media_Massa_Corporal(Individuo *V, int N, int ano_1, int ano_2)
{
    if (!V) return -1;
    float Somat = 0;
    int Cont = 0;
    for (int i = 0; i < N; i++)
    {
        if ((V[i].DT_NASCIMENTO.ANO > ano_1) && (V[i].DT_NASCIMENTO.ANO < ano_2))
        {
            Somat += V[i].PESO;
            Cont++;
        }
    }
    if (Cont == 0) return -1;
    return Somat / Cont;
}
//----------------------------
void Remove_Individuo(Individuo *V, int *N, int nCC)
{
    if (!V) return;
    //[A,B,C,D,E,F,G] N = 7
    // Remover D
    //[A,B,C,E,F,G,G] N = 6
    int pos = -1;
    for (int i = 0; i < *N; i++)
        if (V[i].CC == nCC)
        {
            pos = i;
            break;
        }
    if (pos != -1) // Se encontrou vou remover
    {
    // agora temos de deslocar pos <- pos+1; pos+1<-pos+2
        for (int i = pos; i < (*N-1); i++) // i = N-1
            V[i] = V[i+1];
        *N = *N - 1; // Como foi retirado um elemento, ent�o o numero de elementos DEcrementado
    }
}
//----------------------------
void Limpar_Memoria(Individuo *V)
{
    if (V) free (V);
}
//----------------------------
int LerInteiro(char *msg)
{
    printf("%s", msg);
    int X;
    scanf("%d", &X);
    return X;
}
//----------------------------
void GravarFicheiroTexto(Individuo *V, int N, char *nome_ficheiro)
{
    if (!V) return;
    FILE *F = fopen(nome_ficheiro, "w");
    if (!F) return;
    for(int i = 0; i < N; i++)
    {
        fprintf(F,"Individuo\n");
        fprintf(F,"\tCC = %d\n", V[i].CC);
        fprintf(F,"\tALTURA = %0.3f\n", V[i].ALTURA);
        fprintf(F,"\tPESO = %0.3f\n", V[i].PESO);
        fprintf(F,"\tGENERO = %c\n", V[i].GENERO);
        fprintf(F,"\tDATA_NASC = %d-%d-%d\n", V[i].DT_NASCIMENTO.ANO,
               V[i].DT_NASCIMENTO.MES,V[i].DT_NASCIMENTO.DIA);
        fprintf(F,"\tPAG_WEB = [%s]\n", V[i].pagina_web_pessoal);
    }
    fclose(F);
}

// Para mostrar na 1� aula Pr�tica ao Docente!
void GravarFicheiro_Binario(Individuo *V, int N, char *nome_ficheiro)
{
    if (!V) return;

}
// Para mostrar na 1� aula Pr�tica ao Docente!
// Pelo campo que quiserem!
void Ordenar_Vector(Individuo *V, int N)
{

}
Individuo *Pesquisar_CC(Individuo *V, int N, int cc)
{
    if (!V) return NULL;
    for(int i = 0; i < N; i++)
        if (V[i].CC == cc)
            return &(V[i]); // tenho de devolver o endere�o desta casa i

    return NULL;
}
/*
Este Algoritmo deve ser bem estudado!!!, percebido!!!!!
*/
int Determinar_Mes_Mais_Aniversarios(Individuo *V, int N)
{
    if (!V) return -1;
    int VAUX[12];  // [0;0;0;2;0;0;0;0;1;0;1;0]
    for (int i = 0;i < 12; i++)
        VAUX[i] = 0;

    for(int i = 0; i < N; i++)
        VAUX[V[i].DT_NASCIMENTO.MES]++;

    // [0;0;0;2;0;0;0;0;1;0;1;0]
    int Mes_Mais = 0;
    for(int i = 0; i < 12; i++)
        if (VAUX[i] > VAUX[Mes_Mais])
            Mes_Mais = i;

    return Mes_Mais;
}

int Menu()
{
    printf("1 - Mostrar Vector\n");
    printf("2 - Ordenar Vector\n");
    printf("3 - Gravar Ficheiro TEXTO o Vector\n");
    printf("4 - Pesquisar pelo CC\n");
    printf("5 - Mes com mais Nascimentos\n");
    printf("0 - Sair\n");
    int OP = LerInteiro("Qual a opcao? ");
    return OP;
}

int main()
{
    printf("Ex. 4 da Ficha 0->1!\n");
    srand(time(NULL));

    Individuo *VIND;
    int N;
    N = LerInteiro("Quantas Pessoas !? ");
    VIND = CriarVectorIndividuos(N);
    Mostrar_Vector(VIND, N);
    int OP = 0;
    do
    {
        OP = Menu();
        switch (OP)
        {
            case 1: Mostrar_Vector(VIND, N);
                break;
            case 2:
                Ordenar_Vector(VIND, N);
                Mostrar_Vector(VIND, N);
                break;
            case 3: GravarFicheiroTexto(VIND, N, "ola.txt");
                break;
            case 4:
                {
                int cc = LerInteiro("Qual o CC a Pesquisar? ");
                Individuo *X = Pesquisar_CC(VIND, N, cc);
                if (X)
                    printf("A Pesssoa EXISTE!\n");
                else
                    printf("A Pesssoa NAOAOAOAO EXISTE!, AZAR!!!!\n");
                }
                break;
            case 5:
                {
                    int mes_mais = Determinar_Mes_Mais_Aniversarios(VIND, N);
                    if (mes_mais != -1)
                        printf("Mes com mais Aniversarios = %d\n", mes_mais);
                }
            default:
                printf("Opcao nao Implementada!\n"); break;
        }
    }while (OP != 0);
    Limpar_Memoria(VIND);
    return 0;
}
