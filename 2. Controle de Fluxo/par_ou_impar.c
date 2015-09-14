#include "stdio.h"

main(void){
	int num;

	printf("\n\tDigite um número para saber se é IMPAR ou PAR:\n\t");
	scanf("%i", &num);

	int res = num%2;

	if(res==0){
		printf("\tNúmero %i é par!\n\n", num);
	}else{
		printf("\tNumero %i é impar!\n\n", num);
	}
	return 0;
}