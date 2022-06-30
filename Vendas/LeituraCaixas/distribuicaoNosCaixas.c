#include <stdio.h>
#include <stdlib.h>

#define CAIXAS 3

// Nesse arquivo farei a distribuicao das vendas
// nos caixas disponiveis, de acordo com os tempos fornecidos na entrada

// -------------------------------------------------------------------------

// Considerando tres caixas(pode ser qualquer numero de caixas)
// inicialmente temos essa distribuiçao de tempo:
// caixas   1   2   3 ... n
// tempos   0   0   0 ... 0
// tempo igual a 0 significa que todos os caixas estao disponiveis no inicio


// Na funcao a seguir, considerando a seguinte distribuiçao de tempos:
// caixas   1   2   3
// tempos   20  5   10
// a funcao deve retornar o valor 1
// que é o indice do caixa 2 que tem o menor tempo entre todos (tempo 5)
int buscaMenorTempoRetornaIndice(int vetorTempos[], int caixas){
  int indice = 0;
  int menorTempo = vetorTempos[0];
  for(int i = 1; i < caixas; i++){
    if(vetorTempos[i] < menorTempo){
      indice = i;
      menorTempo = vetorTempos[i];
    }
  }
  return indice;
}

// Dado o vetor contendo os tempos, o valor de tempo e a quantidade de caixas, 
// é percorrido todo o vetor para subtrair o valor de tempo de cada um deles, exemplo:
// caixas   1   2   3
// tempos   20  5   10

// passando o valor 2 para subtraiTempos, assim como o vetor de caixas e tempos, temos:
// caixas   1   2   3
// tempos   18  3   8
int subtraiTempos(int vetorTempos[], int tempo, int qntdCaixas){
  for(int i = 0; i < qntdCaixas; i++){
    vetorTempos[i] = vetorTempos[i] - tempo;
  }
  return *vetorTempos;
}

// Um caixa é considerado disponivel se seu valor de tempo atual é menor ou igual a 0,
// e é considerado nao disponivel se nenhum valor de tempo for menor ou igual a 0
// caixas   1   2   3
// tempos   4   3   1
// neste exemplo, nao temos caixa disponivel
int caixaDisponivel(int vetorTemposCaixa[], int numeroCaixas){
  // 1 = true
  // 0 = false
  for(int i = 0; i < numeroCaixas; i++){
    if(vetorTemposCaixa[i] <= 0 ) return 1;
  }
  return 0;
}

// Dado o vetor de tempos, o indice do caixa e o valor de tempo
// esse valor é atualizado
// caixas   1   2   3
// tempos   4   3   -2
// considerando o indice 2 (valor do tempo é -2, entao esta disponivel)
// e um tempo igual a 10, o vetor de tempos é atualizado
// caixas   1   2   3
// tempos   4   3   10
int atualizaVetorTempos(int vetorTempos[], int indiceCaixaDisponivel, int novoTempo){
  vetorTempos[indiceCaixaDisponivel] = novoTempo;
  return *vetorTempos;
}

// Dado o numero de caixas, todos os tempos sao setados para 0,
// indicando que no inicio todos os caixas estao disponiveis
// caixas   1   2   3
// tempos   0   0   0
int inicializaCaixas(int vetorTempos[], int qtdeCaixas){
  for (int i = 0; i < qtdeCaixas; i++){
    vetorTempos[i] = 0;
  }
  return *vetorTempos;
}

// retorna o indice
int indiceTempoAtual(int indice) {
  return indice;
}

void distribuiVendasNosCaixas(int temposDeEntrada[], int tamanhoEntrada, int caixas) {
  int auxiliarTempos[caixas];
  int registrosCaixas[tamanhoEntrada][caixas];
  // cada caixa pode ter ate 10 vendas, deve armazenar indice da venda

  // popula matriz com todos os valores sendo -1
  for (int i = 0; i < tamanhoEntrada; i++){
    for(int j = 0; j < caixas; j++){
      registrosCaixas[i][j] = -1;
    }
  }

  inicializaCaixas(auxiliarTempos, caixas);

  int contador = 0;
  int prox = temposDeEntrada[0];

  while(contador <  tamanhoEntrada){

    // printf("\nvalor do proximo: %d\n", prox);

    if (caixaDisponivel(auxiliarTempos, caixas)){
      int menorCaixaDisponivel = buscaMenorTempoRetornaIndice(auxiliarTempos, caixas);

      // printf("caixa disponivel no indice: %d\n", menorCaixaDisponivel);
      // preciso guardar a informacao de que o indice 0 dos tempos de entrada foi para o caixa 0
      // posso guardar isso numa matriz

      atualizaVetorTempos(auxiliarTempos, menorCaixaDisponivel, prox);

      // printf("valores atuais de tempo\n");
      // for(int i = 0; i < caixas; i++){
      //   printf("%d ", auxiliarTempos[i]);
      // }
      // printf("\n");

      for(int i = 0; i < tamanhoEntrada; i++){
        if(registrosCaixas[i][menorCaixaDisponivel] == -1) {
          registrosCaixas[i][menorCaixaDisponivel] = contador;
          break;
        }
      }

      contador++;
      prox = temposDeEntrada[contador];

    }
    else {
      // printf("sem caixa disponivel\n");
      subtraiTempos(auxiliarTempos, prox, caixas);
    }
  }

  printf("\n");
  // for(int i = 0; i < tamanhoEntrada; i++){
  //   for(int j = 0; j < caixas; j++){
  //     printf("%d ", registrosCaixas[i][j]);
  //   }
  //   printf("\n");
  // }

  FILE *arq;
  arq = fopen("resultadoDistribuicao.txt", "w");

  for(int i = 0; i < tamanhoEntrada; i++){
    for(int j = 0; j < caixas; j++){
      fprintf(arq, "%d\t", registrosCaixas[i][j]);
    }
    fprintf(arq, "\n");
  }
  fclose(arq);
}

void totalVendasPorCaixa(int tamanho, int caixas) {
  FILE *arqResultado, *arqEntradas;
  arqEntradas = fopen("../entrada/registrodevendas.txt", "r");
  arqResultado = fopen("resultadoDistribuicao.txt", "r");

  int entradas[tamanho][5];
  int resultados[tamanho][caixas];

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanho; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    entradas[i][0] = id;
    entradas[i][1] = qntde;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }
  int valor;
  for (int i = 0; i < tamanho; i++){
    for(int j = 0; j < caixas; j++){
      fscanf(arqResultado, "%d ", &valor);
      resultados[i][j] = valor;
    }
  }

  int vendasPorCaixas[caixas];
  for (int i = 0; i < caixas; i++) vendasPorCaixas[i] = 0;

  int indice, precoEntrada;
  for(int j = 0; j < caixas; j++){
    for(int i = 0; i < tamanho; i++){
      if (resultados[i][j] != -1 ){
        indice = resultados[i][j];
        precoEntrada = entradas[indice][2];
        vendasPorCaixas[j] += precoEntrada;
      }
    }
  }

  printf("\nVendas por caixa: \n");
  for (int i = 0; i < caixas; i++) {
    printf("Caixa %d: %d sanquinhas\n", i+1, vendasPorCaixas[i]);
  };

  fclose(arqResultado);
  fclose(arqEntradas);
}

void tempoMedioPorCaixa(int tamanho, int caixas){
  FILE *arqResultado, *arqEntradas;
  arqEntradas = fopen("../entrada/registrodevendas.txt", "r");
  arqResultado = fopen("resultadoDistribuicao.txt", "r");

  int entradas[tamanho][5];
  int resultados[tamanho][caixas];

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanho; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    entradas[i][0] = id;
    entradas[i][1] = qntde;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }
  int valor;
  for (int i = 0; i < tamanho; i++){
    for(int j = 0; j < caixas; j++){
      fscanf(arqResultado, "%d ", &valor);
      resultados[i][j] = valor;
    }
  }

  int tempoPorCaixas[caixas];
  for (int i = 0; i < caixas; i++) tempoPorCaixas[i] = 0;

  int indice, tempoEntrada;
  for(int j = 0; j < caixas; j++){
    for(int i = 0; i < tamanho; i++){
      if (resultados[i][j] != -1 ){
        indice = resultados[i][j];
        tempoEntrada = entradas[indice][3];
        tempoPorCaixas[j] += tempoEntrada;
      }
    }
  }

  printf("\nTempos por caixa: \n");
  for (int i = 0; i < caixas; i++) {
    printf("Caixa %d: %d unidades de tempo\n", i+1, tempoPorCaixas[i]);
  };

  fclose(arqResultado);
  fclose(arqEntradas);
}

void vendasPorMetodoDePagamento(int tamanho, int caixas) {
  FILE *arqResultado, *arqEntradas;
  arqEntradas = fopen("../entrada/registrodevendas.txt", "r");
  int entradas[tamanho][5];
  int resultados[tamanho][caixas];

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanho; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    entradas[i][0] = id;
    entradas[i][1] = qntde;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }

  int metodosPagamentos[4] = {0, 0, 0, 0};
  int indiceMetodo;

  for (int i = 0; i < tamanho; i++){
    indiceMetodo = entradas[i][4];
    metodosPagamentos[indiceMetodo] += 1;
  }
  printf("\n\nTotal de vendas efetuadas de acordo com o metodo de pagamento:");
  printf("\nPix: %d\n", metodosPagamentos[0]);
  printf("\nDebito: %d\n", metodosPagamentos[1]);
  printf("\nCredito: %d\n", metodosPagamentos[2]);
  printf("\nDinheiro: %d\n", metodosPagamentos[3]);
}

void metodoPagamentoMaisUtilizado(int tamanho, int caixas){
  FILE *arqResultado, *arqEntradas;
  arqEntradas = fopen("../entrada/registrodevendas.txt", "r");
  int entradas[tamanho][5];
  int resultados[tamanho][caixas];

  int id, qntde, preco, tempo, pagamento;
  for (int i = 0; i < tamanho; i++){
    fscanf(arqEntradas, "%d %d %d %d %d", &id, &qntde, &preco, &tempo, &pagamento);
    entradas[i][0] = id;
    entradas[i][1] = qntde;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }
  int totalPagamentos[4] = {0, 0, 0, 0};
  int indiceMetodo;

  for (int i = 0; i < tamanho; i++){
    indiceMetodo = entradas[i][4];
    totalPagamentos[indiceMetodo] += 1;
  }

  // guarda qual metodo de pagamento foi mais utilizado (total)
  int maior = totalPagamentos[0];
  for(int i = 0; i < caixas; i++){
    if (totalPagamentos[i] > maior)
      maior = totalPagamentos[i];
  }

  printf("\n\nO(s) metodo(s) de pagamento mais utilizado(s): ");
  for(int i = 0; i < caixas; i++){

    // printf("\nindice: %d \tmaior: %d", totalPagamentos[i], maior);
    if(totalPagamentos[i] == maior){
      switch (i)
      {
      case 0:
        printf("\nPix: %d\n\n", totalPagamentos[i]);
        break;

      case 1:
        printf("\nDebito: %d\n\n", totalPagamentos[i]);
        break;

      case 2:
        printf("\nCredito: %d\n\n", totalPagamentos[i]);
        break;

      case 3:
        printf("\nDinheiro: %d\n\n", totalPagamentos[i]);
        break;
      default:
        break;
      }
    }
  }
}

// void main() {
//   int caixas = 4, tamanhoEntrada = 6;
//   int temposRegistrados[] = {10, 10, 10, 4, 4, 4};
//   distribuiVendasNosCaixas(temposRegistrados, tamanhoEntrada, caixas);
//   totalVendasPorCaixa(6, 4);
//   tempoMedioPorCaixa(6, 4);
//   vendasPorMetodoDePagamento(6, 4);
//   metodoPagamentoMaisUtilizado(6, 4);
// }