#include <stdio.h>

int main(void){
	/*
	 * Guarda em um vetor de char cada letra do
	 * meu nome. 
	 */
	char nome[] = {'J','o','n','a','t','h','a','n'};
	// não há necessidade de & pois um vetor é um ponteiro
	printf("%s\n", nome);
	return 0;
}