#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char Nome[100];
    float Nota, Media;
    struct aluno *Proximo;
} Aluno;

Aluno *Inicio = NULL, *Fim = NULL;

void InserirOrdenado(float Media, float Nota, char Nome[10]){
    Aluno *Pesquisa = Inicio, *Anterior = NULL;
    Aluno *Novo = (Aluno*)malloc(sizeof(Aluno));

    Novo -> Media = Media;
    Novo -> Nota = Nota;
    strcpy(Novo -> Nome, Nome);   
    Novo -> Proximo = NULL;

    while(Pesquisa && Media < Pesquisa->Media){
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

void Imprimir(){
    Aluno *Pesquisa = Inicio;

    while(Pesquisa){
        printf("\n\nNome do aluno(a): %s.\n", Pesquisa -> Nome);
        printf("Nota do aluno(a): %.1f.\n", Pesquisa -> Nota);
        printf("Media do aluno(a); %.1f.\n\n", Pesquisa -> Media);
        Pesquisa = Pesquisa -> Proximo;
    }
}
int main() {
    char Nome[100];
    float Nota, Media;

    while(1) {
        printf("Digite o nome do aluno (ou 'sair' para encerrar): ");
        fgets(Nome, sizeof(Nome), stdin);
        Nome[strcspn(Nome, "\n")] = '\0';

        if(strcmp(Nome, "sair") == 0) {
            break;
        }

        printf("Digite a nota do aluno: ");
        scanf("%f", &Nota);

        while(getchar() != '\n');

        printf("Digite a media do aluno: ");
        scanf("%f", &Media);

        while(getchar() != '\n');
        printf("\n");
        InserirOrdenado(Media, Nota, Nome);
    }
    
    printf("\n\n");
    printf("==============================================================");
    printf("\nALUNOS EM RANKING DA MAIOR MEDIA PRA MENOR\n");
      printf("==============================================================");

    Imprimir();

    return 0;
}

