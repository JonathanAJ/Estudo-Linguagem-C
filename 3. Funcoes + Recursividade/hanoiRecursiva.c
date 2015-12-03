#include <stdio.h>

void transfere(int N, char org, char des, char aux){
	if(N==1){
		printf("Move disco de %c para %c.\n", org, des);
	}else{
		transfere(N-1, org, aux, des);
		printf("Move disco de %c para %c.\n", org, des);
		transfere(N-1, aux, des, org);
	}
}

int main(void){
	int N;
	char org='A', des='B', aux='C';

	printf("Quantos discos há na torre?\n");
	scanf("%d", &N);
	if(N>0){
		transfere(N, org, des, aux);
	}else{
		printf("\nDigite um número maior que 0.");
	}
	return 0;
}