#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Usuarios_mercasanca/cadastroelogin.c"

int main(){
    int resposta;
    char temp;

printf("------Bem vindo!------\n");
printf("pressione: \n");
printf("0 - encerrar\n");
printf("1 - cadastro\n");
printf("2 - login\n");
printf("deseja fazer cadastro ou login? ");
scanf("%d", &resposta);
scanf("%c", &temp);

if(resposta == 1)
    cadastro();
else if(resposta == 2)
    login();

    while(resposta != 0){
        printf("deseja fazer cadastro ou login? ");
        scanf("%d", &resposta);
        scanf("%c", &temp);

        if(resposta == 1)
            cadastro();
        else if(resposta == 2)
            login();
    }



    return 0;
}