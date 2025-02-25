#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct No{
    int pedido;
    char nome[100];  
    char recheio[10];
    char tamanho[10];
    float valor;
    struct No * prox;
} No;

No *inicio = NULL;
No *fim = NULL;
int tam = 0;

void add(int pedido, const char* nome, const char*recheio, const char*tamanho, float valor){

   No * novo = malloc(sizeof(No));
    novo->pedido = pedido; 
    strcpy(novo->nome, nome); 
    strcpy(novo->recheio, recheio); 
    strcpy(novo->tamanho, tamanho); 
    novo->valor = valor; 
    novo->prox = NULL;

    //1 caso: fila vazia
    //obs: eh necessario mudar algo aqui para que o fim funcione?
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    // 2 caso: fila nao esta vazia e eu quero add fim
    }else{
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

int remover(){
        int pedido = -1;
        if(tam == 0){
            printf("fila vazia!\n");
        }else {
            No *lixo = inicio;
            inicio = inicio->prox;
            if(tam == 1){
                fim = NULL;
            }   
            pedido = lixo->pedido;
            printf("O pedido %d foi removido com sucesso! \n", pedido);
            free(lixo);
            tam--; 
        }
        return pedido;
}

void imprimir() {
    No* aux = inicio;
        if(aux == NULL){
            printf("Nenhum pedido foi cadastrado :(\n");
        }else{
            for (int i = 0; i < tam; i++) {
        
                    printf("Pedido: %d, Nome: %s, Recheio: %s, Tamanho: %s, Valor: %.2f\n",aux->pedido, aux->nome, aux->recheio, aux->tamanho, aux->valor);
                    aux = aux->prox;
                }
        }
}

int main(){
    int removerpedido = 0;
    int escolha;
    char nome[100], recheio[10], tamanho[2];
    float valor = 0;
    int pedido = 0;
    
        for(int menu = 0; menu == 0; ){
                printf("O que deseja fazer? \n");
                printf("[1]Adicionar pedido.\n[2]Remover pedido.\n[3]Visualizar pedidos.\n[4]Fechar programa.\n");
                scanf("%d", &escolha); 
                    #ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear");  
                    #endif
            if(escolha == 1){
                
                for (int parar = 0; parar == 0; ) {
                    pedido++;
                    printf("Pedido: %d\n", pedido);
            
                    printf("Digite apenas o primeiro nome do cliente (Sem espaços): ");
                    scanf("%s", nome);  
                    getchar(); 
            
                    printf("Digite o recheio da pizza (Sem espaços): ");
                    scanf("%s", recheio); 
                    getchar(); 
            
                    printf("Digite o tamanho da pizza (P, M, G): ");
                    scanf("%s", tamanho);  
                    getchar(); 
            
                    printf("Digite o valor total da pizza: ");
                    scanf("%f", &valor);  
                    getchar(); 
            
                    printf("Deseja adicionar mais pedidos? [0]SIM [1]NÃO: ");
                    scanf("%d", &parar);  
                    getchar(); 
            
                    add(pedido, nome, recheio, tamanho, valor);
                    
                    #ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear"); 
                    #endif
                }
                
            }else if(escolha == 2){
                
                    for(int parar = 0; parar == 0; ){
                    remover();
                    printf("Voltar para [5]Menu.\n");
                    scanf("%d", &escolha);
                    if(escolha == 5){
                        parar = 1;
                    #ifdef _WIN32
                        system("cls"); 
                    #else
                        system("clear"); 
                    #endif
                    }
                }
                    
            }else if(escolha == 3){
                for(int parar = 0; parar == 0; ){
                    
                    imprimir();
                    
                    printf("Voltar para [5]Menu.\n");
                    scanf("%d", &escolha);
                    if(escolha == 5){
                        parar = 1;
                    #ifdef _WIN32
                        system("cls"); 
                    #else
                        system("clear"); 
                    #endif
                    };
                }
            }else {
                menu = 1;
            }
            
        }

    return 0;
}
