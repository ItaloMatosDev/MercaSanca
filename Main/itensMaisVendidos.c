#include <stdio.h>
#include <stdlib.h>

void itensMaisVendidos(){
  int id_produto_lido[500];
  char nome_produto_lido[500][40];
  float preco_unitario_lido[500];
  FILE *cadastro ;

    cadastro = fopen("cadastrodeitens.csv", "r");

    if(cadastro == NULL){
        printf("erro");
        exit(0);
    }

    int i = 0;
    while(!feof(cadastro)){  
        fscanf(cadastro, "%d;", &id_produto_lido[i]);
        fscanf(cadastro, "%40[^;];", nome_produto_lido[i]);
        fscanf(cadastro, "%f\n", &preco_unitario_lido[i]);
        i++;
    }

    fclose(cadastro);

  FILE *itens;

  int iditem[500], qteitem[500];

  itens = fopen("quantidadadePorItem.csv", "r"); //arquivo com o id do prod e a quantidade geral
  if(itens == NULL){
      printf("erro ao executar o arquivo");
      exit(0);
  }

  i = 0;
  while(!feof(itens)) {
    fscanf(itens, "%d;%d\n", &iditem[i], &qteitem[i]);
    i++;
  }

  int maior = qteitem[0];
  int indicemaioritem;

  printf("Produto(s) mais vendido(s): \n");
  for(int j = 0; j < i; j++){
    if (qteitem[j] > maior) maior = qteitem[j];
    indicemaioritem = j;
  }

  for(int j = 0; j < i; j++){
    if (qteitem[j] == maior)
      printf("%s: %d itens\n", nome_produto_lido[j], qteitem[j]);
  }
  printf("\n");
  
  fclose(itens);
}

void itensMenosVendidos() {
  int id_produto_lido[500];
  char nome_produto_lido[500][40];
  float preco_unitario_lido[500];
  FILE *cadastro ;

    cadastro = fopen("cadastrodeitens.csv", "r");

    if(cadastro == NULL){
        printf("erro");
        exit(0);
    }

    int i = 0;
    while(!feof(cadastro)){  
        fscanf(cadastro, "%d;", &id_produto_lido[i]);
        fscanf(cadastro, "%40[^;];", nome_produto_lido[i]);
        fscanf(cadastro, "%f\n", &preco_unitario_lido[i]);
        i++;
    }

    fclose(cadastro);

  FILE *itens;

  int iditem[500], qteitem[500];

  itens = fopen("quantidadadePorItem.csv", "r"); //arquivo com o id do prod e a quantidade geral
  if(itens == NULL){
      printf("erro ao executar o arquivo quantidadadePorItem.csv");
      exit(0);
  }

  i = 0;
  while(!feof(itens)) {
    fscanf(itens, "%d;%d\n", &iditem[i], &qteitem[i]);
    i++;
  }

  int menor = qteitem[0];
  int indicemenoritem;

  printf("Produto(s) menos vendido(s): \n");
  for(int j = 0; j < i; j++){
    if (qteitem[j] < menor && qteitem[j] > 0) menor = qteitem[j];
    indicemenoritem = j;
  }

  for(int j = 0; j < i; j++){
    if (qteitem[j] == menor)
      printf("%s: %d itens\n", nome_produto_lido[j], qteitem[j]);
  }
  printf("\n");
  
  fclose(itens);
}

void itensNaoVendidos() {
  int id_produto_lido[500];
  char nome_produto_lido[500][40];
  float preco_unitario_lido[500];
  FILE *cadastro ;

    cadastro = fopen("cadastrodeitens.csv", "r");

    if(cadastro == NULL){
        printf("erro");
        exit(0);
    }

    int i = 0;
    while(!feof(cadastro)){  
        fscanf(cadastro, "%d;", &id_produto_lido[i]);
        fscanf(cadastro, "%40[^;];", nome_produto_lido[i]);
        fscanf(cadastro, "%f\n", &preco_unitario_lido[i]);
        i++;
    }

    fclose(cadastro);

  FILE *itens;

  int iditem[500], qteitem[500];

  itens = fopen("quantidadadePorItem.csv", "r"); //arquivo com o id do prod e a quantidade geral
  if(itens == NULL){
      printf("erro ao executar o arquivo");
      exit(0);
  }

  i = 0;
  while(!feof(itens)) {
    fscanf(itens, "%d;%d\n", &iditem[i], &qteitem[i]);
    i++;
  }

  int zerado = qteitem[0];
  int indicezerado;

  printf("Os seguintes produtos nao foram vendidos: \n");
  for(int j = 0; j < i; j++){
    if (qteitem[j] == 0)
      printf("%s: %d itens\n", nome_produto_lido[j], qteitem[j]);
  }
  printf("\n");
  
  fclose(itens); 
}

// int main(){
//   // printf("teste\n\n");
//   // itemMaisVendido();
//   // itemMenosVendido();
//   // itensNaoVendidos();
// }