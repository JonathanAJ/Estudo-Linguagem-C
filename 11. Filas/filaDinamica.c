#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

typedef struct fila{
	Lista* ini;
	Lista* fim;
}Fila;

typedef struct lista{
	int info;
	Lista* prox;
}Lista;

Fila* filaCria();
Fila* filaInsere(Fila* f, int info);
int filaRetira(Fila* f);
int filaVazia(Fila* f);
void filaImprime(Fila* f);
void filaQntd(Fila* f);
void filaLibera(Fila* f);
Lista* filaBusca(Fila* f, int info);

int main(void){
	Fila* f = filaCria();
	f = filaInsere(f, 10);
	f = filaInsere(f, 20);
	f = filaInsere(f, 30);
	f = filaInsere(f, 40);
	f = filaInsere(f, 50);
	printf("Retirado: %d.\n", filaRetira(f));
	printf("Retirado: %d.\n", filaRetira(f));
	filaImprime(f);
	filaBusca(f, 30);
	filaQntd(f);
	filaLibera(f);
	return 0;
}

Fila* filaCria(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

Fila* filaInsere(Fila* f, int info){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->info = info;
	l->prox = NULL;
	if(f->fim!=NULL) // caso haja lista
		f->fim->prox = l; // a lista fim->prox recebe a nova lista
	else // se for a primeira vez, se ela estiver vazia
		f->ini = l; // o inicio recebe a lista
	f->fim = l; // o fim recebe a lista
}

int filaRetira(Fila* f){
	Lista* tmp;
	int info;
	if(filaVazia(f)){
		printf("Fila Vazia!\n");
		exit(1);
	}
	tmp = f->ini;
	info = tmp->info;
	f->ini = tmp->prox;
	if(f->ini==NULL)
		f->fim = NULL;
	free(tmp);
	return info;
}

int filaVazia(Fila* f){
	return (f->ini==NULL);
}

void filaImprime(Fila* f){
	Lista* aux = f->ini;
	while(aux!=NULL){
		printf("Info: %d.\n", aux->info);
		aux = aux->prox;
	}
}

void filaQntd(Fila* f){
	Lista* aux = f->ini;
	int cont = 0;
	while(aux!=NULL){
		cont++;
		aux = aux->prox;
	}
	printf("Quantidade de elementos é %d.\n", cont);
}

void filaLibera(Fila* f){
	Lista* aux = f->ini;
	Lista* tmp;
	while(aux!=NULL){
		tmp = aux->prox;
		free(aux);
		aux = tmp;
	}
	free(f);
}

Lista* filaBusca(Fila* f, int info){
	if(filaVazia(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	Lista* aux = f->ini;
	while(aux!=NULL){
		if(aux->info == info){
			break;
		}
		aux = aux->prox;
	}
	if(aux==NULL){
		printf("Elemento %d não encontrado.\n", info);
		return NULL;
	}else{
		printf("Elemento %d encontrado com sucesso.\n", info);
		return aux;
	}
}