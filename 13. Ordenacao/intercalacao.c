#include <stdio.h>
#define N 8

void mergesort(int p, int r, int *v);
void intercala(int p, int q, int r, int *v);

int main(void){
	int i;
	int v[N] = {12, 9, 88, 55, 3, 7, 190, 135};
	// Imprime valores sem a função de ordenar
	printf("Sem ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	// chama a função que ordena
	mergesort(0, N, v);
	// Imprime valores com a função de ordenar
	printf("Com ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	return 0;
}

void mergesort(int p, int r, int *v){
	int q;
	if (p<r-1) {
		q=(p+r)/2;
		mergesort(p, q, v);
		mergesort(q, r, v);
		intercala(p, q, r, v);
	}
}

void intercala(int p, int q, int r, int *v){
	int i, j, k, w[N];
	i = p;
	j = q;
	k = 0;
	while(i<q && j<r){
		if(v[i]<v[j]){
			w[k]=v[i];
			i++;
		}
		else{
			w[k]=v[j];
			j++;
		}
		k++;
	}
	while(i<q){
		w[k] = v[i];
		i++;
		k++;
	}
	while(j<r){
		w[k] = v[j];
		j++;
		k++;
	}
	for(i=p; i<r; i++){
		v[i] = w[i-p];
	}
}