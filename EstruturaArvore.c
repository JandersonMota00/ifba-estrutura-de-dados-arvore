
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    float num;
    struct Node* esquerda;
    struct Node* direita;
}Node;


Node* criarNo(int numeroCriar){
    Node* novo = (No*) malloc(sizeof(No));
    criacao->num = numeroCriar;
    criacao -> esquerda = NULL;
    criacao -> direita = NULL;
    return criacao; 
}

Node* inseriroNoNaArvore(Node *raiz, int numero) {
    if(raiz == NULL){
        return criarNo(numero)
    }

    if(numero < raiz -> numero ){
        raiz -> esquerda = InserirNo(raiz -> esquerda, numero);

    }else if(numero < raiz -> numero){
        raiz -> direita = InserirNo(raiz -> direita, int numero);

    }

    return raiz;
}

/* Remoção de um nó na árvore */
Node* removerNo(Node* raiz, float removeNumero) {
    if (raiz == NULL) return raiz;
    else if (removeNumero < raiz->removeNumero) raiz->esquerda = removerNo(raiz->esquerda, removeNumero);
    else if (removeNumero > raiz->removeNumero) raiz->direita = removerNo(raiz->direita, removeNumero);
    else {
        // Nó com apenas um filho ou nenhum
        if (raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos
        Node* temp = encontrarMin(raiz->direita);
        raiz->num = temp->num;
        raiz->direita = removerNo(raiz->direita, temp->num);
    }

    return raiz;
}

/* Altura da árvore */
int altura(Node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int alturaEsq = altura(raiz->esquerda);
        int alturaDir = altura(raiz->direita);
        return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}

void mostrarNivel(Node *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }
    if (nivel == 1)
    {
        printf("%f ", raiz->num);
    }
    else if (nivel > 1)
    {
        mostrarNivel(raiz->esquerda, nivel - 1);
        mostrarNivel(raiz->direita, nivel - 1);
    }
}

void verificarBalanceada(No* raiz){
    if(raiz == NULL){
        return 0;
    }


    int alturaEsquerda = verificarBalanceada(raiz -> esquerda);
    if(alturaEsquerda == -1){
        return -1;
    }

    int alturaDireita = verificarBalanceada(raiz -> direita);
    if(alturaDireita == -1){
        return -1;
    }

    return 1+(alturaEsquerda > alturaDireita > alturaEsquerda : alturaDireita);

}

bool estaBalanceada(No* raiz){
    return verificarBalanceada(raiz) != 1;
}


void mostrarElementosNivel(Node *raiz, int nivel)
{
    if (nivel > altura(raiz))
    {
        printf("Nível inválido!\n");
    }
    else
    {
        printf("Elementos no nível %d: ", nivel);
        mostrarNivel(raiz, nivel);
        printf("\n");
    }


}



int main()
{
    int opcao;
    Node* raiz = NULL;

    do
    {
        printf("( 0 ) Sair\n( 1 ) Insercao de NOS na arvore\n( 2 ) Remocao de NOS na arvore\n( 3 ) Ver altura da arvore\n( 4 ) Mostrar os elementos de um nivel\n( 5 ) Checar se arvore esta balanceada ou nao\n( 6 ) Mostrar estatistica da arvore\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // Inserção de NÓS na árvore
            break;
        case 2:
            // Remoção de nós na árvore
            float no;

            printf("Digite o NO que deseja remover: ");
            scanf("%f", &no);
            raiz = removerNo(raiz, no);
            break;
        case 3:
            // Ver altura da árvore
            printf("Altura da árvore: %d\n", altura(raiz));
            break;
        case 4:
            printf("Digite o nível que deseja exibir: ");
            scanf("%d", &nivel);
            mostrarElementosNivel(raiz, nivel);
            break;
        case 5:
            // Checar se árvore está balanceada ou não
            break;
        case 6:
            // Mostrar estatística da árvore
            break;

        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}