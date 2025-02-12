#include <stdio.h>
#include <stdlib.h>
#define Max 10

int Lista[Max];
int TamanhoAtual = 0;

void Inserir(int Elemento);
int Buscar(int Elemento);
void Remover(int Elemento);
void ImprimirLista();
void InserirIni();

void InserirIni(int Elemento){
    if(TamanhoAtual >= Max){
        printf("Nao eh possivel inserir o elemento pois a lista esta cheia");
        exit(1);
    }
    for(int i = 0; i < TamanhoAtual; i++){
        Lista[i] = Lista[i++];
    }
    Lista[0] = Elemento;
    TamanhoAtual++;
}

void Inserir(int Elemento){
    if(TamanhoAtual >= Max){
        printf("Lista cheia\n.");
        exit(1);
    }

    Lista[TamanhoAtual++] = Elemento;
}


//Busco o elemento e
int Buscar(int Elemento){
    for(int n = 0; n < Max; n++){
        if(Elemento == Lista[n]){
            printf("\nElemento %d encontrado na posição %d.\n", Elemento, n);
            return n;
        }               	
    }
    printf("Elemento nao encontrado./n");
    return -1;
}

void Remover(int Elemento){
    int Posicao = Buscar(Elemento);
    if(Posicao == -1){
        printf("Esse elemento nao existe na lista.\n");
        return;
    }

    Lista[Posicao] = Lista[TamanhoAtual - 1];
    TamanhoAtual--;
    printf("Elemento removido com sucesso.\n");
}

void ImprimirLista(){
    printf("\n[");
    for(int p = 0;p < TamanhoAtual; p++){
        printf("%d,", Lista[p]);
    }
    printf("]\n");
}

int main(){
    Inserir(7);
    Inserir(8);
    Inserir(9);
    Inserir(16);
    Inserir(48);
    InserirIni(10);
    Inserir(100);
    Inserir(200);
    Inserir(30);
    Inserir(45);

    printf("Buscar elemento 15");
    Buscar(15);
    printf("\nBuscar elemento 100\n");
    Buscar(100);
    printf("Buscar elemento 48\n");
    Buscar(48);

    ImprimirLista();
    Remover(100);
    ImprimirLista();


    return 0;
}
