#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int metodoPagamento(){
//   srand(time(NULL));

//   int valor; 
//   valor = rand() % 10;
//   printf("%d ", valor);
//   return valor;
// }

void gerarEntradas(int qtdEntradas){
  int entradas[qtdEntradas][5];
  srand(time(NULL));
  int id, itens, preco, tempo, pagamento;
  for(int i = 0; i < qtdEntradas; i++){
    id = rand() % 10*qtdEntradas + 1;
    itens = rand() % 5*qtdEntradas + 1;
    preco = rand() % 10*qtdEntradas + 1;
    tempo = rand() % 10*qtdEntradas + 1;
    pagamento = rand() % 3;
    entradas[i][0] = id;
    entradas[i][1] = itens;
    entradas[i][2] = preco;
    entradas[i][3] = tempo;
    entradas[i][4] = pagamento;
  }

  for (int i = 0; i < qtdEntradas; i++){
    for (int j = 0; j < 5; j++){
      printf("%d\t\t", entradas[i][j]);
    }
    printf("\n");
  }
}

int main () {
  gerarEntradas(10);
}