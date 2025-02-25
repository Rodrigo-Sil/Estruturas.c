#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    int matricula;
    struct pessoa *esq;
    struct pessoa *dir;

}Aluno;

Aluno *raiz = NULL;
int tam = 0;



Aluno* buscar(int matricula, Aluno *aux)
{
    if(aux == NULL){ //se a raiz é nula
        return NULL;
    }else if( matricula == aux->matricula){ //o valor é a raiz
        return aux; //retornar a raiz
    }else if(matricula < aux->matricula)
    {
        if(aux->esq != NULL)
        {
            return buscar(matricula, aux->esq);
        }else{
            return aux;  // pai do oelemento(se ele existisse)
        }
    }else{ // se o valor for maior que a raiz
        if(aux->dir != NULL)
        {
            return buscar(matricula, aux->dir);
        }else{
            return aux;  // pai do oelemento(se ele existisse)
        }

    }
}




void add(int matricula) //função adcionar
{
    Aluno *novo = malloc(sizeof(Aluno));  // criar o nó
    novo->matricula = matricula; //atribuir o valor da variavel valor da struct
    novo->esq = NULL; // apontar ponteiros para nulo
    novo->dir = NULL;  // apontar ponteiros para nulo;

    Aluno* aux = buscar(matricula, raiz); // nó que vai receber o nó do retorno da da função

    if(aux == NULL) // se não ha nós na arvore
    {
        raiz = novo;
    }else if(aux->matricula > matricula) // se o valor é menor que a raiz atual do buscar
    { 
        aux->esq = novo; // raiz atual recebe nó a sua esquerda
    }else // se for maior
    {
        aux->dir = novo; // a raiz atual recebe nó a sua direita
    }
}




Aluno* remover(Aluno* lixo, int matricula){

    if(lixo == NULL) // se o nó não está na arvore
    { 
        printf("Aluno não matriculado!\n");
        return NULL;
    } 
    else // procurar nó
        {
            if(lixo->matricula == matricula){ //se encontrou o nó

                // remoção se for uma folha
                if (lixo->dir == NULL && lixo->esq == NULL) 
                {
                    printf("O aluno de matricula %d foi removido!\n", lixo->matricula);
                    free(lixo);
                    return NULL;
                }
                else // não é folha
                {
                    Aluno* aux;

                    //remover nó com 2 filhos
                    if(lixo->dir != NULL && lixo->esq != NULL)
                    {
                        //remover nós com dois filhos

                        //buscar o maior dos menores para balancear a arvore
                        aux = lixo->esq;

                        while (aux->dir != NULL)
                        {
                            aux = aux->dir; //o mais a direita
                        }

                        lixo->matricula = aux->matricula; // o valor do no a ser removido é substituido pelo maior do menor
                        aux->matricula = matricula; // o valor do maior dos menores recebe o valor procurado
                        lixo->esq = remover(lixo->esq, matricula); //chama a função novamente para remover o valor que agr é uma folha
            
                        return lixo; 

                    }
                    else{
                        // remoção de quando tem pelo menos um filho

                        if (lixo->dir == NULL && lixo->esq != NULL) // quando só tem o filho esquerdo
                        {
                            aux = lixo->esq; // nó fliho vai receber o no a esquerda do nó a ser removido
                            printf("O aluno de matricula %d foi removido\n", lixo->matricula);
                            free(lixo); // remover nó procurado
                            return aux; // retornar filho
                        }
                        else // quando só tem o filho direito
                        {
                            aux = lixo->dir; // nó fliho vai receber o no a direita do nó a ser removido
                            printf("O aluno de matricula %d foi removido\n", lixo->matricula);
                            free(lixo); // remover nó procurado
                            return aux;  // retornar filho
                        }
                    
                        }
                    }
                }
                
                else // se não achou o nó
                    {
                        if(lixo->matricula > matricula)
                        { // buscar valor menor que raiz
                        lixo->esq = remover(lixo->esq, matricula);
                        }
                        else
                        { // buscar valor maior que raiz
                        lixo->dir = remover(lixo->dir, matricula);
                        }
                    }
                    
                }

    return lixo;
}


void imprimir_ordem(Aluno* aux){ //imprimir do manor para o maior
    if(aux != NULL){
        imprimir_ordem(aux->esq); //chamar recursivamente ate chegar ao no mais a esquerda
        printf("%d\n", aux->matricula); //imprimi o valor
        imprimir_ordem(aux->dir); // fazendo o backtracking verificando se o no pai tem filho a direita
    }
}



// Simular cadastro de alunos em um turma (por matricula):


int main()
{   
    int i, num_alunos, matricula, opcao;
    char escolha = 'S';

    while (escolha == 's'|| escolha == 'S')
    {
        printf("__________________________________\n| 1 - Adicionar alunos a turma    |\n|_________________________________|\n| 2 - Cancelar matrícula na turma |\n|_________________________________|\n| 3 - Ver alunos matriculados     |\n|_________________________________|\n\n");
        printf("Digite um numero para a operação: ");
        scanf("%d", &opcao);


        if (opcao == 1){
            
            printf("\nDigite quantos alunos serão cadastrados: ");
            scanf("%d", &num_alunos);

            for(i = 0; i < num_alunos; i++){
                printf("\nCasdatrar novo aluno\n");
                printf("Digite a matricula: ");
                scanf("%d", &matricula);

                add(matricula);
            }
        }            
        else if(opcao == 2){

            printf("Digite a mtricula a ser cancelada: ");
            scanf("%d", &matricula);
            raiz = remover(raiz, matricula);
        }
        else if(opcao == 3){
            printf("Alunos da turma em ordem numérica:\n");

            imprimir_ordem(raiz);
        }
        else{
            printf("Opção inválida!\n");
            continue;
        }

        printf("Deseja realizar outra operação?\n__________\n| S - sim |\n|_________|\n| N - não |\n|_________|\n");
        getchar();
        scanf("%c", &escolha);
        if (escolha != 's' && escolha != 'S'){
            break;
        } 
        
    }

    return 0;
}
