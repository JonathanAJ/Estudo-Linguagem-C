#include <stdio.h>

int main(void){

	int *pon,
		 num,
		 i;

	for(i=0; i<=100; i++){
		num = i;
		pon = &num;
		printf("%d-%d\n", *pon, num);
	}

	return 0;
}