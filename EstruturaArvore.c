
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    float num;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node *InseriroNo(Node *raiz, int numero)
{
    if (raiz == NULL)
    {
        return criarNo(numero)
    }

    if (numero < raiz->numero)
    {
        raiz->esquerda = InserirNo(raiz->esquerda, numero);
    }
    else if (numero < raiz->numero)
    {
        raiz->direita = InserirNo(raiz->direita, int numero);
    }

    return raiz;
}

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

int main()
{
    int opcao;

    do
    {
        printf("( 0 ) Sair\n( 1 ) Insercao de NOS na arvore\n( 2 ) Remocao de NOS na arvore\n( 3 ) Ver altura da arvore\n( 4 ) Mostrar os elementos de um nivel\n( 5 ) Checar se arvore esta balanceada ou nao\n( 6 ) Mostrar estatistica da arvore\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            /* Inserção de NÓS na árvore */
            break;
        case 2:
            /* Remoção de nós na árvore */
            break;
        case 3:
            /* Ver altura da árvore */
            break;
        case 4:
            /* Mostrar os elementos de um nível */
            break;
        case 5:
            /* Checar se árvore está balanceada ou não */
            break;
        case 6:
            /* Mostrar estatística da árvore */
            break;

        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}