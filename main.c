#include<stdio.h>

int main(){

    int dificuldade;
    FILE* fp;
    char palavra[30];

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