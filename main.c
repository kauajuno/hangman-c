#include<stdio.h>
#include"hangman.h"

int main(){

    int dificuldade;
    FILE* fp;
    Pilha* pi = cria_pilha();
    Letra* palavra;
    char palavra_aux[30];
    char palpite;


    abertura();
    escolhe_dificuldade(&fp);
    preenche_pilha(pi, &fp);
    while(1){
        palavra = cria_palavra();
        prepara_palavra(pi, palavra, palavra_aux);
        do{
            printa_palavra(palavra);
            scanf(" %c", &palpite);
            checa_palpite(palavra, palpite);
        }while(!checa_completude(palavra));
        free_palavra(palavra);
        pop_pilha(pi);
    }
    


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