#include <stdio.h>
#include <math.h>

typedef struct torre{
	int n;
	char posicao;
}Torre;

int main(void){
	int i, n=3, mv;

	printf("Quantos discos há na torre?\n");
	scanf("%d", &n);
	
	mv = (pow(2, n))-1;

	Torre origem;
	Torre destino;
	Torre auxiliar;

	origem.n=n;
	destino.n=0;
	auxiliar.n=0;

	origem.posicao='A';
	destino.posicao='C';
	auxiliar.posicao='B';

	for(i=1; i<=mv; i++){
		// Se PAR
		if(origem.n%2==0){
			printf("Mova %d de %c para %c.\n", destino.n, destino.posicao, origem.posicao);
			origem.n = destino.n;
			destino.n = destino.n-1;
		}else{
			printf("Mova %d de %c para %c.\n", auxiliar.n, auxiliar.posicao, destino.posicao);
			destino.n = auxiliar.n;
			auxiliar.n = auxiliar.n-1;
		}
	}
	return 0;
}