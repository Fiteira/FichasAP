#include <stdio.h>
#include <locale.h>

	void main(){
    int posicao;
	printf("Introduza um numero da posicao do ateleta:\n");
	scanf("%d", &posicao);

	if(posicao==1){
    printf("O ateleta recebeu a medalha de ouro!");
 }else if(posicao==2){
    printf("O ateleta recebeu a medalha de prata!"); 
}else if(posicao==3){
	printf("O ateleta recebeu a medalha de bronze!"); 
}else{
	printf("O ateleta nao recebeu nenhuma medalha!"); 
}

}

