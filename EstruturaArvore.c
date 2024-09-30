#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Estrutura da árvore */
typedef struct Node
{
    float num;
    struct Node *esquerda;
    struct Node *direita;
} Node;

/* Função para criar um novo nó */
Node *criarNo(float numeroCriar)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->num = numeroCriar;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/* Função para inserir um nó na árvore */
Node *inseriroNoNaArvore(Node *raiz, float numero)
{
    if (raiz == NULL)
    {
        return criarNo(numero);
    }

    if (numero < raiz->num)
    {
        raiz->esquerda = inseriroNoNaArvore(raiz->esquerda, numero);
    }
    else if (numero > raiz->num)
    {
        raiz->direita = inseriroNoNaArvore(raiz->direita, numero);
    }

    return raiz;
}

/* Função para remover um nó da árvore */
Node *removerNo(Node *raiz, float removeNumero)
{
    if (raiz == NULL)
        return raiz;
    else if (removeNumero < raiz->num)
        raiz->esquerda = removerNo(raiz->esquerda, removeNumero);
    else if (removeNumero > raiz->num)
        raiz->direita = removerNo(raiz->direita, removeNumero);
    else
    {
        if (raiz->esquerda == NULL)
        {
            Node *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            Node *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Node *temp = raiz->direita;
        while (temp && temp->esquerda != NULL)
        {
            temp = temp->esquerda;
        }
        raiz->num = temp->num;
        raiz->direita = removerNo(raiz->direita, temp->num);
    }

    return raiz;
}

/* Função para calcular a altura da árvore */
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

/* Função para contar o número de nós */
int contarNos(Node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

/* Função para verificar se a árvore está balanceada */
int verificarBalanceada(Node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int alturaEsquerda = verificarBalanceada(raiz->esquerda);
    if (alturaEsquerda == -1)
        return -1;

    int alturaDireita = verificarBalanceada(raiz->direita);
    if (alturaDireita == -1)
        return -1;

    if (abs(alturaEsquerda - alturaDireita) > 1)
        return -1;

    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

bool estaBalanceada(Node *raiz)
{
    return verificarBalanceada(raiz) != -1;
}

/* Função para mostrar as estatísticas da árvore */
void mostrarEstatisticas(Node *raiz)
{
    int totalNos = contarNos(raiz);
    int alturaArvore = altura(raiz);
    bool balanceada = estaBalanceada(raiz);

    printf("=== Estatísticas da Árvore ===\n");
    printf("Número total de nós: %d\n", totalNos);
    printf("Altura da árvore: %d\n", alturaArvore);
    printf("Árvore está balanceada: %s\n", balanceada ? "Sim" : "Não");
    printf("===============================\n");
}

/* Função para pausar a execução e aguardar o usuário pressionar Enter */
void aguardar()
{
    printf("Pressione Enter para continuar...\n");
    getchar(); // Espera um Enter
    getchar(); // Garante que captura o "Enter" após a leitura anterior
}

/* Função para mostrar os elementos de um nível específico */
void mostrarNivel(Node *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }
    if (nivel == 1)
    {
        printf("%f ", raiz->num); // Imprime o número do nó
    }
    else if (nivel > 1)
    {
        mostrarNivel(raiz->esquerda, nivel - 1); // Desce à esquerda
        mostrarNivel(raiz->direita, nivel - 1);  // Desce à direita
    }
}

/* Função para mostrar os elementos de um nível dado */
void mostrarElementosNivel(Node *raiz, int nivel)
{
    if (nivel > altura(raiz))
    {
        printf("Nível inválido!\n");
    }
    else
    {
        printf("Elementos no nível %d: ", nivel);
        mostrarNivel(raiz, nivel); // Chama a função recursiva que imprime os nós do nível
        printf("\n");
    }
}

int main()
{
    int opcao;
    Node *raiz = NULL;

    do
    {
        printf("( 0 ) Sair\n( 1 ) Insercao de NOS na arvore\n( 2 ) Remocao de NOS na arvore\n( 3 ) Ver altura da arvore\n( 4 ) Mostrar os elementos de um nivel\n( 5 ) Checar se arvore esta balanceada ou nao\n( 6 ) Mostrar estatistica da arvore\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            float numero;
            printf("Digite o número para inserir: ");
            scanf("%f", &numero);
            raiz = inseriroNoNaArvore(raiz, numero);
            printf("Número inserido!\n");
            aguardar(); // Pausar após inserir
            break;
        }
        case 2:
        {
            float no;
            printf("Digite o NO que deseja remover: ");
            scanf("%f", &no);
            raiz = removerNo(raiz, no);
            printf("Número removido!\n");
            aguardar(); // Pausar após remover
            break;
        }
        case 3:
            printf("Altura da árvore: %d\n", altura(raiz));
            aguardar(); // Pausar após mostrar altura
            break;
        case 4:
        {
            int nivel;
            printf("Digite o nível que deseja exibir: ");
            scanf("%d", &nivel);
            mostrarElementosNivel(raiz, nivel); // Mostra os elementos no nível
            aguardar();                         // Pausar após mostrar nível
            break;
        }
        case 5:
            printf("Árvore está balanceada: %s\n", estaBalanceada(raiz) ? "Sim" : "Não");
            aguardar(); // Pausar após checar balanceamento
            break;
        case 6:
            mostrarEstatisticas(raiz);
            aguardar(); // Pausar após mostrar estatísticas
            break;
        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
            aguardar(); // Pausar após opção inválida
            break;
        }

    } while (opcao != 0);

    return 0;
}