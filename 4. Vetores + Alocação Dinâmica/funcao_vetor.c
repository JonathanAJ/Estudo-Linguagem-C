#include <stdio.h>
#include <stdlib.h>

void imprime(int* vet, int c);

int main(void){
	/*
	  Iniciando valores e requisitando a
	  alocação para o usuário.
	*/
	int i, c, *n;
	printf("Digite a alocaçao:\n");
	scanf("%d", &c);
	/*
	  malloc serve para alocar uma quantidade
	  de memoria livre. No caso está a alocar
	  a quantidade de bytes de um int determinado
	  pelo valor do usuário. É retornado um
	  endereço de memória guardado no ponteiro n.
	*/
	n = (int *) malloc(c*sizeof(int));
	/*
	  Se o valor retornado for NULL o programa é
	  encerrado e uma mensagem é mostrada.
	*/
	if(n==NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	/*
	  Scanea os números e os insere no ponteiro n.
	*/
	printf("\nDigite %d números:\n", c);
	for(i=0; i<c; i++)
		scanf("\n%d", &n[i]);
	imprime(n, c);
	return 0;
}

void imprime(int* vet, int c){
	int i;
	printf("\nVocê digitou:");
	for(i=0; i<c; i++){
		printf("\n%d ", vet[i]);
	}
	printf("\n\n");
}