#include <stdio.h>
#include <string.h>
/*
 * Construção de alunos de uma disciplina
 */
struct aluno{
	char nome[81];
	char matricula[8];
	char turma;
	float prova1;
	float prova2;
	float prova3;
};
typedef struct aluno Aluno;

// Protótipo
void imprimeAlunos(int n, Aluno **turmas);

/*
 * Função principal
 */
int main(void){
	// Primeiro Aluno
	Aluno aluno_a;
	/*
	 * Aqui fica inválido referenciar uma string diretamente
	 * ao vetor de char, por conta disso faz-se o uso de strcpy
	 * que copia a string para a determinada alocação
	 */
	strcpy(aluno_a.nome,"Jonathan");
	strcpy(aluno_a.matricula,"1928657");
	aluno_a.turma = 'A';
	aluno_a.prova1 = 10;
	aluno_a.prova2 = 7;
	aluno_a.prova3 = 9;
	// Segundo Aluno
	Aluno aluno_b;
	strcpy(aluno_b.nome, "Hemelly");
	strcpy(aluno_b.matricula,"8962472");
	aluno_b.turma = 'A';
	aluno_b.prova1 = 10;
	aluno_b.prova2 = 10;
	aluno_b.prova3 = 10;
	// Terceiro Aluno
	Aluno aluno_c;
	strcpy(aluno_c.nome, "Lucas");
	strcpy(aluno_c.matricula,"8962472");
	aluno_c.turma = 'B';
	aluno_c.prova1 = 3;
	aluno_c.prova2 = 4;
	aluno_c.prova3 = 6;
	// Vetor que guarda a turma, ou seja, guarda um ponteiro de cada aluno
	Aluno *turmas[3];
	turmas[0] = &aluno_a;
	turmas[1] = &aluno_b;
	turmas[2] = &aluno_c;
	// chamada da função
	imprimeAlunos(3, turmas);

	return 0;
}

void imprimeAlunos(int n, Aluno **turmas){
	int i;
	float res_m;
	for(i=0; i<n; i++){
		/*
		 * Cálculo simples de média:
		 * o uso do (->) invés de (.) é necessário
		 * pois estamos trabalhando com ponteiros
		 */
		res_m = ((turmas[i]->prova1) + (turmas[i]->prova2) + (turmas[i]->prova3))/3;
		/*
		 * Imprimindo os valores do vetor
		 */
		printf("\nNome: %s\nMatr.: %s\nTurma: %c\nMédia: %0.2f\n",
				turmas[i]->nome,
				turmas[i]->matricula,
				turmas[i]->turma,
				res_m);
		/*
		 * Por fim o resultado de aprovação
		 */
		if(res_m>7){
			printf("Resultado: Aprovado\n");
		}else{
			printf("Resultado: Reprovado\n");	
		}
	}
}