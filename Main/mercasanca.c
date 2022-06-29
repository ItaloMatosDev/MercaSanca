#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Main/Usuarios_mercasanca\cadastroelogin.c"
#include "./telaRelatorios.c"
#include "..\entrada\Entradamanual.c"


int main(){
    int resposta;

    printf("--------------------Bem vindo!----------------------\n");
    while(login() == 0)
        printf("");
        

    printf("\n\n---------- TELA INICIAL MERCASANCA 2022 ------------\n");
    printf("Pressione: \n");
    printf("1 - trocar de perfil\n");
    printf("2 - cadastrar produtos\n");
    printf("3 - registrar vendas\n");
    printf("4 - gerar relatorios\n");
    printf("0 - sair\n");
    printf("Insira aqui: ");
    scanf("%d", &resposta);
    printf("-----------------------------------------------------\n");

    while(resposta != 0){
        switch(resposta){
            case 1: 
                teladelogin();
                break;
            case 2:
                cadastro_de_produtos();
                break;
            case 3: 
                gerarEntradas(numero_maximo_de_produtos);
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
    printf("Insira aqui: ");
    scanf("%d", &resposta);
    printf("----------------------------------------------------\n");

    }


    return 0;
}