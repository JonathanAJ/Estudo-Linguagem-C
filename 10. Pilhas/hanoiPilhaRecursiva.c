#include <stdio.h>
#include <stdlib.h>
/*
  Criando protótipo do tipo Lista
*/
typedef struct lista Lista;
/*
  Criando Tipo Lista e Pilha.
  A pilha também tem o nome da Torre.
*/
typedef struct lista{
	int info;
	Lista* prox;
}Lista;

typedef struct pilha{
	char torreNome;
	Lista* prime;
}Pilha;
/*
  Protótipos das funções
*/
Pilha* criaPilha(char torreNome);
void pushPilha(Pilha* p, int info);
int popPilha(Pilha* p);
int pilhaVazia(Pilha* p);
void pilhaLibera(Pilha* p);
char printNome(Pilha* p);
void populaPilha(Pilha* p, int N);
void transfere(int N, Pilha* org, Pilha* des, Pilha* aux);
void pilhaImprime(Pilha* p);
void display(int info, Pilha* org, Pilha* des, Pilha* aux);
/*
  Função principal
*/
int main(void){
	/*
  	  Pedindo ao usuário a quantidade de discos.
	*/
	int N;
	while(N<2){
		printf("Quantos discos há na torre de origem?\n");
		scanf("%d", &N);
		if(N<2)
			printf("O número deve ser maior que um. Tente novamente.\n");
	}
	/*
  	  Criando e inicializando as pilhas com o nome da torre.
  	  Cada torre é uma pilha que será manipulada pelo programa.
	*/
	Pilha *org, *des, *aux;
	org = criaPilha('A');
	des = criaPilha('B');
	aux = criaPilha('C');
	/*
	  Popula-se a torre origem 'A' com o número de 
	  discos do usuário. Após, chama a função transfere
	  para fazer os devidos movimentos da torre.
	*/
	populaPilha(org, N);
	transfere(N, org, des, aux);
	printf("\n");
	return 0;
}

void transfere(int N, Pilha* org, Pilha* des, Pilha* aux){
	if(N>0){
		transfere(N-1, org, aux, des);
		/*
  		  Função pop para retirar da pilha o valor. E função
  		  push para colocar na pilha o valor.
		*/
		int info = popPilha(org);
		pushPilha(des, info);
		/*
  		  Função que printa o conteúdo das pilhas, bem como o
  		  número do disco que foi retirado.
		*/
		display(info, org, des, aux);
		transfere(N-1, aux, des, org);
	}
}

void display(int info, Pilha* org, Pilha* des, Pilha* aux){
	printf("\n  +> Move disco %d de %c para %c.\n", info, org->torreNome, des->torreNome);
	printf("  | ");
	printf("\n| %c |\n", printNome(org));
	pilhaImprime(org);

	printf("\n| %c |\n", printNome(des));
	pilhaImprime(des);

	printf("\n| %c |\n", printNome(aux));
	pilhaImprime(aux);
}

void populaPilha(Pilha* p, int N){
	int i=1;
	while(i<=N){
		pushPilha(p, i);
		i++;
	}
}

Pilha* criaPilha(char torreNome){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	if(p==NULL)
		exit(1);
	p->torreNome = torreNome;
	p->prime = NULL;
	return p;
}

void pushPilha(Pilha* p, int info){
	Lista* item = (Lista*) malloc(sizeof(Lista));
	item->info = info;
	item->prox = p->prime;
	p->prime = item;
}

int popPilha(Pilha* p){
	if(pilhaVazia(p)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	Lista* aux = p->prime->prox;
	int info = p->prime->info;
	free(p->prime);
	p->prime = aux;
	return info;
}

char printNome(Pilha* p){
	return p->torreNome;
}

void pilhaLibera(Pilha* p){
	while(p->prime!=NULL){
		Lista* tmp = p->prime->prox;
		free(p->prime);
		p->prime = tmp;
	}
	free(p);
}

int pilhaVazia(Pilha* p){
	return(p->prime==NULL);
}

void pilhaImprime(Pilha* p){
	Lista* aux = p->prime;
	while(aux!=NULL){
		printf("+ %d +\n", aux->info);
		aux = aux->prox;
	}
}
