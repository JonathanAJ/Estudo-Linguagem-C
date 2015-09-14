#include <stdio.h>
/*
 * Exercício para definir se um ponto está dentro
 * ou fora de um retângulo.
 */

// definindo o tipo Ponto
typedef struct ponto Ponto;
/*
 * Protótipo da função
 */
int pontoRet(Ponto *v1, Ponto *v2, Ponto *p);
/*
 * Criando um tipo Struct Ponto
 */
struct ponto{
 	int x, y;
};
// função principal
int main(void){
	// declarando os pontos
	Ponto v1, v2, p;
	// declarando o resultado
	int res;
	// inicializando o ponto do vértice 1
	v1.x = 1;
	v1.y = 1;
	// inicializando o ponto do vértice 2
	v2.x = 4;
	v2.y = 4;
	// inicializando um ponto qualquer
	p.x = 3;
	p.y = 3;
	// chamando a função que calcula se está dentro ou fora
	res = pontoRet(&v1, &v2, &p);
	// imprimindo resultado
	if(res==0){
		printf("O ponto está fora!\n");
	}else{
		printf("O ponto está dentro!\n");
	}
	return 0;
}

int pontoRet(Ponto *v1, Ponto *v2, Ponto *p){
	if(((p->x)>(v2->x) || (p->x)<(v1->x)) || (p->y)>(v2->y) || (p->y)<(v1->y)){
		return 0;
	}else{
		return 1;
	}
}