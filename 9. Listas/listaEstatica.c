#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct lista Lista;

typedef struct lista{
	int n;
	int info[N];
}Lista;

Lista* listaCria();
Lista* inserirNoFinal(Lista* l, int info);
void listaImprime(Lista* l);
void listaQntd(Lista* l);
int listaVazia(Lista* l);
void listaPosicao(Lista* l, int info);
void removeElemento(Lista* l, int info);
void alteraElemento(Lista* l, int info, int info_novo);
void inserirQualquer(Lista* l, int info, int info_novo);
void listaLibera(Lista* l);

int main(void){
	Lista* l;
	l = listaCria();
	inserirNoFinal(l, 10);
	inserirNoFinal(l, 20);
	inserirNoFinal(l, 30);
	inserirNoFinal(l, 40);
	removeElemento(l, 20);
	alteraElemento(l, 40, 44);
	inserirQualquer(l, 44, 55);
	inserirNoFinal(l, 60);
	listaImprime(l);
	listaQntd(l);
	listaPosicao(l, 44);
	listaLibera(l);
	return 0;
}

Lista* listaCria(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->n = 0;
	return l;
}

Lista* inserirNoFinal(Lista* l, int info){
	if(l->n==N){
		printf("Lista Cheia!\n");
		exit(1);
	}
	l->info[l->n] = info;
	l->n++;
}

void inserirQualquer(Lista* l, int info, int info_novo){
	if(l->n==N){
		printf("Lista Cheia!\n");
		exit(1);
	}
	int i=0;
	while(i!=N){
		if(l->info[i] == info){
			int j;
			for(j=l->n-1; j>=0; j--){
				l->info[j+1] = l->info[j];
				if(j==i)
					break;
			}
			l->info[i] = info_novo;
			break;
		}
		i++;
	}
	if(i==N){
		printf("Elemento %d não encontrado.\n", info);
	}
	else{
		printf("Elemento %d inserido com sucesso antes do %d!\n", info_novo, info);
		l->n++;
	}
}

void listaImprime(Lista* l){
	if(listaVazia(l)){
		printf("Lista vazia!\n");
		exit(1);
	}
	int i = 0;
	while(i!=l->n){
		printf("Info: %d.\n", l->info[i]);
		i++;
	}
}

void listaQntd(Lista* l){
	printf("Quantidade de elementos: %d.\n", l->n);
}

int listaVazia(Lista* l){
	return (l->n==0);
}

void listaPosicao(Lista* l, int info){
	if(listaVazia(l)){
		printf("Lista vazia!\n");
		exit(1);
	}
	int i = 0, cont = 1;
	while(i!=N){
		if(l->info[i] == info)
			break;
		i++;
		cont++;
	}
	if(i==N){
		printf("Elemento %d não encontrado.\n", info);
	}
	else{
		printf("Posição do elemento %d é a %dª.\n", info, cont);
	}
}

void removeElemento(Lista* l, int info){
	if(listaVazia(l)){
		printf("Lista vazia!\n");
		exit(1);
	}
	int i=0;
	while(i!=N){
		if(l->info[i] == info){
			for(i; i<=l->n; i++){
				l->info[i] = l->info[i+1];
			}
			break;
		}
		i++;
	}
	if(i==N){
		printf("Elemento %d não encontrado.\n", info);
	}
	else{
		printf("Elemento %d removido com sucesso!\n", info);
		l->n--;
	}
}

void alteraElemento(Lista* l, int info, int info_novo){
	if(listaVazia(l)){
		printf("Lista vazia!\n");
		exit(1);
	}
	int i=0;
	while(i!=N){
		if(l->info[i] == info){
			l->info[i] = info_novo;
			break;
		}
		i++;
	}
	if(i==N){
		printf("Elemento %d não encontrado.\n", info);
	}
	else{
		printf("Elemento %d alterado com sucesso para %d!\n", info, info_novo);
	}
}

void listaLibera(Lista* l){
	free(l);
}