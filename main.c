#include<stdio.h>
#include"hangman.h"

int main(){

    int dificuldade;
    FILE* fp;
    Pilha* pi = cria_pilha();
    char palavra[30];

    abertura();
    escolhe_dificuldade(&fp);
    preenche_pilha(pi, &fp);

    /*
    Utilizado pra testar se o arquivo tá realmente sendo aberto!
	if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    char chunk[128];

    while(fgets(chunk, sizeof(chunk), fp) != NULL){
    	fputs(chunk, stdout);
    	fputs("\n", stdout);
    }
    */


	return 0;
}