#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <time.h>
#include <math.h>

float num1, num2, num3, num4, media, variancia, variancia2, total, mediana, t;


void * funcao1(void * arg){
    printf("*------*INICIO FUNCAO 1*----****\n");
    media = total / 4;
    printf("\nMedia dos alunos = %.1f\n",media);

    // fazendo a variança  pos na formula precisa
    variancia = pow((num1-media),2) + pow((num2-media),2) + pow((num3-media),2) + pow((num4-media),2);
    variancia = variancia / 4;

    printf("\nVariancia e  = %f\n", variancia);
   
    printf("\nValor do desvio padrao = %f\n", sqrt(variancia));
}


void * funcao2(void * arg){

    printf("*------*INICIO FUNCAO 2*----****\n");
    media = total / 4;
    printf("\nMedia 2 = %.1f\n",media);

    
    variancia2 = pow((num1-media),2) + pow((num2-media),2) + pow((num3-media),2) + pow((num4-media),2);
    variancia2 = variancia2 / 4;

    printf("\nVariancia = %f\n", variancia2);
    

}

void * funcao3(void * arg){

    printf("*------*INICIO FUNCAO 3*----****\n");
    do{
        if(num1 > num4 ){
            t = num1;
            num1 = num4;
            num4 = t;
        }
        if(num1 > num2){
            t = num1;
            num1 = num2;
            num2 = t;
        }
        if(num2 > num3){
            t = num2;
            num2 = num3;
            num3 = t;
        }
        if(num3 > num4){
            t = num3;
            num3 = num4;
            num4 = t;
        }

    }while (num1 > num4 || num1 > num2 || num2 > num3 || num3 > num4);

    printf("\nOs numeros em ordem crescente  %.1f, %.1f, %.1f, %.1f\n",num1, num2, num3, num4);

    mediana = (num2 + num3) / 2;
    printf("A mediana é igual a: %.1f", mediana );


}


int main (void)
{

    printf("Digite o priemiro numero:\n");
    scanf("%f",&num1);

    printf("Digite o segundo numero:\n");
    scanf("%f",&num2);

    printf("Digite o terceiro numero:\n");
    scanf("%f",&num3);

    printf("Digite o quarto numero:\n");
    scanf("%f",&num4);


    total = num1 + num2 + num3 + num4;
    printf("\nSoma total e igual = %.1f\n",total);
    printf("");

    pthread_t tid, tid2, tid3;
    
    pthread_create(&tid, NULL, &funcao1, NULL);
    pthread_join(tid, NULL);

    pthread_create(&tid2, NULL, &funcao2, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, NULL, &funcao3, NULL);
    pthread_join(tid3, NULL);
    

    return 0;


}