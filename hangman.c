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

// insere um elemento com uma determinada palavra na pilha, sub-rotina do preenche_pilha
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
        pilha->qtd++;
    }
}

// preenche a pilha com palavras contidas no arquivo
void preenche_pilha(Pilha* pilha, FILE** file){
    char pal[30];
    while(fgets(pal, sizeof(pal), *file) != NULL){
        insere_pilha(pilha, pal);
    }
}

// copia a palavra contida no elemento mais de cima da pilha para a string passada no parâmetro
int get_topo_pilha(Pilha* pilha, char* st){
    if(pilha == NULL)
        return 0;
    if(pilha->topo == NULL)
        return 0;
    strcpy(st, pilha->topo->palavra);
    return 1;
}

// remove o elemento no topo da pilha
int pop_pilha(Pilha* pilha){
    if(pilha == NULL)
        return 0;
    if(pilha->topo == NULL)
        return 0;
    Elem* aux = pilha->topo;
    pilha->topo = pilha->topo->nxt;
    free(aux);
    pilha->qtd--;
    return 1;
}

Letra* cria_palavra(){
    Letra* p = (Letra*) malloc(sizeof(Letra));
    if(p != NULL){
        p->nxt = NULL;
    }
    return p;
}

void insere_palavra(Letra* l, char letra){
    if(l == NULL)
        return;
    Letra* aux = l;
    Letra* nova_letra = (Letra*) malloc(sizeof(Letra));
    if(nova_letra != NULL){
        nova_letra->letra = letra;
        nova_letra->adivinhada = 0;
        nova_letra->nxt = NULL;

        while(aux->nxt != NULL)
            aux = aux->nxt;

        aux->nxt = nova_letra;
    }
}

void prepara_palavra(Pilha* pilha, Letra* palavra_list, char* palavra){
    int index = 0;
    get_topo_pilha(pilha, palavra);
    while(palavra[index] != '\0' && palavra[index] != '\n'){
        insere_palavra(palavra_list, palavra[index]);
        index++;
    }
}

void printa_palavra(Letra* palavra_list){
    Letra* aux = palavra_list->nxt;
    while(aux != NULL){
        if(aux->adivinhada)
            printf("%c ", aux->letra);
        else
            printf("_ ");
        aux = aux->nxt;
    }
    printf("\n");
}

int checa_palpite(Letra* palavra_list, char palpite){
    int ocorrencias = 0;
    Letra* aux = palavra_list->nxt;
    while(aux != NULL){
        if(palpite == aux->letra){
            ocorrencias++;
            aux->adivinhada = 1;
        }
        // printf("SPOILER! AQUI DEVERIA TER UM %c\n", aux->letra);
        aux = aux->nxt;
    }
    if(ocorrencias == 0){
        printf("A LETRA %c NAO ESTA NESSA PALAVRA.\n", palpite);
        return 0;
    }
    printf("A LETRA %c FOI ENCONTRADA %d VEZES!\n", palpite, ocorrencias);
    return 1;
}

int checa_completude(Letra* palavra){
    int complete = 1;
    Letra* aux = palavra->nxt;
    while(aux != NULL){
        if(!aux->adivinhada){
            complete = 0;
            break;
        }
        aux = aux->nxt;
    }
    return complete;
}

void free_palavra(Letra* p){
    free(p);
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