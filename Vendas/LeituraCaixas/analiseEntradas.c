#include <stdio.h>
#include <stdlib.h>
#include "./distribuicaoNosCaixas.c"

void main() {

  int caixas = 4, tamanhoEntrada = 30;
  int temposRegistrados[tamanhoEntrada];

  FILE *arqEntradas;
  arqEntradas = fopen("6EntradasTeste.txt", "r");

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanhoEntrada; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    printf("tempo: %d\n", tempo);
    temposRegistrados[i] = tempo;
  }

  for(int i = 0; i < tamanhoEntrada; i++){
    printf("%d ", temposRegistrados[i]);
  }

  distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
  totalVendasPorCaixa(tamanhoEntrada, caixas);
  tempoMedioPorCaixa(tamanhoEntrada, caixas);
  vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
  metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);

  fclose(arqEntradas);
}