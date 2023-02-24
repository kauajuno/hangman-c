#include<stdio.h>
#include"hangman.h"

int main(){

    int dificuldade;
    FILE* fp;
    Pilha* pi = cria_pilha();
    Letra* palavra;
    char palavra_aux[30];
    char palpite;
    int tentativas, score, fim = 1, acerto;

    score = 0;
    abertura();
    escolhe_dificuldade(&fp);
    preenche_pilha(pi, &fp);
    while(1){
        palavra = cria_palavra();
        prepara_palavra(pi, palavra, palavra_aux);
        tentativas = 7;
        do{
            printa_forca(tentativas);
            printa_palavra(palavra);
            scanf(" %c", &palpite);
            acerto = checa_palpite(palavra, palpite);
            if(!acerto) tentativas--;
        }while(!checa_completude(palavra) && tentativas != 0);
        if(tentativas == 0){
            printf("\033[0;31m");
            printf("FIM DE JOGO\n");
            printf("PONTUACAO FINAL: %d\n", score);
            return 0;
        }
        printf("\033[0;32m");
        printf("ISSO MESMO! A PALAVRA ERA %s.\n", palavra_aux);
        printf("\033[0;37m");
        score++;
        free_palavra(palavra);
        fim = pop_pilha(pi);
        if(fim == 0) break;
    }
    
    printf("\033[0;32m");
    printf("PARABENS! VOCE CONCLUIU O JOGO.\n");


	return 0;
}