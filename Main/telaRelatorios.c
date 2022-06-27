#include <stdio.h>
#include <stdlib.h>
#include "../Vendas/LeituraCaixas/distribuicaoNosCaixas.c"

void relatorios(int opcao){
  int caixas = 4, tamanhoEntrada = 100;
  int temposRegistrados[tamanhoEntrada];

  FILE *arqEntradas;
  arqEntradas = fopen("6EntradasTeste.txt", "r");

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanhoEntrada; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    temposRegistrados[i] = tempo;
  }

  if (opcao == 1){
    distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
    totalVendasPorCaixa(tamanhoEntrada, caixas);
    tempoMedioPorCaixa(tamanhoEntrada, caixas);
    vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
    metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);
  }

  fclose(arqEntradas);
}

//int main(){

  /*int opcao;
  printf("Escolha uma opcao para gerar o relatorio de uma das opcoes abaixo\n");
  printf("1 - Todos\n");
  scanf("%d", &opcao);
  relatorios(1);*/
//}