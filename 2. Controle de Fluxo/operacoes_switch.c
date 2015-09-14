#include <stdio.h>

int main(void){
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

	return 0;
}
