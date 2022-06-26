#include <stdio.h>
#include <stdlib.h>
#include "./distribuicaoNosCaixas.c"

void main() {
  int caixas = 4, tamanhoEntrada = 6;
  int temposRegistrados[] = {10, 10, 10, 4, 4, 4};
  distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
  totalVendasPorCaixa(tamanhoEntrada, caixas);
  tempoMedioPorCaixa(tamanhoEntrada, caixas);
  vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
  metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);
}