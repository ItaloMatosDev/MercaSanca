#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limitedeusuarios 50

void cadastro(){
    char nomedousuario[100], emaildousuario[100], senhadousuario[15], novasenha[15];
    FILE *cadastramento;

    cadastramento = fopen("cadastrodeusuarios.txt", "a+");

    if(cadastramento == NULL){
        printf("erro ao executar o arquivo");
        exit(0);
    }


    printf("------ CADASTRO ------\n\n");
    printf("Insira o nome: ");
    scanf("%100[^\n]", nomedousuario);
    printf("Insira o email: ");
    scanf("%s", emaildousuario);
    printf("Insira uma nova senha: ");
    scanf("%s", senhadousuario);
    printf("Confirme sua senha: ");
    scanf("%s", novasenha);

    if(strcmp(senhadousuario, novasenha) != 0)
        printf("Confirme corretamente a sua senha.\n");
    else{
        fprintf(cadastramento, "%s\n%s\n%s\n", nomedousuario, emaildousuario, senhadousuario);
    }

    fclose(cadastramento);
}

int login(){
    char nome[limitedeusuarios][100], email[limitedeusuarios][100], senha[limitedeusuarios][15];

    char emaillogin[100], senhalogin[15];

    FILE *arqlogin;

    arqlogin = fopen("cadastrodeusuarios.txt", "r");

    if(arqlogin == NULL){
        printf("erro ao executar o arquivo");
        exit(0);
    }

    int i=0;
    while(!feof(arqlogin)){
        fscanf(arqlogin, "%100[^\n]\n", nome[i]);
        fscanf(arqlogin, "%s\n", email[i]);
        fscanf(arqlogin, "%s\n", senha[i]);
        i++;
    }

    printf("------ LOGIN ------\n\n");
    printf("Insira seu email: ");
    scanf("%s", emaillogin);
    printf("Insira sua senha: ");
    scanf("%s", senhalogin);

int x = 0;
    for(int j=0; j<=i; j++){
        if(strcmp(email[j], emaillogin) == 0){
            //printf("%s / %s\n", email[j], emaillogin);
            if(strcmp(senha[j], senhalogin) == 0){
                printf("login concluido com sucesso, bem vindo, %s!\n", nome[j]);
                x = 1;
            }
        }
    }

    if(x==0){
        printf("houve algum erro, confira se seu email e senha estao corretos\n");
    }
    fclose(arqlogin);

    return x;
    
}

void teladelogin(){
    int resposta, loginn;
    char temp;

printf("------ TROCAR DE PERFIL ------\n\n");
printf("pressione: \n");
printf("0 - voltar\n");
printf("1 - cadastro\n");
printf("2 - login\n");
printf("Insira aqui: ");
scanf("%d", &resposta);
scanf("%c", &temp);

if(resposta == 1)
    cadastro();
else if(resposta == 2)
    loginn = login();

    while(resposta != 0 && loginn != 1){
        printf("------ TROCAR DE PERFIL ------\n\n");
        printf("pressione: \n");
        printf("0 - voltar\n");
        printf("1 - cadastro\n");
        printf("2 - login\n");
        printf("Insira aqui: ");
        scanf("%d", &resposta);
        scanf("%c", &temp);

        if(resposta == 1)
            cadastro();
        else if(resposta == 2){
            loginn = login();
        }
    }

}


 /*int main(){

     return 0;
 }*/