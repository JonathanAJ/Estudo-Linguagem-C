#include <stdio.h>
#include <stdlib.h>
/*
 * Primeiro é criada uma estrutura lista que guarda uma
 * informação e um ponteiro(endereço) para a próxima lista.
 * Já que as listas servem para guardar um endereço de memória
 * dinâmico, porém como é dinâmico não há como manipular se-
 * quencialmente, sendo assim é necessário encadear cada infor-
 * mação com o endereo da próxima informação.
 */
struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

/*
 * Protótipos das funções.
 */
Lista* criaLista();
Lista* insereLista(Lista *ls, int novo_info);
void mostraLista(Lista *ls);
/*
 * Função principal.
 */
int main(void){
	/*
	 * Primeiramente é criado um ponteiro para o tipo Lista.
	 * que recebe o valor de retorno de crialista(), que é,
	 * no caso NULL. Logo, uma lista vazia é criada.
	 */
	Lista *ls = criaLista();
	/*
	 * Depois chamo a função insereLista() quantas vezes for
	 * necessária, tendo como parâmetros: a lista criada e o
	 * valor que se quer colocar na informação. Ela retorna
	 * o novo valor da lista que é atualizada na variável ls.
	 * Sem isso o valor se perde na função e a lista não atualiza.
	 */
	ls = insereLista(ls, 9);
	ls = insereLista(ls, 8);
	ls = insereLista(ls, 7);
	ls = insereLista(ls, 6);
	ls = insereLista(ls, 5);
	ls = insereLista(ls, 4);
	ls = insereLista(ls, 3);
	ls = insereLista(ls, 2);
	ls = insereLista(ls, 1);
	ls = insereLista(ls, 0);
	/*
	 * Chamada da função mostraLista() que tem como parametro a
	 * lista que se quer mostrar.
	 */
	mostraLista(ls);
	return 0;
}
/*
 * Função criaLista() que retorna um ponteiro para uma Lista NULL
 */
Lista* criaLista(){
	return NULL;
}
/*
 * Função insereLista() que necessita do ponteiro da lista e a info.
 */
Lista* insereLista(Lista *ls, int novo_info){
	/* Aqui nós alocamos memória do tamanho de lista e inicializamos
	   uma variável ponteiro para Lista chamada ls_novo. */
	Lista* ls_novo = (Lista *) malloc(sizeof(Lista));
	// Agora ls_novo->info recebe o valor digitado no parâmetro.
	ls_novo->info = novo_info;
	/*
	 * ls_novo->prox recebe o valor de um ponteiro para Lista que 
	 * indica a lista "anterior"(basicamente o próximo é o valor anterior)
	 * pois a lista é invertida a cada alocação de dado.
	 */
	ls_novo->prox = ls;
	/*
	 * O retorno da função é um ponteiro Lista que é o nova lista criada.
	 * Isso é primordial pois os valores serão perdidos após o término da
	 * função. Porém, uma outra forma é setar dentro da própria função, mas
	 * seria necessário um ponteiro para ponteiro, algo mais complexo.
	 */
	return ls_novo;
}
/*
 * A função mostraLista() printa os valores de uma determinada lista na tela.
 * Ela se utiliza de um ponteiro Lista para a repetição, funcionando como uma
 * variável auxiliar da mesma forma do i dentro do vetor (vet[i]).
 */
void mostraLista(Lista *ls){
	Lista *p;
	printf("-Início-\n");
	/*
	 * Ponteiro p é igual a lista populada, o loop vai até p ser diferente de NULL.
	 * A cada fim do lado p recebe um ponteiro de p->prox, printando na tela todas
	 * as informações necessárias.
	 */
	for(p=ls; p!=NULL; p=p->prox){
		printf("Info: %d.\n", p->info);
	}
}