#include <stdio.h>

/* Protótipo */ 
void imprime();

int main(void){
	int i=0;
	while(i<10){
		imprime();
		i++;
	}
	return 0;
}

void imprime(){
	/*
	 Aqui o estatic é utilizado para
	 deixar o valor da variável estática.
	 Ou seja, se a função for chamada mais
	 de uma vez ela preservará o valor.
	 -
	 Diferente se fosse:
		int cont=0;
	*/
	static int cont=0;
	printf("- %d\n", cont);
	cont++;
}