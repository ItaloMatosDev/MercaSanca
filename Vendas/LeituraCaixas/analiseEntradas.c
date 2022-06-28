#include <stdio.h>
#include <stdlib.h>
#include "./distribuicaoNosCaixas.c"

void main() {

  int caixas = 4, tamanhoEntrada = 500;
  int temposRegistrados[tamanhoEntrada];

  FILE *arqEntradas;
  arqEntradas = fopen("6EntradasTeste.txt", "r");

  int id, qntde, preco, tempo, pagamento;
  //for (int i = 0; i < tamanhoEntrada; i++){
    int i = 0;
    while(!feof(arqEntradas)){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    temposRegistrados[i] = tempo;
    i++;
  }

  distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
  totalVendasPorCaixa(tamanhoEntrada, caixas);
  tempoMedioPorCaixa(tamanhoEntrada, caixas);
  vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
  metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);

  fclose(arqEntradas);
}