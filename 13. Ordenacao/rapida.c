#include <stdio.h>
#define N 8

void ordenaRapida(int n, int *v);

int main(void){
	int i;
	int v[N] = {12, 9, 88, 55, 3, 7, 190, 135};
	// Imprime valores sem a função de ordenar
	printf("Sem ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	// chama a função que ordena
	ordenaRapida(N, v);
	// Imprime valores com a função de ordenar
	printf("Com ordenação: \n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	printf("\n");
	return 0;
}

void ordenaRapida(int n, int *v){
	/*
	 * Senão houver elementos suficientes para ordenar.
	 */
	if(n<=1)
		return;
	else{
		/*
		 * O pivô inicia no 1º elemento.
		 * O índice esquerdo no próximo.
		 * O índice direito no último.
		 */
		int pivo = v[0];
		int iEsquerdo = 1;
		int iDireito = n-1;
		do {
			while(iEsquerdo<=iDireito && v[iEsquerdo]<=pivo)
				iEsquerdo++;
			while(v[iDireito]>pivo)
				iDireito--;
			if(iEsquerdo<iDireito){
				int tmp = v[iEsquerdo];
				v[iEsquerdo] = v[iDireito];
				v[iDireito] = tmp;
				iEsquerdo++;
				iDireito--;
			}
		} while (iEsquerdo<=iDireito);
		/*
		 * Aqui há a troca do pivô
		 */
		 v[0] = v[iDireito];
		 v[iDireito] = pivo;
		/*
		 * Ordenação recursiva dos subarranjos
		 */
		 ordenaRapida(iDireito, v);
		 ordenaRapida(n-iEsquerdo, &v[iEsquerdo]);
	}
}