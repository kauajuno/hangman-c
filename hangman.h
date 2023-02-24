// Definição de funções

typedef struct pilha{
    struct elemento* topo;
    struct elemento* base;
    int qtd;
}Pilha;

void abertura();
Pilha* cria_pilha();
void escolhe_dificuldade(FILE** file);
void preenche_pilha(Pilha* pilha, FILE** file);
void insere_pilha(Pilha* pilha, char* str);