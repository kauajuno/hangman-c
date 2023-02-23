#include<stdio.h>
#include<stdlib.h>

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

int main(){

    int dificuldade;
    FILE* fp;
    char[30] palavra;

    abertura();
    escolhe_dificuldade(&fp);

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