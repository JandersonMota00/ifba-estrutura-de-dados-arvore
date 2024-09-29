
#include <stdio.h>
#include <stdlib.h>

int main(){

    typedef struct Node{
        float num;
        struct Node* esquerda;
        struct Node* direita;
    }Node;


    Node* InseriroNo(Node *raiz, int numero){
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

    

    return 0;
}