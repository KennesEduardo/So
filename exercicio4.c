#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include    <stdio.h>
#include <locale.h>

int num, i , resultado = 0;


void * funcao1(void * arg){

    do
    {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                resultado++;
                break;
            }
        }
    
        if (resultado == 0)
            printf("%d e um numero primo\n", num);
            num = num - 1;
            for (i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                resultado++;
                printf("%d e um numero primo\n", num);
            }
        }



        // else
        //     printf("%d nao e um numero primo\n", num);
           
    } while (num == 1);
    
}





int main (void)
{
    printf("Digite o priemiro numero:\n");
    scanf("%d",&num);

    pthread_t tid;
    pthread_create(&tid, NULL, &funcao1, NULL);
    pthread_join(tid, NULL);
    return 0;
}