#include <stdio.h>
#include <stdlib.h>
/*
 * Tipo de estrutura
 */
typedef struct arvore Arvore;

typedef struct arvore{
	int info;
	Arvore* esq;
	Arvore* dir;
}Arvore;
/*
 * Protótipos das funções
 */
Arvore* criaNoVazio(void);
Arvore* criaNo();
void liberaArvore(Arvore* arvore);
void liberaNo(Arvore* no);
int arvoreVazia(Arvore* arvore);
void arvoreImprime(Arvore* arvore);
void arvorePertence(int info, Arvore* arvore);
int arvoreVerificaPertence(int info, Arvore* arvore);
int arvoreVerificaNivel(Arvore* arvore, int info, int nivel);
void arvoreNivel(int info, Arvore* arvore);
/*
 *	Árvore binária cheia representada
 *	pelo seguinte modelo:
 *
 *           1
 *		   /   \
 *		  2     3
 *		 / \   / \
 *		4   5 6   7
 */
int main(void){
	Arvore* arvore = criaNo(1,
						criaNo(2, 
							criaNo(4,
								criaNoVazio(),
								criaNoVazio()
							),
							criaNo(5,
								criaNoVazio(),
								criaNoVazio()
							)
						),
						criaNo(3,
							criaNo(6,
								criaNoVazio(),
								criaNoVazio()
							),
							criaNo(7,
								criaNoVazio(),
								criaNoVazio()
							)
						)
					);

	arvoreImprime(arvore);

	arvorePertence(3, arvore);
	arvorePertence(8, arvore);

	arvoreNivel(5, arvore);
	
	liberaNo(arvore);
	return 0;
}

Arvore* criaNoVazio(void){
	return NULL;
}

Arvore* criaNo(int info, Arvore* esq, Arvore* dir){
	Arvore* no = (Arvore*) malloc(sizeof(Arvore));
	no->info = info;
	no->esq = esq;
	no->dir = dir;
	return no;
}

void liberaArvore(Arvore* arvore){
	if(arvoreVazia(arvore)){
		printf("Árvore vazia!\n");
		exit(1);
	}
	liberaNo(arvore);
}

void liberaNo(Arvore* no){
	if(!arvoreVazia(no)){
		liberaNo(no->esq);
		liberaNo(no->dir);
		free(no);
	}
}

int arvoreVazia(Arvore* arvore){
	return arvore == NULL;
}

void arvoreImprime(Arvore* arvore){
	if(!arvoreVazia(arvore)){
		printf("Info: %d\n", arvore->info);
		arvoreImprime(arvore->esq);
		arvoreImprime(arvore->dir);
	}
}

void arvorePertence(int info, Arvore* arvore){
	int x = arvoreVerificaPertence(info, arvore);
	if(x){
		printf("%d pertence.\n", info);
	}else{
		printf("%d não pertence.\n", info);
	}
}

int arvoreVerificaPertence(int info, Arvore* arvore){
	if(arvoreVazia(arvore)){
		return 0;
	}else{
		return info == arvore->info ||
		arvoreVerificaPertence(info, arvore->esq) ||
		arvoreVerificaPertence(info, arvore->dir);
	}
}

void arvoreNivel(int info, Arvore* arvore){
	if(arvoreVazia(arvore)){
		printf("Árvore vazia!\n");
		printf("Nível/Posição é -1\n");
	}
	else if(!arvoreVerificaPertence(info, arvore)){
		printf("%d não pertence.\n", info);
	}else{
		printf("Nível/Posição de %d é %d.\n", info, arvoreVerificaNivel(arvore, info, 0));
	}
}

int arvoreVerificaNivel(Arvore* arvore, int info, int nivel){
    if (arvore == NULL)
        return 0;
 
    if (arvore->info == info)
        return nivel;
 
    int nivelRetorno = arvoreVerificaNivel(arvore->esq, info, nivel+1);
    if (nivelRetorno != 0)
        return nivelRetorno;
 
    nivelRetorno = arvoreVerificaNivel(arvore->dir, info, nivel+1);
    return nivelRetorno;
}