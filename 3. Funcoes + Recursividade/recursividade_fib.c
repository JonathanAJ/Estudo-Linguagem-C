#include <stdio.h>
#include <stdlib.h>

int main(int op){
   int n,i,o;
   printf("\nDigite a quantidade de termos da sequência:\n");
   scanf("%d", &n);
   printf("\nA sequência de Fibonacci é: \n");
   for(i=0; i<n; i++)
       printf("%d ", fibonacci(i+1));
   printf("\n\nOpções:\n1 - Continuar\n0 - Sair:\n");
   scanf("%d", &o);
   if(o==1)
     main(o);
   else
    exit(0);
}

int fibonacci(int num){
   if(num==1 || num==2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2);
}