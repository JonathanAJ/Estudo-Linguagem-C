#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct pilha{
	int topo;
	int info[N];
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
	pilhaImprime(p);
	printf("Retirado %d.\n\n", popPilha(p));
	pilhaImprime(p);
	printf("Quantidade de elementos: %d.\n", pilhaQntd(p));
	return 0;
}

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	if(p==NULL)
		exit(1);
	p->topo = 0;
	return p;
}

void pushPilha(Pilha* p, int info){
	if(p->topo==N){
		printf("Pilha cheia!\n");
		exit(1);
	}
	p->info[p->topo] = info;
	p->topo++;
}

int popPilha(Pilha* p){
	if(pilhaVazia(p)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	int info;
	info = p->info[p->topo-1];
	p->topo--;
	return info;
}

int pilhaVazia(Pilha* p){
	return (p->topo==0);
}

void pilhaImprime(Pilha* p){
	int i;
	for(i = p->topo-1; i >= 0; i--){
		printf("Info: %d.\n", p->info[i]);
	}
}

int pilhaQntd(Pilha* p){
	return p->topo;
}


