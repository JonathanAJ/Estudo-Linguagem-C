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
Arvore* criaNoVazio(void);
Arvore* criaNo(int arv_inf, Arvore *arv_esq, Arvore *arv_dir);
void arvoreImprime(Arvore *arv);
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
	Arvore *arvore = criaNo(1,
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
	return 0;
}
/*
 * Cria e retorna uma árvore vazia
 */
Arvore* criaNoVazio(void){
	return NULL;
}
/*
 * Aloca memória para uma nova arvore, depois seta mais
 * duas outras árvores esquerda e direita, retorna o valor
 * atualizado para não se perder quando a função terminar.
 */
Arvore* criaNo(int arv_inf, Arvore *arv_esq, Arvore *arv_dir){
	Arvore *arv_new = (Arvore*) malloc(sizeof(Arvore));
	arv_new->arv_inf = arv_inf;
	arv_new->arv_esq = arv_esq;
	arv_new->arv_dir = arv_dir;
	return arv_new;
}
/*
 * Função para mostrar a árvore em "pré-ordem".
 */
void arvoreImprime(Arvore *arv){
	if(arv!=NULL){
		printf("Nó: %d\n", arv->arv_inf);
		arvoreImprime(arv->arv_esq);
		arvoreImprime(arv->arv_dir);
	}
}