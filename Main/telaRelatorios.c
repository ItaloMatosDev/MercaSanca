#include <stdio.h>
#include <stdlib.h>
#include "../Vendas/LeituraCaixas/distribuicaoNosCaixas.c"
#include "./itensMaisVendidos.c"

void opcoes(){
  printf("\n\n-------------------------------------------------\n\n");
  printf("Escolha uma das opcoes abaixo para visualizar o relatorio:\n\n");
  printf("1 - Todos os relatorios\n");
  printf("2 - Total de faturamento por caixa\n");
  printf("3 - Tempo total gasto por caixa\n");
  printf("4 - Total de vendas por metodo de pagamento\n");
  printf("5 - Metodo de pagamento mais utilizado\n");
  printf("6 - Item(s) mais vendido(s)\n");
  printf("7 - Item(s) menos vendido(s)\n");
  printf("0 - Voltar para a tela anterior\n");
}

void relatorios(){
  FILE *arqEntradas;
  arqEntradas = fopen("../entrada/registrodevendas.txt", "r");
  int tamanhoEntrada;
  int a, b, c, d, e, i;
  while(!feof(arqEntradas)){
    fscanf(arqEntradas,"%d %d %d %d %d", &i, &b, &c, &d, &e);
  }
  tamanhoEntrada = i+1;
  int temposRegistrados[tamanhoEntrada];

  int caixas = 4, opcao; //importar o numero maximo de produt e trocar o 100 por ele

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanhoEntrada; i++){ //trocar por while feof
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    temposRegistrados[i] = tempo;
  }
  opcoes();
  scanf("%d", &opcao);

  while (opcao != 0){
    switch (opcao)
    {
      case 1:
        distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
        totalVendasPorCaixa(tamanhoEntrada, caixas);
        tempoMedioPorCaixa(tamanhoEntrada, caixas);
        vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
        metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);
        itensMaisVendidos();
        itensMenosVendidos();
        break;
      case 2:
        totalVendasPorCaixa(tamanhoEntrada, caixas);
        break;
      case 3:
        tempoMedioPorCaixa(tamanhoEntrada, caixas);
        break;
      case 4:
        vendasPorMetodoDePagamento(tamanhoEntrada, caixas);
        break;
      case 5:
        metodoPagamentoMaisUtilizado(tamanhoEntrada, caixas);
        break;
      case 6:
        itensMaisVendidos();
        break;
      case 7:
        itensMenosVendidos();
        break;
      default:
        break;
    }
    opcoes();
    scanf("%d", &opcao);
  }

  fclose(arqEntradas);
}