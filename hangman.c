#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

typedef struct elemento{
    char palavra[30];
    struct elemento* nxt;
}Elem;

Pilha* cria_pilha(){
    Pilha* aux = (Pilha *) malloc(sizeof(Pilha));
    if(aux != NULL){
        aux->topo = NULL;
        aux->base = NULL;
        aux->qtd = 0;
    }
    return aux;
}

void insere_pilha(Pilha* pilha, char* str){
    if(pilha == NULL)
        return;
    Elem* elem = (Elem*) malloc(sizeof(Elem));
    if(elem != NULL){
        strcpy(elem->palavra, str);
        if(pilha->base == NULL){
            elem->nxt = NULL;
            pilha->base = elem;
        }else{
            elem->nxt = pilha->topo;
        }
        pilha->topo = elem;
    }
}

void preenche_pilha(Pilha* pilha, FILE** file){
    char pal[30];
    while(fgets(pal, sizeof(pal), *file) != NULL){
        insere_pilha(pilha, pal);
    }
}

void abertura(){
    printf("███████╗ ██████╗ ██████╗  ██████╗ █████╗ \n");
    printf("██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔══██╗\n");
    printf("█████╗  ██║   ██║██████╔╝██║     ███████║\n");
    printf("██╔══╝  ██║   ██║██╔══██╗██║     ██╔══██║\n");
    printf("██║     ╚██████╔╝██║  ██║╚██████╗██║  ██║\n");
    printf("╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝\n");
}

void escolhe_dificuldade(FILE** file){
    int res;

    printf("ESCOLHA A DIFICULDADE:\n");
    printf("1 - FACIL\n");
    printf("2 - NORMAL\n");
    scanf("%d", &res);

    while(res != 1 && res != 2){
        printf("ALTERNATIVA INVALIDA, ESCOLHA NOVAMENTE:\n");
        scanf("%d", &res);
    }
    
    if(res == 1)
        *file = fopen("facil.txt", "r");
    else
        *file = fopen("dificil.txt", "r");
}
