#include <stdio.h>

int main(void){
	//3 linhas e 5 colunas
	int mat[3][5] = {{10,20,30,40,50},
		{100,200,300,400,500},
		{1000,2000,3000,4000,5000}},
		i, j;

	for(i=0; i<3; i++){
		printf("{");
		for(j=0; j<5; j++){
			if(j==4){
				printf("%d}\n", mat[i][j]);
			}else{
				printf("%d ", mat[i][j]);
			}
		}
	}
	printf("%d\n", mat[0]);
	return 0;
}