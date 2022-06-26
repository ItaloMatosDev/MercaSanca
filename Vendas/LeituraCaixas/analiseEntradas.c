#include <stdio.h>
#include <stdlib.h>
#include "./distribuicaoNosCaixas.c"

void main() {
  int caixas = 4, tamanhoEntrada = 6;
  int temposRegistrados[] = {10, 10, 10, 4, 4, 4};
  distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
  totalVendasPorCaixa(6, 4);
  tempoMedioPorCaixa(6, 4);
  vendasPorMetodoDePagamento(6, 4);
  metodoPagamentoMaisUtilizado(6, 4);
}