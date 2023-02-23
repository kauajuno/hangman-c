#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

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