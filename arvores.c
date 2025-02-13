#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int Dado;
    struct no *Esquerda, *Direita;
}No;

No *Raiz = NULL;

No *Inserir( No *no, int Dado){
    if(no == NULL){
        no = (No*)malloc(sizeof(No));
        no -> Dado = Dado;
        no -> Esquerda = no -> Direita = NULL;
    }
    else if(Dado < no -> Dado){
        no -> Esquerda = Inserir(no ->Esquerda, Dado);
    }
    else{
        no -> Direita = Inserir(no -> Direita, Dado);
    }
    return no;
}

No *Remover(No *no, int Dado){
    No *Auxiliar = NULL, *Auxiliar2 = NULL;

    if(no == NULL){
        if(no -> Esquerda == NULL && no -> Direita == NULL){
            free(no);
            return NULL;
        }
    
        else if(!no -> Direita){
            Auxiliar = no -> Esquerda;
            free(no);
            return Auxiliar;
        }
        else{
            Auxiliar = Auxiliar2 = no -> Direita;
            while(Auxiliar -> Esquerda){
                Auxiliar = Auxiliar -> Esquerda;
            }
            Auxiliar -> Esquerda = no -> Esquerda;
            free(no);
            return Auxiliar2;
        }
    }
    else{
        if(no != NULL && Dado < no -> Dado)
            no -> Esquerda = Remover(no -> Esquerda, Dado);

        else
            no -> Direita = Remover(no -> Direita, Dado);
    }
    
    return no;
}
void MostrarFolhas(No *no){
    if(no != NULL){
        if(no -> Esquerda == NULL && no -> Direita == NULL){
            printf("%d ", no -> Dado);
        }

    MostrarFolhas(no -> Esquerda);
    MostrarFolhas(no -> Direita);
    }
}

int GetMax(No *no){
    if(no != NULL){
        while(no -> Direita){
            no = no -> Direita;
        }
            
        return no -> Dado;
    }   
    else{
        printf("A arvore esta vazia./\n");
        return -1;
    }
}

int GetMin(No *no){
    if(no != NULL){
        while(no -> Esquerda){
            no = no -> Esquerda;
        }

        return no -> Dado;
    
    }
    else{
        printf("A arvore esta vazia.\n");
        return -1;
    }
}

int DistanciaDaRaiz(No *no, int Dado){
    int Contador = 0;

    if(no != NULL){
        while(no != NULL){
            if(Dado < no -> Dado){
                Contador++;
                no = no -> Esquerda;
            }
            else if(Dado > no -> Dado){
                Contador++;
                no = no -> Direita;
            }
            else{
                return Contador;
            }
        }
        printf("Nao achei o elemento, mane.\n");
        return -1;

    }
    else{
        printf("A arvore esta vazia.\n");
        return -1;
    }
}

int AlturaArvore(No *no) {
    if (no == NULL) {
        return 0;
    }

    int ContadorEsquerda = AlturaArvore(no->Esquerda);
    int ContadorDireita = AlturaArvore(no->Direita);

    if (ContadorDireita > ContadorEsquerda) {
        return ContadorDireita + 1;
    } else {
        return ContadorEsquerda + 1;
    }
}


int main() {
    // Inserindo elementos na árvore
    Raiz = Inserir(Raiz, 10);  // Raiz: 10
    Raiz = Inserir(Raiz, 5);   // Esquerda de 10: 5
    Raiz = Inserir(Raiz, 15);  // Direita de 10: 15
    Raiz = Inserir(Raiz, 3);   // Esquerda de 5: 3
    Raiz = Inserir(Raiz, 7);   // Direita de 5: 7
    Raiz = Inserir(Raiz, 13);  // Esquerda de 15: 13
    Raiz = Inserir(Raiz, 18);  // Direita de 15: 18

    // Exibindo o valor máximo
    printf("Maximo: %d\n", GetMax(Raiz));  // Saída esperada: 18

    // Exibindo o valor mínimo
    printf("Minimo: %d\n", GetMin(Raiz));  // Saída esperada: 3

    // Exibindo a distância da raiz para o elemento 7
    printf("Distancia da raiz para o elemento 7: %d\n", DistanciaDaRaiz(Raiz, 7));  // Saída esperada: 2

    // Exibindo a altura da árvore
    printf("Altura da arvore: %d\n", AlturaArvore(Raiz));  // Saída esperada: 3 (altura das subárvores mais altas)

    // Mostrando as folhas da árvore
    printf("Mostrando folhas:\n");
    MostrarFolhas(Raiz);  // Saída esperada: 3 7 13 18

    // Removendo o elemento 5 e mostrando novamente as folhas
    Raiz = Remover(Raiz, 5);  // Elemento 5 é removido da árvore
    printf("Raiz apos remover o 5:\n");
    MostrarFolhas(Raiz);  // Saída esperada após remoção: 3 7 13 18 (5 removido)

    return 0;
}

