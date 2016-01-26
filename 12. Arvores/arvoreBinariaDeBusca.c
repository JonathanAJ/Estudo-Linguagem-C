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
int arvoreVerificaNivel(Arvore* arvore, int info, int nivel);
void arvoreNivel(int info, Arvore* arvore);
/*
 *	Árvore binária de busca representada
 *	pelo seguinte modelo:
 *
 *           10
 *          /  \
 *         8    12
 *        / \   / \
 *       7   9 11  15
 *                  \
 *                   20
 */
int main(void){
	Arvore* arvore = criaArvoreVazia();

	arvoreNivel(20, arvore);

	arvore = insereNo(10, arvore);
	arvore = insereNo(8, arvore);
	arvore = insereNo(7, arvore);
	arvore = insereNo(12, arvore);
	arvore = insereNo(15, arvore);
	arvore = insereNo(9, arvore);
	arvore = insereNo(11, arvore);
	arvore = insereNo(20, arvore);

	arvore = removeNo(7, arvore);

	arvoreImprime(arvore);
	
	arvorePertence(3, arvore);
	arvorePertence(12, arvore);

	arvoreNivel(20, arvore);

	liberaNo(arvore);
	return 0;
}

Arvore* criaArvoreVazia(void){
	return NULL;
}

Arvore* insereNo(int info, Arvore* arvore){
	/*
	 * Se for vazia cria o nó (raiz/folha)
	 */
	if(arvoreVazia(arvore)){
		arvore = (Arvore*) malloc(sizeof(Arvore));
		arvore->info = info;
		arvore->esq = NULL;
		arvore->dir = NULL;
	/*
	 * Se a informação for menor, insere a esquerda.
	 */
	}else if(arvore->info > info){
		arvore->esq = insereNo(info, arvore->esq);
	/*
	 * Se a informação for maior, insere a direita.
	 */
	}else if(arvore->info < info){
		arvore->dir = insereNo(info, arvore->dir);
	}else{
		printf("Elemento %d já pertence a árvore!\n", info);
	}
	return arvore;
}

Arvore* removeNo(int info, Arvore* arvore){
	if(!arvoreVazia(arvore) && arvoreVerificaPertence(info, arvore)){
		/*
		 * Se a informação for menor analisa a parte esquerda
		 */
		if(arvore->info > info){
			arvore->esq = removeNo(info, arvore->esq);
		/*
		 * Se a informação for maior analisa a parte direita
		 */
		}else if(arvore->info < info){
			arvore->dir = removeNo(info, arvore->dir);
		/*
		 * Faz a recursão até não ser nem maior, nem menor, mas igual.
		 */
		}else{
			Arvore* tmp;
			/*
			 * Se o valor da esquerda for nulo a arvore receberá o valor da direita
			 * e o valor anterior da arvore será liberado. Ocorre de modo contrário no
			 * próximo else if.
			 */
			if(arvore->esq == NULL){
				tmp = arvore;
				arvore = arvore->dir;
				free(tmp);
			}else if(arvore->dir == NULL){
				tmp = arvore;
				arvore = arvore->esq;
				free(tmp);
			/*
			 * No entanto, se nenhum valor for nulo, o algoritmo terá que reestruturar
			 * todos os filhos tanto da direita como da esquerda para remoção de info.
			 */
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