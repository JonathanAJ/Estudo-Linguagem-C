#include <stdio.h>

// prototipos de funções
void operacoes(void);
void par_impar(void);

int main(void){
	int op;

	printf("Operações(1) ou Par/Impar(2)?");
	scanf("%d", &op);

	switch(op){
		case 1:
			operacoes();
		break;
		case 2:
			par_impar();
		break;
		default:
			printf("Valor Inválido!\n");
		break;
	}
}

void operacoes(void){
	int num1, num2, res;
	char op;

	printf("\n\tDigite um número:\n\t");
	scanf("%d", &num1);

	printf("\n\tDigite uma operação (Ex: |+|-|*|/|):\n\t");
	scanf(" %c", &op);

	printf("\n\tDigite outro número:\n\t");
	scanf("%d", &num2);

	switch(op){
		case '+':
			res = num1 + num2;
		break;
		case '-':
			res = num1 - num2;
		break;
		case '*':
			res = num1 * num2;
		break;
		case '/':
			res = num1 / num2;
		break;
		default:
			res = (char) 'x';
		break;
	}

	if(res!='x'){
		printf("\n\tO resultado é %d.\n\n", res);
	}else{
		printf("\n\tOperação Inválida!\n\n");
	}
}

void par_impar(void){
	int num;

	printf("\n\tDigite um número para saber se é IMPAR ou PAR:\n\t");
	scanf("%i", &num);

	int res = num%2;

	if(res==0){
		printf("\tNúmero %i é par!\n\n", num);
	}else{
		printf("\tNumero %i é impar!\n\n", num);
	}
}