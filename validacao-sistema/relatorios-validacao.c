#include <stdio.h>
#include <stdlib.h>
#include "./distribuicao-caixas.c"

void relatorios(){
  int caixas = 10, tamanhoEntrada = 1000, opcao;
  int temposRegistrados[tamanhoEntrada];

  FILE *arqEntradas;
  arqEntradas = fopen("arquivoEntradasValidacao.txt", "r");

  int id, qntde, preco, tempo, pagamento;
  int i = 0;
  while(!feof(arqEntradas)){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    temposRegistrados[i] = tempo;
    i++;
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
        // itensMaisVendidos();
        // itensMenosVendidos();
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
      // case 6:
      //   itensMaisVendidos();
      //   break;
      // case 7:
      //   itensMenosVendidos();
      //   break;
      // case 8:
      //   itensNaoVendidos();
      //   break;
      default:
        break;
    }
    opcoes();
    scanf("%d", &opcao);
  }

  fclose(arqEntradas);
}

void main(){
  relatorios();
}