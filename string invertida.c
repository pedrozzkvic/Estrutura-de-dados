#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char Dado;
    struct no *Proximo;
}No;

No *Topo = NULL;

int PilhaVazia(){
    return Topo == NULL;
}

void Empilhar(char Dado){
    No *Novo = (No*)malloc(sizeof(No));

    Novo -> Dado = Dado;
    Novo -> Proximo = NULL;
     
    if(Topo == NULL){
        Topo = Novo;
    }
    else{
        Novo -> Proximo = Topo;
        Topo  = Novo;
    }
}

char Desempilhar(){
    if(Topo == NULL){
        printf("Pilha vazia.\n");
        return  '\0';
    }

    No *Temporario = Topo;
    char String = Topo -> Dado;
    Topo = Topo -> Proximo;

    free(Temporario);
    return String;
}

void InverterString(char* String){
    for(int i = 0; String[i] != '\0'; i++){
        Empilhar(String[i]);
    }

    printf("String invertida: \n");
    while(!PilhaVazia()){
        printf("%c", Desempilhar());
    }
    printf("\n");
}

int main(){
    char str[]  = "Estrutura de Dados";
    InverterString(str);

    return 0;
}