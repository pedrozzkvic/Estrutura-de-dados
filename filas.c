#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct no{
    int Dado;
    struct no *Proximo;
} No;

No *Inicio = NULL, *Fim = NULL;

void Enfileirar(int Dado){
    No *Novo = (No*)malloc(sizeof(No));
    
    Novo -> Dado = Dado;
    Novo -> Proximo = NULL;

    if (Inicio == NULL){
        Inicio = Fim = Novo;
    }
    else {
        Fim -> Proximo = Novo;
        Fim = Novo;
    }
}

int Desenfileirar(){
    if (Inicio != NULL){
        int Dado = Inicio -> Dado;
        No *Temporario = Inicio;

        if (Inicio == Fim){
            Inicio = Fim = NULL;
        }
        else {
            Inicio = Inicio -> Proximo;
        }
        free(Temporario);

        return Dado;
    }
    else{
        printf("Nao ha oq desenfileirar, a fila esta vazia");
        exit(1);
    }
}

int Tamanho(){
    No *Auxiliar = Inicio;
    int Contador = 0;

    while (Auxiliar != NULL){
        Contador++;
        Auxiliar = Auxiliar -> Proximo;
    }
    return Contador;
}

void Imprimir(){
    No *Auxiliar = Inicio;

    while (Auxiliar != NULL){
        printf("%d, ", Auxiliar -> Dado);
        Auxiliar = Auxiliar -> Proximo;
    }
}

void Apagar(){
    No *Auxiliar = Inicio, *Anterior = NULL;

    while (Auxiliar != NULL){
        Anterior = Auxiliar;
        Auxiliar = Auxiliar -> Proximo;
        free(Anterior);
    }
    Inicio = Fim = NULL;
}

int main(){
    Enfileirar(10);
    Enfileirar(20);
    Enfileirar(30);
    printf("Fila apos enfileirar 10, 20 e 30:\n");
    Imprimir();
    printf("\n");

    printf("Tamanho da fila: %d\n", Tamanho());

    int DadoRemovido = Desenfileirar();
    printf("Elemento desenfileirado: %d\n", DadoRemovido);
    printf("Fila apos desenfileirar:\n");
    Imprimir();
    printf("\n");

    printf("Tamanho da fila agora: %d\n", Tamanho());

    Apagar();
    printf("Fila apagada.\n");

    printf("Tamanho da fila apos apagar: %d\n", Tamanho());

    return 0;
}
