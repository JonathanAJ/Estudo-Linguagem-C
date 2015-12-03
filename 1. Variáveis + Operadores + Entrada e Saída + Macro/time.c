#include <stdio.h>
#include <time.h>

int main(){
	double total;
	// inicializando tipo clock
	clock_t inicio, fim;
	int a=1;
	// tempo até aqui
	inicio = clock();
	// laço de teste
	while(a<100000000){
		a++;
	}
	// tempo até aqui
	fim = clock();
	// cálculo do tempo
	total = (double) (fim - inicio)/CLOCKS_PER_SEC;
	printf("TOTAL = %.2f seg.\n", total);
	return 0;
}