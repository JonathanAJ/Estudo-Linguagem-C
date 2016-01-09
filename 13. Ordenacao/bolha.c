#include <stdio.h>
#define N 8

void ordenaBolha(int n, int *v);

int main(void){
	int i;
	int v[N] = {12, 9, 88, 55, 3, 7, 190, 135};
	// Imprime valores sem a função de ordenar
	printf("Sem ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	// chama a função que ordena
	ordenaBolha(N, v);
	// Imprime valores com a função de ordenar
	printf("Com ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	return 0;
}

void ordenaBolha(int n, int *v){
	int i, j;
	/*
	 * Primeiro laço serve para verificar até onde
	 * a comparação deve ser executada.
	 * 'i' recebe o final comparado do vetor.
	 */
	for(i=n-1; i>=1; i--){
	/*
	 * Segundo laço faz as comparações.
	 */
		for(j=0; j<i; j++){
			/*
			 * Se o elemento for maior que o próximo, troca.
			 */
			if(v[j]>v[j+1]){
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}