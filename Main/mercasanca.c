#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Usuarios_mercasanca/cadastroelogin.c"
#include "./telaRelatorios.c"

int main(){
    int resposta;

    //teladelogin();

    printf("\n------------- TELA PRINCIPAL MERCASANCA 2022 ------------------\n");
    printf("Pressione:\n");
    printf("1 - trocar de perfil\n");
    printf("2 - cadastrar novos produtos\n");
    printf("3 - registrar venda\n");
    printf("4 - gerar relatorios\n");
    printf("0 - sair\n");
    printf("Insira aqui: ");
    scanf("%d", &resposta);
    printf("-----------------------------------------------------------\n");

    while(resposta!= 0){
        switch(resposta){
            case 1:
                teladelogin();
                break;
            case 4:
                relatorios(1);
                break;
        }

    printf("\n------------- TELA PRINCIPAL MERCASANCA 2022 ------------------\n");
    printf("Pressione:\n");
    printf("1 - trocar de perfil\n");
    printf("2 - cadastrar novos produtos\n");
    printf("3 - registrar venda\n");
    printf("4 - gerar relatorios\n");
    printf("0 - sair\n");
    printf("Insira aqui: ");
    scanf("%d", &resposta);
    printf("-----------------------------------------------------------\n");
    }


    //tela principal

    //trocar de perfil
    //cadastrar produto
    //registrar venda
    //gerar relatorios
    //sair


    return 0;
}