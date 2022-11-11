//
//  main.c
//  OrdenEPesquisaVectStructV2
//
//  Created by Jorge Alexandre de Albuquerque Loureiro on 18/12/18.
//  Last update Jorge Alexandre de Albuquerque Loureiro on 10/01/22.
//  Copyright © 2022 Jorge Alexandre de Albuquerque Loureiro. All rights reserved.
//



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>                // for gettimeofday()
#include <errno.h>
typedef int dado;
#define maxTam 1000// tamanho máximo dos vectores de dados criados
#include <errno.h>
#define MAX 1000 // não utilizada

typedef struct {int ano, mes, dia;}DATA;
typedef struct pessoa
{
    short num;
    char nome[60];
    DATA nascimento;
    char genero;
    float altura;
    float peso;
    char habilitacoes[40];
    float salario;
    DATA dtActualizacao;
} PESSOA;

void lerP(PESSOA *ptr);
void mostrarP(PESSOA x);
void mostraErro(void);
void gerarDadosP(PESSOA *vectP, int tam, int limSup);

void sortSelecaoDirectaP(PESSOA *vectP, int tam);
void sortSelecaoDirectaPNome(PESSOA *vectP, int tam);
void sortSelecaoDirectaPNomeDesc(PESSOA *vectP, int tam);

void sortInsercaoDirectaP(PESSOA *vectP, int tam);
void sortInsercaoDirectaPNome(PESSOA *vectP, int tam);
void sortInsercaoDirectaPNomeDesc(PESSOA *vectP, int tam);

void bubbleSortP(PESSOA *vectP, int tam);

void fastBubbleSortP(PESSOA *vectP, int tam);

void shakerSortP(PESSOA *vectP, int tam);

void ShellSortV1P(PESSOA *vectP, int tam);
void ShellSortV1PNome(PESSOA *vectP, int tam);

void ShellSortV2P(PESSOA *vectP, int tam);
void ShellSortV3P(PESSOA *vectP, int tam);

void QuickSortV1P(PESSOA *vectP, int tam, int first, int last);

int seqSearchP(PESSOA *vectP, int tamVect, int chave);
int seqSearchPNome(PESSOA *vectP, int tamVect, char *chave);

int PesquisaBinariaP(PESSOA *vectP, int tamVect, int chave);
int PesquisaBinariaPNome(PESSOA *vectP, int tamVect, char *chave);

int PesquisaBinariaRecP(PESSOA *vectP, int tamVect, int indInf, int indSup, int chave);
int PesquisaBinariaRecPNome(PESSOA *vectP, int tamVect, int indInf, int indSup, char *chave);

int main()
{
    PESSOA umaPessoa;
    int i, num, pos;
    char mostrar ='n';
    char nome[50];
    
    
    
    PESSOA vectP[maxTam];
    PESSOA vectPOrdCod[maxTam];
    PESSOA vectPOrdNome[maxTam];
    
    struct timeval t1, t2;
    double elapsedTime;
    unsigned long lenStr;
    
    gerarDadosP(vectP, maxTam, maxTam);
    //exit(0);
    
    if (maxTam <= 2000)
    {
        printf("Vector gerado...\n");
        for (i=0; i<maxTam; i++)
        {
            umaPessoa=vectP[i];
            printf("Pessoa: %d\n", i+1);
            mostrarP(umaPessoa);
            //printf("\nDigite <enter> para continuar...");
            //getchar();
        }
    }
    
    // Selecção Directa ordenada por código
    // copia o vector gerado para o vector que vai ser ordenado
    printf("Ordenação por Selecção Directa por código ascendente ....\n\n");
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortSelecaoDirectaP(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Selecção Directa: Executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d\n", i+1);
        mostrarP(umaPessoa);
    }
    printf("\nDigite <enter> para continuar...");
    getchar();
    
    // Selecção Directa para ordenação por nome ascendente
    // copia o vector gerado para o vector que vai ser ordenado
    printf("Ordenação por nome ascendente, usando a Selecção Directa....\n\n");
    for (i=0; i<maxTam; i++)
        vectPOrdNome[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortSelecaoDirectaPNome(vectPOrdNome, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Selecção Directa por Nome ascendente executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdNome[i];
        printf("Pessoa: %d\n", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    // Selecção Directa para ordenação por nome descendente
    // copia o vector gerado para o vector que vai ser ordenado
    printf("Ordenação por nome descendente usando a Selecção Directa....\n\n");
    for (i=0; i<maxTam; i++)
        vectPOrdNome[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortSelecaoDirectaPNomeDesc(vectPOrdNome, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por nome descendente, usando Selecção Directa executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdNome[i];
        printf("Pessoa: %d\n", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Inserção Directa
    printf("Ordenação por Inserção Directa por código....\n\n");
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortInsercaoDirectaP(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Inserção Directa: Executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    
    // Inserção Directa por nome
    printf("Ordenação por Inserção Directa por nome ascendente....\n\n");
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdNome[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortInsercaoDirectaPNome(vectPOrdNome, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Inserção Directa por Nome Ascendente executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdNome[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    
    // Inserção Directa por nome descendente
    printf("Ordenação por Inserção Directa por nome descendente....\n\n");
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdNome[i]=vectP[i];
    // start timer
    gettimeofday(&t1, NULL);
    
    sortInsercaoDirectaPNomeDesc(vectPOrdNome, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Inserção Directa por Nome Ascendente executada em %.9f milissegundos. \n", elapsedTime);
    printf("Vector ordenado...\n");
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdNome[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Bubble Sort ordenar por código
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    bubbleSortP(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Bubble Sort por código executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Fast Bubble Sort ordenar por código
    
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    fastBubbleSortP(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por código usando Fast Bubble Sort executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Shaker Sort ordenar por código
    
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    shakerSortP(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por código usando Shaker Sort, executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Shell Sort V1 ordenar por código
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    ShellSortV1P(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Shell Sort V1: Executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Shell Sort V1 ordenar por nome
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdNome[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    ShellSortV1PNome(vectPOrdNome, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por nome usando o Shell Sort V1, executada em %.9f milissegundos. \n", elapsedTime);
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdNome[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Shell Sort V2 (ordenar por código)
    
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    ShellSortV2P(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Shell Sort V2: Executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Shell Sort V3 (ordenar por código)
    
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    ShellSortV3P(vectPOrdCod, maxTam);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Shell Sort V3: Executada em %.9f milissegundos. \n", elapsedTime);
    if (mostrar=='s')
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Quick Sort V1 or código
    
    // copia o vector gerado para o vector que vai ser ordenado
    for (i=0; i<maxTam; i++)
        vectPOrdCod[i]=vectP[i];
    
    // start timer
    gettimeofday(&t1, NULL);
    
    QuickSortV1P(vectPOrdCod, maxTam, 0, maxTam-1);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    printf("Ordenação por Quick Sort V1: Executada em %.9f milissegundos. \n", elapsedTime);
    for (i=0; i<maxTam; i++)
    {
        umaPessoa=vectPOrdCod[i];
        printf("Pessoa: %d", i+1);
        mostrarP(umaPessoa);
        //printf("\nDigite <enter> para continuar...");
        //getchar();
    }
    
    // Pesquisa Linear por código
    
    printf("\n\nPesquisa linear...\n");
    printf("Qual o valor a pesquisar: ");
    scanf(" %d", &num);
    
    // start timer
    gettimeofday(&t1, NULL);
    
    pos=seqSearchP(vectPOrdCod, maxTam, num);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    if(pos == -1)
        printf("O código %d não foi encontrado.\n", num);
    else{
        printf("A pesquisa linear por código foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O código %d foi encontrado na posição %d do vector.\n", num, pos+1);
    }
    

    // Pesquisa Linear por nome
    
    printf("\n\nPesquisa linear por nome...\n");
    printf("Qual o nome a pesquisar: ");
    getchar();
    fgets(nome, 100, stdin);
    //gets(nome);
    printf("1-A chave para a pesquisa linear por nome: %s\n\n", nome);
    
    // start timer
    gettimeofday(&t1, NULL);
    lenStr=strlen(nome);
    nome[lenStr-1]='\0';
    pos=seqSearchPNome(vectPOrdNome, maxTam, nome);
    
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    if(pos == -1)
        printf("O nome %s não foi encontrado.\n", nome);
    else{
        printf("A pesquisa linear por nome foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O nome %s foi encontrado na posição %d do vector.\n", nome, pos+1);
    }
    

    // Pesquisa Binária por código
    
    printf("\n\nPesquisa binária por código...\n");
    printf("Qual o código a pesquisar: ");
    scanf("%d", &num);
    
    // start timer
    gettimeofday(&t1, NULL);
    
    pos=PesquisaBinariaP(vectPOrdCod, maxTam, num);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    if(pos == -1)
        printf("O codigo %d não foi encontrado.\n", num);
    else{
        printf("A pesquisa binária por código foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O código %d foi encontrado na posição %d do vector.\n", num, pos+1);
    }
    
    // Pesquisa Binária Recursiva por código
    
    printf("\n\nPesquisa binária recursiva por código...\n");
    printf("Qual o código a pesquisar: ");
    scanf("%d", &num);
    
    // start timer
    gettimeofday(&t1, NULL);
    
    pos=PesquisaBinariaRecP(vectPOrdCod, maxTam, 0, maxTam-1, num);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    if(pos == -1)
        printf("O codigo %d não foi encontrado.\n", num);
    else{
        printf("A pesquisa binária por código foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O código %d foi encontrado na posição %d do vector.\n", num, pos+1);
    }
    
    

    // Pesquisa Binária por nome
    
    printf("\n\nPesquisa binária por nome...\n");
    printf("Qual o nome a pesquisar: ");
    getchar();
    fgets(nome, 100, stdin);
    lenStr=strlen(nome);
    nome[lenStr-1]='\0';
    printf("2-A chave para a pesquisa binária por nome: %s\n\n", nome);
    // start timer
    gettimeofday(&t1, NULL);
    
    // Ordenar por nome para depois fazer a pesquisa binária por nome
    ShellSortV1PNome(vectPOrdNome, maxTam);
    
    pos=PesquisaBinariaPNome(vectPOrdNome, maxTam, nome);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    if(pos == -1)
        printf("O nome %s não foi encontrado.\n", nome);
    else{
        printf("A pesquisa binária por nome foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O nome %s foi encontrado na posição %d do vector.\n", nome, pos+1);
    }
    
    // Pesquisa Binária Recursiva por nome
    
    printf("\n\nPesquisa binária recursiva...\n");
    printf("Qual o nome a pesquisar: ");
    fgets(nome, 100, stdin);
    lenStr=strlen(nome);
    nome[lenStr-1]='\0';
    
    // start timer
    gettimeofday(&t1, NULL);
    
    pos=PesquisaBinariaRecPNome(vectPOrdNome, maxTam, 0, maxTam-1, nome);
    
    // stop timer
    gettimeofday(&t2, NULL);
    
    // calcular e imprimir o tempo decorrido em milissegundos
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    
    if(pos == -1)
        printf("O nome %s não foi encontrado.\n", nome);
    else{
        printf("A pesquisa binária recursiva por nome foi executada em %.9f milissegundos. \n", elapsedTime);
        printf("O nome %s foi encontrado na posição %d do vector.\n", nome, pos+1);
    }
    
    getchar();
    printf("Digite <enter> para terminar....");
    getchar();
    
    return 0;
}

