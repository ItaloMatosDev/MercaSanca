#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Usuarios_mercasanca/cadastroelogin.c"
#include "./telaRelatorios.c"

int main(){
    int resposta;

    loginInicial();

    printf("\n\n---------- TELA INICIAL MERCASANCA 2022 ------------\n");
    printf("Pressione: \n");
    printf("1 - trocar de perfil\n");
    printf("2 - cadastrar produtos\n");
    printf("3 - registrar vendas\n");
    printf("4 - gerar relatorios\n");
    printf("0 - sair\n");
    printf("Insira aqui: ");
    scanf("%d", &resposta);
    printf("----------------------------------------------------\n");

    while(resposta != 0){
        switch(resposta){
            case 1: 
                teladelogin();
                break;
            case 4: 
                relatorios();
                break;
        }
    printf("\n\n---------- TELA INICIAL MERCASANCA 2022 ------------\n");
    printf("Pressione: \n");
    printf("1 - trocar de perfil\n");
    printf("2 - cadastrar produtos\n");
    printf("3 - registrar vendas\n");
    printf("4 - gerar relatorios\n");
    printf("0 - sair\n");
    printf("Insira aqui: \n");
    scanf("%d", &resposta);
    printf("----------------------------------------------------\n");

    }


    return 0;
}