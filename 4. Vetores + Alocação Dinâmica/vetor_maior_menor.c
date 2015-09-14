#include <stdio.h>

int main(void){
	int num[10],
		maior,
		menor,
		i;

	printf("Digite 10 valores:\n");
	for(i=0; i<10; i++){
		scanf("%d", &num[i]);
		if(i==0){
			menor = num[i];
			maior = num[i];
		}
		if(num[i]>maior)
			maior = num[i];
		else if(num[i]<menor)
			menor = num[i];
	}
	printf("O menor valor é %d e o maior é %d\n", menor, maior);
	return 0;
}