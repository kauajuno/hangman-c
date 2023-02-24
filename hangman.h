// Definição de funções

typedef struct pilha{
    struct elemento* topo;
    struct elemento* base;
    int qtd;
}Pilha;

typedef struct letra{
	char letra;
	int adivinhada;
	struct letra* nxt;
}Letra;

void abertura();
Pilha* cria_pilha();
void escolhe_dificuldade(FILE** file);
void preenche_pilha(Pilha* pilha, FILE** file);
void insere_pilha(Pilha* pilha, char* str);
int get_topo_pilha(Pilha* pilha, char* str);
int pop_pilha(Pilha* pilha);
Letra* cria_palavra();
void insere_palavra(Letra* l, char letra);
void prepara_palavra(Pilha* pilha, Letra* palavra, char* str);
void printa_palavra(Letra* palavra_list);
int checa_palpite(Letra* palavra, char palpite);
int checa_completude(Letra* palavra);
void free_palavra(Letra* p);
void printa_forca(int num);