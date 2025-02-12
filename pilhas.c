#include <stdio.h>
#include <stdlib.h>

// =====================Pilha usando Lista sequencial===============================

//#define Max 10

//int Lista[Max], TamanhoAtual = 0;

//void Push(int Dado){
//    if(TamanhoAtual > Max){
//        printf("Lista cheia\n");
//        exit(1);
//    } 

//    TamanhoAtual++;
//    Lista[TamanhoAtual] = Dado
//}

//void Pop(int Dado){
//    if(TamanhoAtual > 0){
//        return Lista[TamanhoAtual];
//        TamanhoAtual-- ;
//    }
//    else{
//        printf("Lista vazia.\n");
//    }    
//}

// Tudo igualzinho uma lista sequencial normal.

//Pilhas usando Listas encadeadas.

typedef struct no{
    int Dado;   
    struct no *Proximo;
}No;

No *Topo = NULL;

void Push(int Dado){
    No *Novo = (No*)malloc(sizeof(No));
    
    Novo -> Dado = Dado;
    Novo -> Proximo = NULL;

    if(Topo == NULL){
        Topo = Novo;
    }
    else{
        Novo -> Proximo = Topo;
        Topo = Novo;
    }
}

int Pop(){
    if(Topo != NULL){
        int Dado = Topo -> Dado;
        No *Temporario = Topo;

        Topo = Topo -> Proximo;
        free(Temporario);

        return Dado;
    }
    return -1;
}

int Tamanho(){
    int Contador = 0;
    No *Vassoura = Topo;

    while(Vassoura != NULL){
        Contador ++;
        Vassoura = Vassoura -> Proximo;   
    }
    return Contador;
}

void Imprimir(){
    No *Printar = Topo;

    while(Printar != NULL){ 
        printf("%d,", Printar -> Dado);
        Printar = Printar -> Proximo;
    }
}

void Apagar(){
    No *Ajuda = Topo, *Anterior;

    while(Ajuda != NULL){
        Anterior = Ajuda;
        Ajuda = Ajuda -> Proximo;
        free(Anterior);
    }
    Topo = NULL;
}

int main() {
    Push(10);
    Push(20);
    Push(30);

    printf("Tamanho: %d\n", Tamanho()); // 3
    Imprimir(); // 30 20 10

    printf("Pop: %d\n", Pop()); // 30
    printf("Tamanho: %d\n", Tamanho()); // 2
    Imprimir(); // 20 10

    printf("Pop: %d\n", Pop()); // 20
    printf("Pop: %d\n", Pop()); // 10
    printf("Pop: %d\n", Pop()); // -1 (pilha vazia)

    printf("Tamanho: %d\n", Tamanho()); // 0

    Apagar(); 
    printf("Tamanho apos Apagar: %d\n", Tamanho()); // 0

    return 0;
}
