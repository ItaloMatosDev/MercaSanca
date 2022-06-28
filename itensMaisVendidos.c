#include <stdio.h>
#include <stdlib.h>
#include "Itens/CadastroELeituracsv copy.c"

void itemMaisVendido(){
  int id_produto_lido[numero_maximo_de_produtos];
  char nome_produto_lido[numero_maximo_de_produtos][40];
  float preco_unitario_lido[numero_maximo_de_produtos];
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

  int iditem[numero_maximo_de_produtos], qteitem[numero_maximo_de_produtos];

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


int main(){
  printf("teste\n\n");
  itemMaisVendido();
}