#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct No{
    int valor;
    struct No * prox;
}No;

No *topo= NULL;
int tam = 0;

void add(int valor){

        No * novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = NULL;

        //1 caso: pilha vazia
        if(topo == NULL){
            topo = novo;
        // 2 caso: pilha nao esta vazia e eu quero add no topo
        }else{
            novo->prox = topo;
            topo = novo;
        }
        tam++;
}

int remover(){
    int valor;
    if(tam > 0){
        No *lixo = topo;
        topo = topo->prox;
        valor = lixo->valor;
        free(lixo);
        tam--;
        return valor;
    }else{
        printf("Pilha esta vazia!");
        return -1;
    }   
}

void imprimir(){
    No *aux = topo;
        for (int i = 0; i<tam; i++){
            printf("Valor:%d\n", aux->valor);
            aux = aux->prox;
        }
}


int main(){

    char expressao[100];
    int i;

    printf("digite uma expressao: \n"); 
    fgets(expressao, sizeof(expressao), stdin);

    for(i = 0; expressao[i] != '\0'; i++){
        if (isdigit(expressao[i])){
            int valor = expressao[i] - '0';
            add(valor);
        } else if( expressao[i] == ' '){
                continue;
        }else {
            switch(expressao[i]){
                case '*':
                    topo -> prox -> valor = topo -> prox -> valor * topo -> valor;
                    remover();
                    break;
                case '/':
                    topo -> prox -> valor = topo -> prox -> valor / topo -> valor;
                    remover();
                    break;
                case '-':
                    topo -> prox -> valor = topo -> prox -> valor - topo -> valor;
                    remover();
                    break;
                case '+':
                    topo -> prox -> valor = topo -> prox -> valor + topo -> valor;
                    remover();
                    break;
                default:
                    break;
            }
        }

    }


    imprimir();

    return 0;

}