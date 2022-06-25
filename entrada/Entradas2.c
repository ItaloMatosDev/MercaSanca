#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//método de pagamento 
void metod_pag (int n, int *mp){
    
    // printf("dentro da funcao");
    for (int i = 0; i < n; i++){
            mp[i] = rand () % 3;
            // printf("dentro do for\n");
            printf ("%d", mp[i]);
        printf ("\n");
    }
    printf ("\n");
    
}


int main () {

    int n = 5;
    int sale[n][4];
    int *mp;
    int ident [20], tottime [3], totvalue = 0, totitens = 0, sumtime=0 ;

    mp  = (int*) malloc (n * sizeof(int));

    //id de produto
    srand (time(NULL));
    for (int i = 0; i < 20; i++){
        ident [i] = rand () % 100;
        printf ("[ %d ] \n", ident[i]);
    }

    for(int i=0; i<n; i++){
        printf("%d\n", ident[i]);
    }

    printf("%d %d\n", ident[0], ident[1]);
    
    printf ("\n");
    
    
    //matriz das entradas 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            sale[i][j] = rand () % 10;
            printf ("%d ", sale[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    
    
    metod_pag(n, mp);
    
    //valor total
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 1; j++){
        totvalue = totvalue + sale [i][j];
;        }
    }
    printf ("Valor Total: %d ", totvalue);
    printf ("\n");
    
    
    //itens totais
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 1; j++){
        totitens = totitens + sale [i][1];
        }
    }
    printf ("Itens Totais: %d ", totitens);
    printf ("\n");
    
    //vetor do tempo e a soma do total 
    for (int i = 0; i < n; i++){
        tottime [i] = rand () % 10;
        sumtime = sumtime + tottime[i];
    }
    printf ("Tempo Total: %d ", sumtime);

    FILE *arqEnt;

    arqEnt = fopen("matrizdeentradas.txt", "w");

    if(arqEnt == NULL){
        printf("Erro ao executar o arquivo");
        exit(0);
    }
    int matriz[n][5];
printf("%d %d\n", ident[0], ident[1]);

    for(int j=0; j<5; j++){
        for(int i=0; i<n; i++){
            if(j==0)
                matriz[i][j] = ident[i];
            else if(j>0 && j<4)
                matriz[i][j] = sale[i][j-1];
            else    
                matriz[i][j] = mp[i];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            fprintf(arqEnt, "%d ", matriz[i][j]);
        }fprintf(arqEnt, "\n");
    }

fclose(arqEnt);

return 0;
}