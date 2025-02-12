#include <stdio.h>
#include <stdlib.h>

typedef struct no{   
    int Dado;
    struct no *Proximo;
}No;

No *Inicio = NULL, *Fim = NULL;

void Inserir(int Dado){
    No *Novo = (No*)malloc(sizeof(No));

    Novo -> Dado = Dado;
    Novo -> Proximo =  NULL;

    if(Inicio == NULL){
        Inicio = Fim = Novo;
    }

    else{
        Fim -> Proximo = Novo;
        Fim = Novo;
    }
}

No *Buscar(int Dado){
    No *Pesquisa = Inicio;

    while(Pesquisa != NULL){
        if (Pesquisa -> Dado == Dado){
            return Pesquisa;
        }
        Pesquisa = Pesquisa -> Proximo;
    }
    return NULL;

}

void Remover(int Dado) {
    No *Pesquisa = Inicio, *Anterior = NULL;

    while (Pesquisa != NULL) {
        if (Pesquisa->Dado == Dado) {
            if (Pesquisa == Inicio) {
                Inicio = Inicio->Proximo;
                if (Inicio == NULL) {
                    Fim = NULL;
                }
            } else {
                Anterior->Proximo = Pesquisa->Proximo;
                if (Pesquisa == Fim) {
                    Fim = Anterior;
                }
            }
            free(Pesquisa);
            return;
        }
        Anterior = Pesquisa;
        Pesquisa = Pesquisa->Proximo;
    }
}

int Obter (No *no){
    if(!no){
        printf("Nao existe no");
        exit(1);
    }
    return no -> Dado;
}

int Tamanho(){
    int Contador = 0;
    No *Pesquisa = Inicio;

    while(Pesquisa != NULL){
        Contador ++;
        Pesquisa = Pesquisa -> Proximo;
    }
    return Contador;
}

void Imprimir(){
    No *Pesquisa = Inicio;
    printf("[");

    while(Pesquisa != NULL){
        printf("%d ", Pesquisa -> Dado);
        Pesquisa = Pesquisa -> Proximo;
    }
    printf("]\n");
}

void Apagar(){
    No *Pesquisa = Inicio, *Antecessor = NULL;
    
    while(Pesquisa){
        Antecessor = Pesquisa;
        Pesquisa = Pesquisa -> Proximo;
        free(Antecessor);
    }
    Inicio = Fim = NULL;
}

void InserirOrdenado(int Dado){
    No *Pesquisa = Inicio, *Anterior = NULL;
    No *Novo = (No*)malloc(sizeof(No));

    Novo -> Dado = Dado;
    Novo -> Proximo = NULL;

    while(Pesquisa && Dado > Pesquisa->Dado){
        Anterior = Pesquisa;
        Pesquisa = Pesquisa -> Proximo;
    }
    if(Inicio == NULL){
        Inicio = Fim = Novo;
    }
    else if (Pesquisa == Inicio){
        Novo -> Proximo = Inicio;
        Inicio = Novo;
    }
    else if(Pesquisa == NULL){
        Fim -> Proximo = Novo;
        Fim = Novo;
    }
    else{
        Anterior -> Proximo = Novo;
        Novo -> Proximo = Pesquisa;
    }
}
int main() {
    InserirOrdenado(10);
    InserirOrdenado(20);
    InserirOrdenado(30);
    InserirOrdenado(40);
    InserirOrdenado(50);
    
    printf("Lista apos insercao:\n");
    Imprimir();

    printf("Tamanho da lista: %d\n", Tamanho());

    No *noBuscado = Buscar(30);
    if (noBuscado != NULL) {
        printf("Valor encontrado: %d\n", Obter(noBuscado));
    } else {
        printf("Valor nao encontrado.\n");
    }

    printf("Removendo o valor 30 da lista...\n");
    Remover(30);
    Imprimir(); 

    
    printf("Tamanho da lista apas remocao: %d\n", Tamanho()); // Esperado: 4

    noBuscado = Buscar(30);
    if (noBuscado != NULL) {
        printf("Valor encontrado: %d\n", Obter(noBuscado));
    } else {
        printf("Valor 30 nao encontrado apas remocao.\n");
    }
    
    printf("Apagando todos os elementos da lista...\n");
    Apagar(10); 
    Imprimir();  

    return 0;
}
