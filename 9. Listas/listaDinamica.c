#include <stdio.h>

typedef struct lista Lista;

typedef struct lista{
	int info;
	Lista* prox;
}Lista;

Lista* criaLista();
void inserirNoInicio(Lista* l, int info);

int main(void){
	Lista* l;
	l = criaLista();
	return 0;
}

Lista* criaLista(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prox = NULL;
	return l;
}

void inserirNoInicio(Lista* l, int info){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = l;
	return novo;
}

void inserirQualquer(Lista* l, int info, int elemento){

}