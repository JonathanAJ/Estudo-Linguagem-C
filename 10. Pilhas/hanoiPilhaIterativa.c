#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
void transfere(int N, Pilha* org, Pilha* des, Pilha* aux);
void moveDiscoEntreDoisPontos(Pilha *org, Pilha *des, Pilha* aux);
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
	/*
	  Inicializando contador para verificar o tempo
	  de execução da função transfere recursiva
	*/
	// inicializando tipo clock
	clock_t inicio, fim;
	// tempo até aqui
	inicio = clock();
	/*
	  Inicializando função que transfere os discos.
	*/
	transfere(N, org, des, aux);
	// tempo até aqui
	fim = clock();
	// cálculo do tempo
	double total;
	total = (double) (fim - inicio)/CLOCKS_PER_SEC;
	printf("\n+++++> Tempo de execução foi de %.5f segundos.\n\n", total);
	return 0;
}

void transfere(int N, Pilha* org, Pilha* des, Pilha* aux){
	
	int i, totalMovimentos;

    totalMovimentos = pow(2, N) - 1;
	/*
	  Se o número de discos for par, troque
	  a torre de destino com o auxiliar.
	*/
    if(N % 2 == 0){
        char temp = des->torreNome;
        des->torreNome = aux->torreNome;
        aux->torreNome  = temp;
    }
	for(i=1; i<=totalMovimentos; i++){
        if(i % 3 == 1){
          moveDiscoEntreDoisPontos(org, des, aux);
        
        }else if (i % 3 == 2){
          moveDiscoEntreDoisPontos(org, aux, des);
        
        }else if (i % 3 == 0){
          moveDiscoEntreDoisPontos(aux, des, org);
        }
    }
}

void moveDiscoEntreDoisPontos(Pilha *org, Pilha *des, Pilha* aux){
	// Para saber qual o topo da pilha
    int poloUmTopo = popPilha(org);
    int poloDoisTopo = popPilha(des);
    // Quando o PoloUm estiver vazio
    if(poloUmTopo == -1){
        pushPilha(org, poloDoisTopo);
        display(poloDoisTopo, des, org, aux);
    }
    // Quando o PoloDois estiver vazio
    else if(poloDoisTopo == -1){
        pushPilha(des, poloUmTopo);
        display(poloUmTopo, org, des, aux);
    }
    // Quando o topo do poloUm > topo do poloDois
    else if(poloUmTopo > poloDoisTopo){
        pushPilha(org, poloUmTopo);
        pushPilha(org, poloDoisTopo);
        display(poloDoisTopo, des, org, aux);
    }
    // Quando o topo do poloUm < topo do poloDois
    else{
        pushPilha(des, poloDoisTopo);
        pushPilha(des, poloUmTopo);
        display(poloUmTopo, org, des, aux);
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
	while(N>=i){
		pushPilha(p, N);
		N--;
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
		return -1;
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
