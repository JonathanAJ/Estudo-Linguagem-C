#include <stdio.h>

int main(void){
	/*
	 * Inicializa um vetor de char com 30 posições
	 */
	char nome[30];
	printf("Insira seu primeiro nome:\n");
	scanf("%s", nome);
	printf("O nome digitado foi %s.\n",nome);
	return 0;
}