#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

typedef struct lista{
	int info;
	Lista* prox;
}Lista;

Lista* listaCria();
Lista* inserirNoInicio(Lista* l, int info);
void listaImprime(Lista* l);
void listaQntd(Lista* l);
int listaVazia(Lista* l);
void listaPosicao(Lista* l, int info);
Lista* removeElemento(Lista* l, int info);
void alteraElemento(Lista* l, int info, int info_novo);
Lista* inserirQualquer(Lista* l, int info, int info_novo);
void listaLibera(Lista* l);

int main(void){
	Lista* l;
	l = listaCria();
	l = inserirNoInicio(l, 10);
	l = inserirNoInicio(l, 20);
	l = inserirNoInicio(l, 30);
	l = inserirNoInicio(l, 40);
	l = removeElemento(l, 40);
	alteraElemento(l, 30, 33);
	l = inserirQualquer(l, 20, 52);
	l = inserirQualquer(l, 20, 42);
	l = inserirQualquer(l, 33, 4);
	listaImprime(l);
	listaQntd(l);
	listaPosicao(l, 33);
	listaLibera(l);
	return 0;
}

Lista* listaCria(){
	return NULL;
}

Lista* inserirNoInicio(Lista* l, int info){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = l;
	return novo;
}

Lista* inserirQualquer(Lista* l, int info, int info_novo){
	Lista* aux = l;
	Lista* ant = NULL;
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	while(aux!=NULL){
		if(aux->info == info){
			if(ant==NULL){
				novo->info = info_novo;
				novo->prox = l;
				printf("Elemento %d inserido com sucesso!\n", info_novo);
				return novo;
			}
			else{
				novo->info = info_novo;
				ant->prox = novo;
				novo->prox = aux;
				printf("Elemento %d inserido com sucesso!\n", info_novo);
				return l;
			}
			break;
		}
		ant = aux;
		aux = aux->prox;
	}
	if(aux==NULL){
		printf("Elemento %d não encontrado.\n", info);
		return l;
	}
}

void listaImprime(Lista* l){
	Lista* aux = l;
	while(aux!=NULL){
		printf("Info: %d.\n", aux->info);
		aux = aux->prox;
	}
}

void listaQntd(Lista* l){
	Lista* aux = l;
	int cont = 0;
	while(aux!=NULL){
		cont++;
		aux = aux->prox;
	}
	printf("Quantidade de elementos: %d.\n", cont);
}

int listaVazia(Lista* l){
	return (l==NULL);
}

void listaPosicao(Lista* l, int info){
	Lista* aux = l;
	int cont = 0;
	while(aux!=NULL){
		if(aux->info == info){
			cont++;
			break;
		}
		else{
			cont++;
		}
		aux = aux->prox;
	}
	if(aux==NULL)
		printf("Elemento %d não encontrado.\n", info);
	else
		printf("Posição do elemento %d é a %dª.\n", info, cont);
}

Lista* removeElemento(Lista* l, int info){
	if(listaVazia(l)){
		printf("Lista vazia!\n");
		exit(1);
	}
	Lista* aux = l;
	Lista* ant = NULL;
	while(aux!=NULL){
		if(aux->info == info){
			if(ant==NULL)
				l = l->prox;
			else
				ant->prox = aux->prox;
			free(aux);
			break;
		}
		ant = aux;
		aux = aux->prox;
	}
	if(aux==NULL){
		printf("Elemento %d não encontrado.\n", info);
		return l;
	}
	else{
		printf("Elemento %d removido com sucesso!\n", info);
		return l;
	}
}

void alteraElemento(Lista* l, int info, int info_novo){
	Lista* aux = l;
	while(aux!=NULL){
		if(aux->info == info){
			aux->info = info_novo;
			break;
		}
		aux = aux->prox;
	}
	if(aux==NULL){
		printf("Elemento %d não encontrado.\n", info);
	}
	else{
		printf("Elemento %d alterado com sucesso para %d!\n", info, info_novo);
	}
}

void listaLibera(Lista* l){
	Lista* aux = l;
	Lista* tmp;
	while(aux!=NULL){
		tmp = aux->prox;
		free(aux);
		aux = tmp;
	}
}