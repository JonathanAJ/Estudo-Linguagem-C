#include <stdio.h>

/* Protótipo */ 
int fat(int num);
 
int main(void){
    int n;
    printf("Vamos calcular o n! de ? ");
    scanf("%d", &n);
 
    printf("Soma: %d\n", fat(n));

    return 0;
}

int fat(int n){
    if(n == 1)
        return 1;
    else
        return ( n * fat(n-1) );
}