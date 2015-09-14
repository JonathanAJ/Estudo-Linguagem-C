#include <stdio.h>

/*
 * Inicializando uma estrutura "coordenada" que irá
 * agrupar duas variaveis x e y.
 */

struct coordenada{
	int x;
	int y;
};

int main(void){
	/*
 	 * Inicializando uma variavel cood1 que é
 	 * uma estrutura coordenada. Setando x e y com
 	 * o uso do ponto(.)
	 */
	struct coordenada cood1;
	cood1.x = 10;
	cood1.y = 20;
	printf("Coordenada x é %d e y é %d.\n", cood1.x, cood1.y);
	
	/*
	 * Abaixo utilizo o typedef que é utilizado para definir
	 * novos tipos de dados. O código abaixo significa que
	 * estou definindo um tipo de estrutura coordenada como
	 * Coordenada. Após isso o novo tipo pode ser inicializado
	 * com um contexto mais simples.
	 */
	typedef struct coordenada Coordenada;
	/*
	 * Criando uma variável do tipo Coordenada chamada cd1.
	 */
	Coordenada cd1;
	cd1.x = 1;
	cd1.y = 2;
	printf("Coordenada x é %d e y é %d.\n", cd1.x, cd1.y);

	return 0;
}