#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *v, n;
	printf("Digite a quantidade de Inteiros para alocação dinâmica:\n");
	scanf("%d", &n);
	v = (int*) malloc(n*sizeof(int));
	if(v==NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}else{
		printf("A memória foi alocada!\n");
		free(v);
		printf("A memória foi limpa com free()!\n");
	}
	return 0;
}