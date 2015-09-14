#include <stdio.h>

main(void){
	int v1, v2;

	printf("\nDigite um valor:\n");
	scanf("%i", &v1);

	printf("\nDigite um segundo valor:\n");
	scanf("  %i", &v2);

	int soma = v1+v2;

	printf("\n\tA soma dos valores é %i.\n\n", soma);

	return(0);
}