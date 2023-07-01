#include <stdio.h>
#include <stdlib.h> //biblioteca que contém o comando "malloc()".

typedef struct no{
    int elemento;
    struct no *proximo;
    struct no *anterior;
}no;

typedef struct controleLista{
   
    no *fim;
    no *inicio;
    int quantidade;
}controleLista;

void inicializar(controleLista *lista);
int inserirInicio(controleLista *lista, int elemento);
int inserirFim(controleLista *lista, int elemento);
int listaVazia(controleLista *lista);
void mostrarLista(controleLista *lista);
void mostrarListaRev(controleLista *lista);

int main()
{
    controleLista *lista;
   
    lista = (controleLista*)malloc(sizeof(no));
    if(lista == NULL){
        return 1;
    }
   
   
    inicializar(lista);
    inserirInicio(lista,10);
    inserirInicio(lista,20);
    inserirInicio(lista,30);
    inserirFim(lista,5);
    mostrarLista(lista);
    printf("\n");
    mostrarListaRev(lista);
}

void inicializar(controleLista *lista){
    lista->quantidade = 0;
    lista->fim = NULL;
    lista->inicio = NULL;
}

int listaVazia(controleLista *lista){
    if(lista->quantidade == 0){
        return 0;
    }
    return 1;
}

int inserirInicio(controleLista *lista, int elemento){
   
    no *novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("erro ao alocar memória...");
        return 1;
    }
    novoNo->elemento = elemento;
    novoNo->anterior = NULL;
   if(listaVazia(lista) == 0){
       
       novoNo->proximo = NULL;
       lista->fim = novoNo;
       lista->inicio = novoNo;
       
       
   }else{
       novoNo->proximo = lista->inicio;
       lista->inicio->anterior = novoNo;
       lista->inicio = novoNo;
   }
    lista->quantidade++;
   
    return 0;
}



int inserirFim(controleLista *lista, int elemento){
   
    no *novoNo = (no*)malloc(sizeof(no));
    if(novoNo == NULL){
        printf("erro ao alocar memória...");
        return 1;
    }
   
    novoNo->elemento = elemento;
   
    novoNo->proximo = NULL;
   
    if(listaVazia(lista) == 0){
       
        novoNo->anterior = NULL;
        lista->fim = novoNo;
        lista->inicio = novoNo;
       
    }else{
       
   
        lista->fim->proximo = novoNo;
        novoNo->anterior = lista->fim;
        lista->fim = novoNo;
    }
    lista->quantidade++;
    return 0;

}
     
void mostrarLista(controleLista *lista){
   
    no *inicioAux = lista->inicio;
   
    while(inicioAux != NULL){
        printf("%i \n",inicioAux->elemento);
        inicioAux = inicioAux->proximo;
    }
   
}

void mostrarListaRev(controleLista *lista){
   
        no *fimAux = lista->fim;
   
    while(fimAux != NULL){
        printf("%i \n",fimAux->elemento);
        fimAux = fimAux->anterior;
    }
}
