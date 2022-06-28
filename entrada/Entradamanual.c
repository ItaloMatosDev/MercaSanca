#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\Itens\CadastroELeituracsv copy.c"

void gerarEntradas(int qtdEntradas){
  FILE *arquivoEntradas;
  arquivoEntradas = fopen("registrodevendas.txt", "a+");
  if (arquivoEntradas == NULL){
    printf("Nao ha arquivo de entradas para analisar");
  }

  int i, a,b,c,d;
  srand(time(NULL));

  while(!feof(arquivoEntradas)){
    fscanf(arquivoEntradas, "%d %d %d %d %d \n", &i, &a, &b, &c, &d);
  }

  int entradas[5];
  
  int id, itens, preco, pagamento;
  registro_de_vendas(&itens, &preco, &pagamento);


    entradas[0] = i+1;
    entradas[1] = itens;
    entradas[2] = preco;
    entradas[3] = rand()% (itens*2) + 2;
    entradas[4] = pagamento;
  
  for(int i=0; i<5; i++){
    fprintf(arquivoEntradas, "%d ", entradas[i]);
  }
    fprintf(arquivoEntradas, "\n");

  fclose(arquivoEntradas);

}

int main () {
  gerarEntradas(100);
}