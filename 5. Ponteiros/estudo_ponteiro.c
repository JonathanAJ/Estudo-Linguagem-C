#include <stdio.h>

int main(void){

	//declarei duas vars comuns e uma var ponteiro com (*)
	int num1, num2, *pon;

	//valor de num1 é 10
	num1 = 10;
	//valor do ponteiro é o endereço de num1 com (&)
	pon = &num1;
	//setando o conteudo do ponteiro para 7
	*pon = 7;
	//num2 recebe valor de num1 + conteudo do ponteiro
	num2 = num1 + *pon;
	
	/*
	 * Logo, o valor de num1 é 7, pois o conteúdo do
	 * ponteiro era o endereço de memória de num1.
	 */

	printf("Valor: %d Resultado: %d \n", num1, num2);
	//Saída -> Valor: 7 Resultado: 14
}