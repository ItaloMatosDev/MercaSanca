#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limite_por_registro 100
#define numero_maximo_de_produtos 500 //a ser definido, valor apenas para os testes



  //        Essa funcao, ao ser executada, começará a receber os dados dos produtos: id(qualquer numero    //
 //  maior que zero), nome do produto(ate 20 caracteres - podemos aumentar se for necessario) e o preço   //
//   unitario(qualquer numero maior que zero)                                                            //

 //   O sistema tem limite de 100 registros por cadastro, e ele interrompe a ação quando   //
//  insere-se um id ou preco inválido                                                     //

//por fim, adicionará essas informações de forma organizada em um arquivo csv/planilha do excel

void cadastro_de_produtos(){
    int id_produto[limite_por_registro], id_produto_lido[numero_maximo_de_produtos], i =0, x, y, count = 0, conferir;
    char nome_produto[limite_por_registro][40], nome_produto_lido[numero_maximo_de_produtos][40], temp;
    float preco_unitario[limite_por_registro], preco_unitario_lido[numero_maximo_de_produtos];

    FILE *cadastro ;

    cadastro = fopen("cadastrodeitens.csv", "a+");

    if(cadastro == NULL){
        printf("Erro, confira se o excel nao esta aberto simultaneamente");
        exit(0);
    }
    FILE *itens;

    itens = fopen("quantidadadePorItem.csv", "a"); 

    if(itens == NULL){
        printf("erro ao executar o arquivo");
        exit(0);
    }
    
    printf("\n-------- Cadastro de Produtos --------\n");
    printf("insira 0 no id ou no preco para finalizar\n");
    while(!feof(cadastro)){  
        fscanf(cadastro, "%d;", &id_produto_lido[i]);
        fscanf(cadastro, "%40[^;];", nome_produto_lido[i]);
        fscanf(cadastro, "%f\n", &preco_unitario_lido[i]);
        count++;
        i++;
    }
    

    for (int i = 0; i<limite_por_registro; i++){
        printf("Id: ");
        scanf("%d", &id_produto[i]);
        scanf("%c", &temp);     
        
        printf("Nome do produto: ");
        scanf("%40[^\n]", nome_produto[i]);
    

        printf("preco individual: ");
        scanf("%f", &preco_unitario[i]);

        x = 0, y = 0;
        for(int j = 0; j<count; j++){
            if(id_produto[i] == id_produto_lido[j] && id_produto[i] !=0){
                printf("Esse id ja existe no sistema.\n");
                x = 1;
                break;
            } else if(strcmp(nome_produto[i], nome_produto_lido[j]) == 0){
                printf("Esse produto ja existe no sistema com esse ou outro id.\n");
                y = 1;
                break;
         } 
        }
        if(x==1||y==1) continue;
        
       

        if(id_produto[i]<= 0 || preco_unitario[i]<= 0){
        printf("fim do cadastro");
         break;
        }
        fprintf(cadastro, "%d;%s;%.2f\n", id_produto[i], nome_produto[i], preco_unitario[i]);
        fprintf(itens, "%d;0\n", id_produto[i]);
    }

    
    fclose(itens);
    fclose(cadastro);
}

void registro_de_vendas(int *quantidadetotal, int *precototal, int *pagamentoutilizado){
    int id, quantidade, quantidade_produto[numero_maximo_de_produtos], i, id_produto_lido[numero_maximo_de_produtos], count = 0, indice[numero_maximo_de_produtos];
    char nome_produto_lido[numero_maximo_de_produtos][40];
    int iditem[numero_maximo_de_produtos], qteitem[numero_maximo_de_produtos];
    float preco_unitario_lido[numero_maximo_de_produtos],  preco[numero_maximo_de_produtos];

    FILE *cadastro ;

    cadastro = fopen("cadastrodeitens.csv", "r");

    if(cadastro == NULL){
        printf("erro");
        exit(0);
    }

    i = 0;
    while(!feof(cadastro)){  
        fscanf(cadastro, "%d;", &id_produto_lido[i]);
        fscanf(cadastro, "%40[^;];", nome_produto_lido[i]);
        fscanf(cadastro, "%f\n", &preco_unitario_lido[i]);
        count++;
        i++;
    }

    fclose(cadastro);
        printf("\n---------- REGISTRO DE VENDA ------------\n");
        printf("Bem vindo ao registro de venda! Pressione 0 a qualquer momento no id para encerrar\n");

        printf("Id do produto: ");
        scanf("%d", &id);
        printf("quantidade: ");
        scanf("%d", &quantidade);

        int j = 0;
        *quantidadetotal = 0;
        *precototal = 0;
        float precototalfloat = 0;
        
    while(id != 0){
        for(i = 0; i<count; i++){
            if(id == id_produto_lido[i]){
                indice[j] = i;
                quantidade_produto[i] = quantidade;
                preco[i] = preco_unitario_lido[i] * quantidade;
                precototalfloat += preco[i];
                *precototal += preco[i];
                *quantidadetotal += quantidade;
                j++;
                break;
            }
        } 
        printf("ID do produto: ");
        scanf("%d", &id);
        printf("quantidade: ");
        scanf("%d", &quantidade);
    }

    printf("\nRegistrado!\n");
    printf("O preco total dessa venda foi de R$%.2f\n\n", precototalfloat);
    
    printf("Qual foi o metodo de pagamento?\n");
    printf("Pressione: \n");
    printf("0 - Pix\n");
    printf("1 - Cartao de Debito\n");
    printf("2 - Cartao de Credito\n");
    printf("3 - Dinheiro\n");
    printf("Insira aqui: ");
    scanf("%d", pagamentoutilizado);
    printf("\nObrigado! Retornando para a tela inicial... \n");

    /*printf("vendemos os produtos: \n");

    for(i=0; i<j; i++){
        int x = indice[i];
        printf("%s: %.2f\n", nome_produto_lido[x], preco[x]);
    }

    printf("quantidade total de produtos vendidos: %d\n", quantidadetotal);
    printf("preco total arrecadado na venda: %.2f\n", precototal);*/

    FILE *itens;

    itens = fopen("quantidadadePorItem.csv", "r"); //arquivo com o id do prod e a quantidade geral vendida dele
    //fprintf(itens, "oi");

    if(itens == NULL){
        printf("erro ao executar o arquivo");
        exit(0);
    }

    for(int i=0; i<count; i++){
        fscanf(itens, "%d;%d\n", &iditem[i], &qteitem[i]);
        //printf("%d    %d\n", iditem[i], qteitem[i]);
            for(int z=0; z<j; z++){
                if(indice[z] == i)
                    qteitem[i] += preco[i]/preco_unitario_lido[i];
            }
    }

    fclose(itens);
    fopen("quantidadadePorItem.csv", "w");
    //fprintf(itens, "oi");

    if(itens == NULL){
        printf("erro ao executar o arquivo");
        exit(0);
    }

    for(int i=0; i<count; i++)
        fprintf(itens, "%d;%d\n", iditem[i], qteitem[i]); //adicionando as novas quantidades
    fclose(itens);


}


/*int main(){

// recomendo usar uma funcao de cada vez pra n dar ruim - so remover o //


//cadastro_de_produtos(); 
//registro_de_vendas();


    return 0;
}*/