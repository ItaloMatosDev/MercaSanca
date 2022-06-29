#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarEntradas(int qtdEntradas){
  FILE *arquivoEntradas;
  arquivoEntradas = fopen("arquivoEntradasValidacao.txt", "w");
  if (arquivoEntradas == NULL){
    printf("Nao ha arquivo de entradas para analisar");
  }

  int entradas[qtdEntradas][5];
  srand(time(NULL));
  int id, itens, preco, tempo, pagamento;
  for(int i = 0; i < qtdEntradas; i++){
    itens = rand() % 100 + 1;
    preco = rand() % (10*qtdEntradas);
    tempo = rand() % (itens * 2) + 2;
    pagamento = rand() % 4;
    entradas[i][0] = i;
    entradas[i][1] = itens;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }

  for (int i = 0; i < qtdEntradas; i++){
    for (int j = 0; j < 5; j++){
      printf("%d ", entradas[i][j]);
      fprintf(arquivoEntradas, "%d ", entradas[i][j]);
    }
    printf("\n");
    fprintf(arquivoEntradas, "\n");
  }

  fclose(arquivoEntradas);

}

int main () {
  gerarEntradas(10000);
}