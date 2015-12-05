#include <stdio.h>
#include <math.h>
 
typedef struct torre{
	int n;
	char posicao;
}Torre;

int main(void){
	int i, n=2, mv;

	// printf("Quantos discos há na torre?\n");
	// scanf("%d", &n);
	
	mv = (pow(2, n))-1;

	Torre origem;
	Torre destino;
	Torre auxiliar;

	origem.n=n;
	destino.n=0;
	auxiliar.n=0;

	origem.posicao='A';
	auxiliar.posicao='B';
	destino.posicao='C';

	for(i=1; i<=mv; i++){
		// Se o disco for PAR
		if(origem.n%2==0){
			if(origem.n==0){
				printf("Mova %d de %c para %c.\n", destino.n, destino.posicao, origem.posicao);
				origem.n = destino.n;
				destino.n = destino.n-1;
			}else{
				printf("Mova %d de %c para %c.\n", origem.n, origem.posicao, destino.posicao);
				destino.n = origem.n;
				origem.n = origem.n-1;
			}
		// Se o disco for IMPAR
		}else{	
			// Se a torre visionada tiver um PAR	
			if(auxiliar.n%2==0){
				printf("Mova %d de %c para %c.\n", origem.n, origem.posicao, auxiliar.posicao);
				auxiliar.n = origem.n;
				origem.n = origem.n-1;
			// Se a torre visionada tiver um IMPAR
			}else{
				printf("Mova %d de %c para %c.\n", auxiliar.n, auxiliar.posicao, destino.posicao);
				destino.n = auxiliar.n;
				auxiliar.n = auxiliar.n-1;
			}
		}
	}
	return 0;
}
