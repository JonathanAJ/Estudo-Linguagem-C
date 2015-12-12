#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

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
int pilhaQntd(Pilha* p);

int main(void){
	Pilha* p;
	p = criaPilha();
	pushPilha(p, 10);
	pushPilha(p, 20);
	pushPilha(p, 30);
	pushPilha(p, 40);
	pushPilha(p, 50);
	pushPilha(p, 60);
	printf("Retirado: %d\n", popPilha(p));
	pilhaImprime(p);
	printf("Quantidade de elementos: %d.\n", pilhaQntd(p));
	pilhaLibera(p);
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
		printf("Pilha vazia!\n");
		exit(1);
	}
	Lista* aux = p->prime->prox;
	int info = p->prime->info;
	free(p->prime);
	p->prime = aux;
	return info;
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

int pilhaQntd(Pilha *p){
	if(pilhaVazia(p))
		return 0;
	Pilha* aux = p;
	int cont = 0;
	while(aux->prime!=NULL){
		cont++;
		aux->prime = p->prime->prox;
	}
	return cont;
}