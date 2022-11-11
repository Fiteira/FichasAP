#include<stdio.h>

void trocarStr(char *p,int n){

    int i,j;
    char aux;
        for(i=0;i<n;i++){
            for(j=n;j<0;j--){
                aux=p[i];
                p[i]=p[j];
                p[j]=aux;
            }
        }
printf("%s",p);
}

main(){
    char p[20];
    int tam;
    printf("Introduza um numero: ");
    fflush(stdin);
    gets(p);
    tam=strlen(p);
    trocarStr(p,tam);
    

}
/*
#include<stdio.h>

void trocarStr(char *p,int n){

    int i,j;
    char aux;
        for(i=0;i<n/2;i++){
            aux=p[i];
            p[i]=p[n-i-1];
            p[n-i-1]=aux;
        }

}

main(){
    char p[20];
    int tam;
    printf("Introduza um numero: ");
    fflush(stdin);
    gets(p);
    tam=sizeof(p);
    tam=tam-1;
    //tam=strlen(p);
    printf("%d",tam);
    trocarStr(p,tam);
    //printf("%s",p);

}
*/