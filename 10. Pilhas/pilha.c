#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int info;
	Lista* prox;
}Lista;

typedef struct pilha{
	Lista* prime;
}Pilha;

Pilha* criaPilha(void);
void pushPilha(Pilha* p, int info);
int popPilha(Pilha* p);
int pilhaVazia(Pilha* p);
void pilhaLibera(Pilha* p);
void pilhaImprime(Pilha* p);


void main(void){
	
	Pilha* p;
	p = criaPilha();
	pushPilha(p, 10);
	pushPilha(p, 20);
	pushPilha(p, 30);
	pushPilha(p, 40);
	pushPilha(p, 50);
	pushPilha(p, 60);
	popPilha(p);
	pilhaImprime(p);

	return 0;
}

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	if(p==NULL)
		exit(1);
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
		printf("Pilha vazia!");
		exit(1);
	}

	Lista* aux = p->prime->prox;
	free(p->prime);
	p->prime = aux;
}

void pilhaImprime(Pilha* p){
	Lista* aux = p->prime;
	while(aux!=NULL){
		printf("Info: %d\n", aux->info);
		aux = aux->prox;
	}
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