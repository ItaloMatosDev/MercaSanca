#include <stdio.h>

void main() {
  FILE *arq;
  
  // Abre o arquivo 6EntradasTeste.txt para leitura
  arq = fopen("6EntradasTeste.txt", "rt");
  
  // Se houve erro na abertura
  if (arq == NULL) {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  int id, quantidade, preco, tempo, pagamento;

  // retorna a leitura para o inicio do arquivo
  rewind(arq);

  // enquanto nao for o fim do arquivo
  int ids[6];
  int quantidades[6];
  int precos[6];
  int tempos[6];
  int pagamentos[6];

  int i = 0;

  while(!feof(arq)){
    // le cada item do arquivo txt como inteiro
    fscanf(arq, "%d %d %d %d %d", &id, &quantidade, &preco, &tempo, &pagamento);
    // printf("%d %d %d %d %d\n", id, quantidade, preco, tempo, pagamento);
    quantidades[i] = quantidade;
    precos[i] = preco;
    tempos[i] = tempo;
    pagamentos[i] = pagamento;
    i++;
  }

  for(int i = 0; i < 6; i++){
    printf("%d\n", tempos[i]);
  }
  
  fclose(arq);
}