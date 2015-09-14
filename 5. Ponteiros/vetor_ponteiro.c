#include <stdio.h>

/*
  Relação entre vetores e ponteiros.
  Duas formas existentes:
  - Acessar como vetor
  - Acessar com aritmética de ponteiros
*/

int main(void){
	//declaração do vetor e ponteiro
	int num[] = {50, 100, 150, 200},
		*pont;

	/*
	  Aqui o ponteiro recebe um outro ponteiro,
	  na verdade um vetor, que também é um ponteiro.
	  Por isso não há necessidade de '&'
	*/
	pont = num;
	/*
	  Acesso como vetor
	*/
	printf("\nAcesso como vetor:\n\n%d, %d, %d, %d.\n\n",
			pont[0],pont[1],pont[2],pont[3]);
	/*
	  Acesso com aritmética de ponteiros
	*/
	printf("Acesso com aritmética de ponteiros:\n\n%d, %d, %d, %d.\n\n",
			*(pont),*(pont+1),*(pont+2),*(pont+3));
	/*
	  Aritmética
	*/
	printf("---------\nAritmética de ponteiros\n");
	//incrementa o endereço de memoria para o prox.
	pont++;
	printf("pont++: %d\n\n", *pont);
	//incrementa o endereço de memoria para o prox.
	pont=pont+1;
	printf("OU\n\npont=pont+1: %d\n\n", *pont);

	printf("---------\nAritmética com valores de ponteiros\n");
	//incrementa o valor do ponteiro.
	(*pont)++;
	printf("(*pont)++: %d\n\n", *pont);
	//incrementa o valor do ponteiro.
	*pont=*pont+1;
	printf("OU\n\n*pont=*pont+1: %d\n\n", *pont);
	
	return 0;
}