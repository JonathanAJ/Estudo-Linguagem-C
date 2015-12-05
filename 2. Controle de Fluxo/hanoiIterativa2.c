// C Program for Iterative Tower of Hanoi
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Uma estrutura para representar uma pilha
typedef struct pilha{
   int capacidade;
   int topo;
   int *array;
}Pilha;

// function to create a Pilha of given capacidade.
Pilha* criarPilha(int capacidade){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha -> capacidade = capacidade;
    pilha -> topo = -1;
    pilha -> array = (int*) malloc(pilha -> capacidade * sizeof(int));
    return pilha;
}

// Pilha is full when topo is equal to the last index
int pilhaCheia(Pilha* Pilha){
   return (Pilha->topo == Pilha->capacidade - 1);
}

// Pilha is empty when topo is equal to -1
int pilhaVazia(Pilha* Pilha){
   return (Pilha->topo == -1);
}

// Function to add an item to Pilha.  It increases
// topo by 1
void push(Pilha *Pilha, int item){
    if (pilhaCheia(Pilha))
        return;
    Pilha -> array[++Pilha -> topo] = item;
}

// Function to remove an item from Pilha.  It
// decreases topo by 1
int pop(Pilha* Pilha){
    if (pilhaVazia(Pilha))
        return INT_MIN;
    return Pilha -> array[Pilha -> topo--];
}

//Function to show the movement of discos
void moveDisco(char de, char para, int disco){
    printf("Move o disco %d de %c para %c\n",
           disco, de, para);
}

// Function to implement legal movement between
// two poles
void moveDiscoEntreDoisPontos(Pilha *origem, Pilha *destino, char s, char d){
    int poloUmTopo = pop(origem);
    int poloDoisTopo = pop(destino);

    // When pole 1 is empty
    if (poloUmTopo == INT_MIN)
    {
        push(origem, poloDoisTopo);
        moveDisco(d, s, poloDoisTopo);
    }

    // When pole2 pole is empty
    else if (poloDoisTopo == INT_MIN)
    {
        push(destino, poloUmTopo);
        moveDisco(s, d, poloUmTopo);
    }

    // When topo disco of pole1 > topo disco of pole2
    else if (poloUmTopo > poloDoisTopo)
    {
        push(origem, poloUmTopo);
        push(origem, poloDoisTopo);
        moveDisco(d, s, poloDoisTopo);
    }

    // When topo disco of pole1 < topo disco of pole2
    else
    {
        push(destino, poloDoisTopo);
        push(destino, poloUmTopo);
        moveDisco(s, d, poloUmTopo);
    }
}

//Function to implement TOH puzzle
void iteracaoHanoi(int nDiscos, Pilha *origem, Pilha *auxiliar, Pilha *destino){
    int i, totalMovimentos;
    char s = 'A', d = 'B', a = 'C';

    //If number of discos is even, then interchange
    //destinoination pole and auxiliariliary pole
    if (nDiscos % 2 == 0)
    {
        char temp = d;
        d = a;
        a  = temp;
    }
    totalMovimentos = pow(2, nDiscos) - 1;

    //Larger discos will be pushed first
    for (i = nDiscos; i >= 1; i--)
        push(origem, i);

    for (i = 1; i <= totalMovimentos; i++)
    {
        if (i % 3 == 1)
          moveDiscoEntreDoisPontos(origem, destino, s, d);

        else if (i % 3 == 2)
          moveDiscoEntreDoisPontos(origem, auxiliar, s, a);

        else if (i % 3 == 0)
          moveDiscoEntreDoisPontos(auxiliar, destino, a, d);
    }
}

// Driver Program
int main(void){
    // Input: number of discos
    int nDiscos;
    
    printf("Quantos discos há na torre A?\n");
    scanf("%d", &nDiscos);

    Pilha *origem, *destino, *auxiliar;

    // Create three Pilhas of size 'nDiscos'
    // to hold the discos
    origem = criarPilha(nDiscos);
    auxiliar = criarPilha(nDiscos);
    destino = criarPilha(nDiscos);

    iteracaoHanoi(nDiscos, origem, auxiliar, destino);

    return 0;
}