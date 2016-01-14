#include <stdio.h>
#define N 8

void ordenaInsercao(int n, int *v);

int main(void){
	int i;
	int v[N] = {12, 9, 88, 55, 3, 7, 190, 135};
	// Imprime valores sem a função de ordenar
	printf("Sem ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	// chama a função que ordena
	ordenaInsercao(N, v);
	// Imprime valores com a função de ordenar
	printf("Com ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	return 0;
}

void ordenaInsercao(int n, int *v){
	int i, j, x;

	for(i=1; i<n; i++){
		x = v[i];
		for(j=i-1; j>=0 && v[j]>x; j--){
			v[j+1] = v[j];
		}
		v[j+1] = x;
	}
}
