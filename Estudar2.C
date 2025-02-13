#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int Dado;
    struct no *Proximo;
}No;

No *Inicio = NULL, *Fim = NULL;

void InserirIni(int Dado){
    No *Novo = (No*)malloc(sizeof(No));

    Novo -> Dado = Dado;
    Novo -> Proximo = Inicio;

    if(Inicio == NULL){
        Inicio = Fim = Novo;
    }
    else{
        Inicio = Novo;
    }
}

void RemoverIni(){
    if(Inicio == NULL){
        printf("Fila vazia\n.");
    }

    No *Auxiliar = Inicio;
    Inicio = Inicio -> Proximo;

    if(Inicio == NULL){
        Fim = NULL;
    }

    free(Auxiliar);
}

void InserirFim(int Dado){
    No *Novo = (No*)malloc(sizeof(No));
    
    Novo -> Dado = Dado;
    Novo -> Proximo = NULL;

    if(Inicio == NULL){
        Inicio = Fim = Novo;
    }
    else{
        Fim -> Proximo = Novo;
        Fim = Novo;
    }
}

void RemoverFim(){
    if(Inicio == NULL){
        printf("Fila vazia.\n");
    }

    No *Auxiliar = Fim, *Anterior = Inicio;

    if(Inicio == Fim){
        Inicio = Fim = NULL;
    }


    while(Anterior -> Proximo != Fim){
        Anterior = Anterior -> Proximo;
    }
    Anterior -> Proximo = NULL;
    free(Auxiliar);
}

int getFront(){
    if(Inicio != NULL){
        int Dado = Inicio -> Dado;
        return Dado;
    }
    else{
        printf("Fila Vazia.\n");
        return -1;
    }
}



int main(){


    return 0;
}