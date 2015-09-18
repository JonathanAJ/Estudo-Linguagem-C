#include <stdio.h>
#include <stdlib.h>
/*
 * Criação de estrutura árvore e definição de um novo tipo.
 */
struct arvore{
	int arv_inf;
	struct arvore *arv_esq;
	struct arvore *arv_dir;
};
typedef struct arvore Arvore;
/*
 * Protótipos
 */
Arvore* criaArvoreVazia(void);
Arvore* criaArvore(int arv_inf, Arvore *arv_esq, Arvore *arv_dir);
void mostraArvore(Arvore *arv);
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
	Arvore *arv_my = criaArvore(1,
						criaArvore(2, 
							criaArvore(4,
								criaArvoreVazia(),
								criaArvoreVazia()
							),
							criaArvore(5,
								criaArvoreVazia(),
								criaArvoreVazia()
							)
						),
						criaArvore(3,
							criaArvore(6,
								criaArvoreVazia(),
								criaArvoreVazia()
							),
							criaArvore(7,
								criaArvoreVazia(),
								criaArvoreVazia()
							)
						)
					);
	mostraArvore(arv_my);
	return 0;
}
/*
 * Cria e retorna uma árvore vazia
 */
Arvore* criaArvoreVazia(void){
	return NULL;
}
/*
 * Aloca memória para uma nova arvore, depois seta mais
 * duas outras árvores esquerda e direita, retorna o valor
 * atualizado para não se perder quando a função terminar.
 */
Arvore* criaArvore(int arv_inf, Arvore *arv_esq, Arvore *arv_dir){
	Arvore *arv_new = (Arvore*) malloc(sizeof(Arvore));
	arv_new->arv_inf = arv_inf;
	arv_new->arv_esq = arv_esq;
	arv_new->arv_dir = arv_dir;
	return arv_new;
}
/*
 * Função para mostrar a árvore em "pré-ordem".
 */
void mostraArvore(Arvore *arv){
	if(arv!=NULL){
		printf("Nó: %d\n", arv->arv_inf);
		mostraArvore(arv->arv_esq);
		mostraArvore(arv->arv_dir);
	}
}