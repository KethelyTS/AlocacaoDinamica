/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *bairro = NULL; //caderno de endereços
    int capacidade =  2; //capacidade inicial da construção
    int casas = 0; //nunhuma casa construida ainda
    int nova_casa; //variavel temporaria 
    
    bairro = malloc (capacidade * sizeof (int));
    if (bairro == NULL) {
        printf("Erro ao construir o bairro! \n");
        return 1;
    }
    printf("Digite os números ou ctrl+d/crtl+z para sair.\n\n");
    printf("Insira o valor da carta das casas: \n");
    while(scanf("%d", &nova_casa) == 1) {
        if(casas == capacidade) {
            //pedir para pref aumentar o bairro
            printf("Prefeitura, preciso expandir o bairro!\n");
            capacidade = capacidade * 2; //dobra tatamanho do bairro 
            int *novo_bairro = realloc(bairro, capacidade * sizeof(int));
            if(novo_bairro == NULL) {
                printf("Erro: Prefeitura não aprovou a expansão!\n");
                free(bairro);
                return 1;
            } else {
                printf("Bairro expandido, pode construir!\n");
            }
            bairro = novo_bairro; //atualiza o caderno de endereços com o numero novo
        }
        //constroi a nova casa e armazena o numero
        bairro[casas] = nova_casa;
        casas++;
    }
        printf("\nCasas no bairro (%d no total):\n", casas);
        for(int i = 0; i < casas; i++){
            printf("Casa %d : %d", i, bairro[i]);
        }
        //demolir o bairro 
        free(bairro);
        bairro = NULL;
    return 0;
}