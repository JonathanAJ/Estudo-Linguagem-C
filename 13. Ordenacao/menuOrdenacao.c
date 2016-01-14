#include <stdio.h>
#include <time.h>
#define N 20

void ordenaBolha(int n, int *v);
void ordenaInsercao(int n, int *v);
void ordenaRapida(int n, int *v);
void ordenaIntercala(int inicio, int fim, int *v);
void intercala(int p, int q, int r, int *v);

int main(){
	double total;
	clock_t inicio, fim;

	int i;
	int v[N] = {12, 9, 88, 55, 3, 7, 190, 135, 20, 87, 14, 90, 2, 4, 1, 265, 167, 0, 300, 44};
	// Imprime valores sem a função de ordenar
	printf("\nVamos ordenar os seguintes valores:\n\n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);
	
	int opcao;
	printf("\n\nEscolha qual o tipo de ordenação >>>>\n");
	printf("\n <1> Bolha\n <2> Inserção\n <3> Rápida\n <4> Intercalação\n\n");
	scanf(" %d", &opcao);
	if(opcao==1){
		printf("\nVocê escolheu Bolha!\n\n");
		inicio = clock();
		// chama a função que ordena
		ordenaBolha(N, v);
		fim = clock();
	}else if(opcao==2){
		printf("\nVocê escolheu Inserção!\n\n");
		inicio = clock();
		// chama a função que ordena
		ordenaInsercao(N, v);
		fim = clock();
	}else if(opcao==3){
		printf("\nVocê escolheu Rápida!\n\n");
		inicio = clock();
		// chama a função que ordena
		ordenaRapida(N, v);
		fim = clock();
	}else if(opcao==4){
		printf("\nVocê escolheu Intercalação!\n\n");
		inicio = clock();
		// chama a função que ordena
		ordenaIntercala(0, N, v);
		fim = clock();
	}else{
		printf("\nVocê escolheu um número inválido!\n\n");
		return 1;
	}
	// Imprime valores com a função de ordenar
	printf("Valores ordenados: \n\n");
	for(i=0; i<N; i++)
		printf(" - %d",v[i]);

	total = (double) (fim - inicio)/CLOCKS_PER_SEC;
	printf("\n\nTOTAL = %.7f seg.\n\n", total);
	return 0;
}

void ordenaBolha(int n, int *v){
	int i, j;
	/*
	 * Primeiro laço serve para verificar até onde
	 * a comparação deve ser executada.
	 * 'i' recebe o final comparado do vetor.
	 */
	for(i=n-1; i>=1; i--){
	/*
	 * Segundo laço faz as comparações.
	 */
		for(j=0; j<i; j++){
			/*
			 * Se o elemento for maior que o próximo, troca.
			 */
			if(v[j]>v[j+1]){
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}

//Ex: Ordenação do baralho de cartas
void ordenaInsercao(int n, int *v){
	int i, j, x;
	/*
	 * O laço inicia com 1 e vai até n-1, ou seja,
	 * o final do vetor.
	 */
	for(i=1; i<n; i++){
		/*
		 * X recebe o valor de índice 1.
		 */
		x = v[i];
		/*
		 * O segundo laço inicia j com o valor anterior 
		 * de i, nesse 1º caso é zero. Enquanto j for maior
		 * ou igual a zero e se o valor anterior for maior
		 * que o próximo, o próximo recebe o valor do anterior.
		 * Ou seja, se for maior desloca pra frente.
		 */
		for(j=i-1; j>=0 && v[j]>x; j--){
			v[j+1] = v[j];
		}
		/*
		 * j+1 receberá o valor do x guardado anteriormente.
		 */
		v[j+1] = x;
	}
}

void ordenaRapida(int n, int *v){
	/*
	 * Senão houver elementos suficientes para ordenar.
	 */
	if(n<=1)
		return;
	else{
		/*
		 * O pivô inicia no 1º elemento.
		 * O índice esquerdo no próximo.
		 * O índice direito no último.
		 */
		int pivo = v[0];
		int iEsquerdo = 1;
		int iDireito = n-1;
		do {
			while(iEsquerdo<=iDireito && v[iEsquerdo]<=pivo)
				iEsquerdo++;
			while(v[iDireito]>pivo)
				iDireito--;
			if(iEsquerdo<iDireito){
				/*
				 * Troca dos elementos
				 */
				int tmp = v[iEsquerdo];
				v[iEsquerdo] = v[iDireito];
				v[iDireito] = tmp;
				iEsquerdo++;
				iDireito--;
			}
		} while (iEsquerdo<=iDireito);
		/*
		 * Aqui há a troca do pivô
		 */
		 v[0] = v[iDireito];
		 v[iDireito] = pivo;
		/*
		 * Ordenação recursiva dos subarranjos
		 */
		 ordenaRapida(iDireito, v);
		 ordenaRapida(n-iEsquerdo, &v[iEsquerdo]);
	}
}

// Dividir para conquistar
void ordenaIntercala(int inicio, int fim, int *v){
	/*
	 * Cria a variável meio que retorna a metade entre
	 * o inicio e o final do vetor. Enquanto o inicio
	 * for menor que o fim, chama recursivamente duas vezes
	 * uma do inicio até o meio e outra do meio até o fim.
	 * Dividi-se tudo sucessivamente.
	 */
	int meio;
	if (inicio<fim-1) {
		meio=(inicio+fim)/2;
		ordenaIntercala(inicio, meio, v);
		ordenaIntercala(meio, fim, v);
		/*
		 * A função intercala serve justamente para juntar
		 * esses subarrajos, criados recursivamente, de uma
		 * forma ordenada.
		 */
		intercala(inicio, meio, fim, v);
	}
}

void intercala(int inicio, int meio, int fim, int *v){
	int i, j, k, w[N];
	// indice i vai inicia o vetor no inicio
	i = inicio;
	// indice j vai iniciar o vetor no meio
	j = meio;
	// indice k é o indice do vetor que será ordenado w[]
	k = 0;
	/*
	 * Enquanto o i for até o meio e o j for até o fim.
	 */
	while(i<meio && j<fim){
		/*
		 * verifique se o valor de i é menor que o valor de j.
		 */
		if(v[i]<v[j]){
			/*
			 * Se for, o novo vetor recebe o valor de i. Incrementa.
			 */
			w[k]=v[i];
			i++;
		}
		else{
			/*
			 * Se não, acontece o mesmo,só que com o índice j.
			 */
			w[k]=v[j];
			j++;
		}
		/*
		 * No final o indíce k é incrementado para o próximo. 
		 */
		k++;
	}
	/*
	 * Se ainda houver valor no i que seja menor que o meio
	 * preenche o novo vetor com os valores restantes, ainda
	 * não ordenados. O mesmo ocorre com o j.
	 */
	while(i<meio){
		w[k] = v[i];
		i++;
		k++;
	}
	while(j<fim){
		w[k] = v[j];
		j++;
		k++;
	}
	/*
	 * Por fim copio os valores do vetor temporário
	 * para o vetor original passado na função
	 */
	for(i=inicio; i<fim; i++){
		v[i] = w[i-inicio];
	}
}