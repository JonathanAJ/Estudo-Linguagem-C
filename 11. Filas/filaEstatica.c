#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct fila{
	int n;
	int ini;
	int info[N];
}Fila;

Fila* filaCria();
void filaInsere(Fila* f, int info);
int filaRetira(Fila* f);
int filaVazia(Fila* f);
void filaImprime(Fila* f);
void filaQntd(Fila* f);
void filaLibera(Fila* f);
int filaBusca(Fila* f, int info);

int main(void){
	Fila* f = filaCria();
	filaInsere(f, 10);
	filaInsere(f, 20);
	filaInsere(f, 30);
	filaInsere(f, 40);
	filaInsere(f, 50);
	printf("Retirado: %d.\n", filaRetira(f));
	printf("Retirado: %d.\n", filaRetira(f));
	filaInsere(f, 60);
	filaInsere(f, 70);
	filaImprime(f);
	filaBusca(f, 50);
	filaQntd(f);
	filaLibera(f);
	return 0;
}

Fila* filaCria(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

void filaInsere(Fila* f, int info){
	int fim;
	if(f->n==N){
		printf("Fila cheia!\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->info[fim] = info;
	f->n++;
}

int filaRetira(Fila* f){
	int info;
	if(filaVazia(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	info = f->info[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	return info;
}

int filaVazia(Fila* f){
	return (f->n==0);
}

void filaImprime(Fila* f){
	int i = 0;
	int k;
	while(i < f->n){
		k = (f->ini + i)%N;
		printf("Info: %d.\n", f->info[k]);
		i++;
	}
}

void filaQntd(Fila* f){
	int i = 0, cont = 0;
	while(i < f->n){
		cont++;
		i++;
	}
	printf("Quantidade de elementos é %d.\n", cont);
}

void filaLibera(Fila* f){
	free(f);
}

int filaBusca(Fila* f, int info){
	if(filaVazia(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	int i = 0;
	int k;
	while(i < f->n){
		k = (f->ini + i)%N;
		if(f->info[k] == info){
			printf("Elemento %d encontrado com sucesso.\n", info);
			return k;
			break;
		}
		i++;
	}
	if(i == f->n){
		printf("Elemento %d não encontrado.\n", info);
		return f->ini;
	}
}