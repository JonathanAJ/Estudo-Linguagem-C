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
Arvore* criaArvoreVazia(void);
Arvore* insereNo(int info, Arvore* arvore);
Arvore* removeNo(int info, Arvore* arvore);
void liberaArvore(Arvore* arvore);
void liberaNo(Arvore* no);
int arvoreVazia(Arvore* arvore);
void arvoreImprime(Arvore* arvore);
void arvorePertence(int info, Arvore* arvore);
int arvoreVerificaPertence(int info, Arvore* arvore);
int retornaNivelUtil(Arvore* arvore, int info, int nivel);
void retornaNivel(int info, Arvore* arvore);
/*
 *	Árvore binária de Busca
 */
int main(void){
	Arvore* arvore = criaArvoreVazia();

	arvore = insereNo(10, arvore);
	arvore = insereNo(8, arvore);
	arvore = insereNo(7, arvore);
	arvore = insereNo(12, arvore);
	arvore = insereNo(15, arvore);
	arvore = insereNo(9, arvore);
	arvore = insereNo(11, arvore);

	arvore = removeNo(7, arvore);

	arvoreImprime(arvore);
	
	arvorePertence(3, arvore);
	arvorePertence(12, arvore);

	retornaNivel(11, arvore);

	liberaNo(arvore);
	return 0;
}

Arvore* criaArvoreVazia(void){
	return NULL;
}

Arvore* insereNo(int info, Arvore* arvore){
	if(arvoreVazia(arvore)){
		arvore = (Arvore*) malloc(sizeof(Arvore));
		arvore->info = info;
		arvore->esq = NULL;
		arvore->dir = NULL;
	}else if(arvore->info > info){
		arvore->esq = insereNo(info, arvore->esq);
	}else if(arvore->info < info){
		arvore->dir = insereNo(info, arvore->dir);
	}else{
		printf("Elemento %d já pertence a árvore!\n", info);
	}
	return arvore;
}

Arvore* removeNo(int info, Arvore* arvore){
	if(!arvoreVazia(arvore)){
		if(arvore->info > info){
			arvore->esq = removeNo(info, arvore->esq);
		}else if(arvore->info < info){
			arvore->dir = removeNo(info, arvore->dir);
		}else{
			Arvore* tmp;
			if(arvore->esq == NULL){
				tmp = arvore;
				arvore = arvore->dir;
				free(tmp);
			}else if(arvore->dir == NULL){
				tmp = arvore;
				arvore = arvore->esq;
				free(tmp);
			}else{
				tmp = arvore->esq;
				while(tmp->dir != NULL){
					tmp = tmp->dir;
				}
				arvore->info = tmp->info;
				tmp->info = info;
				arvore->esq = removeNo(info, arvore->esq);
			}
		}
	}
	return arvore;
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

int arvoreVazia(Arvore* arvore){
	return arvore == NULL;
}

int retornaNivelUtil(Arvore* arvore, int info, int nivel){
    if (arvore == NULL)
        return 0;
 
    if (arvore->info == info)
        return nivel;
 
    int nivelBaixo = retornaNivelUtil(arvore->esq, info, nivel+1);
    if (nivelBaixo != 0)
        return nivelBaixo;
 
    nivelBaixo = retornaNivelUtil(arvore->dir, info, nivel+1);
    return nivelBaixo;
}

void retornaNivel(int info, Arvore* arvore){
	printf("Nível/Posição de %d é %d.\n", info, retornaNivelUtil(arvore, info, 0));
}