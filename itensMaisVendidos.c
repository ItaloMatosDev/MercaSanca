#include <stdio.h>
#include <stdlib.h>
#include "Itens/CadastroELeituracsv copy.c"

void itemMaisVendido(){
  FILE *itens;

  int iditem[numero_maximo_de_produtos], qteitem[numero_maximo_de_produtos];

  itens = fopen("quantidadadePorItem.csv", "r"); //arquivo com o id do prod e a quantidade geral
  if(itens == NULL){
      printf("erro ao executar o arquivo");
      exit(0);
  }

  int i = 0;
  while(!feof(itens)) {
    fscanf(itens, "%d;%d\n", &iditem[i], &qteitem[i]);
    i++;
  }

  int maior = qteitem[0];

  for(int j = 0; j < i; j++){
    if (qteitem[j] > maior) maior = qteitem[j];
  }

  fclose(itens);
}

int main(){
  printf("teste");
}