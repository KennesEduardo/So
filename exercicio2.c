#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <time.h>

float num1,num2,num3, media, total;
//lembrete ilustrei as questão como se fosse uma media de notas de aluno pra ficilitar minha didadica

void * funcao1(void * arg){
    printf("\n*------*INICIO FUNCAO 1*----****\n");
    media = total / 3;
    printf(" Media aritmetica = %.1f \n",media);

}

void * funcao2(void * arg){
    printf("\n*------*INICIO FUNCAO 2*----****\n");
    printf("");
    if(num1 > num2 && num1 > num3)
        printf("\nAluno 1 possui maior nota: %.1f \n",num1);

    else if (num2 > num1 && num2 > num3)
        printf("\nAluno 2 possui maior nota: %.1f \n",num2);

    else if (num1 < num3 && num2 < num3)
        printf("\nAluno 3 possui maior nota: %.1f \n",num3);
            
    else
        printf("\nTodas as notas sao iguais: nota 1 = %.1f nota 2 = %.1f nota 3 =  %.1f \n",num1 , num2, num3);   

}

void * funcao3(void * arg){
    printf("\n*------*INICIO FUNCAO 3*----**** \n");
    printf("");
    if(num1 < num2 && num1 < num3)
        printf("\nAluno 1 possui menor nota: %.1f\n",num1);

    else if (num2 < num1 && num2 < num3)
        printf("\nAluno 2 possui menor nota: %.1f\n",num2);

    else if (num1 > num3 && num2 > num3)
        printf("\nAluno 3 possui menor nota: %.1f\n",num3);
            
    else
        printf("\nTodas as notas sao iguais: nota 1 = %.1f nota 2 = %.1f nota 3 =  %.1f \n",num1 , num2, num3);   

}

int main (void)
{

    printf("Digite a primeira nota do aluno 1: \n");
    scanf("%f",&num1);

    printf("Digite a primeira nota do aluno 2: \n");
    scanf("%f",&num2);

    printf("Digite a primeira nota do aluno 3: \n");
    scanf("%f",&num3);


    total = num1 + num2 + num3;
    printf("\nSoma total e igual = %.1f \n",total);

    // for (i = 1; i<=5; i++){
    //     printf("Digite a primeira nota do aluno %d\n",i);
    //     scanf("%f",&num);
    //     total = (num)+ (num);
    //     printf("%f", total);
    // }
    // media = (total) / 5;
    // printf("\nMedia dos alunos = %.1f\n",media);
    // // media = num / 2;
    // // printf("sua media é: ", media);

     pthread_t tid, tid2, tid3;
    
    pthread_create(&tid, NULL, &funcao1, NULL);
    pthread_join(tid, NULL);

    pthread_create(&tid2, NULL, &funcao2, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, NULL, &funcao3, NULL);
    pthread_join(tid3, NULL);
    
    return 0;


    


}