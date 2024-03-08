#include "stdlib.h"
#include "stdio.h"

typedef struct sElemento {
    int valor;
    struct sElemento * prox;
} TElemento;

typedef struct sLista {
    TElemento * inicio;
} TLista ;

TLista * cria_lista(){
    TLista  * novaLista = malloc(sizeof(TLista));
    novaLista -> inicio = NULL;
    return novaLista;
}

int insere_no_fim(TLista *list, int valor){
    TElemento *novo = malloc(sizeof(TElemento));

    novo -> valor = valor;
    novo -> prox = NULL;

    if (list->inicio == NULL) {
        list -> inicio = novo;
        return 0;
    }

    TElemento *aux = list->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;

    return 0;
}

int insere_no_inicio(TLista *list, int valor){
    TElemento *novo = malloc(sizeof (TElemento));

    novo->valor = valor;
    novo->prox = list->inicio;
    list->inicio = novo;

    return 0;
}

int coloca_lista(TLista *list, int valor, int indice){
    if(indice <= 0){
        return insere_no_inicio(list, valor);
    }

    TElemento *aux = malloc(sizeof (TElemento));
    int cont = 0;

    aux = list->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
        if(indice == cont){
            TElemento *novo = malloc(sizeof (TElemento));
            novo->valor = valor;
            novo->prox = aux->prox;
            aux->prox=novo;
        }
    }

    return insere_no_fim(list, valor);
}

int remover(TLista *list, int indice){
    int retorno = 0;

    if(indice <= 0){
        retorno = list->inicio->valor;
        list->inicio = list->inicio->prox;
        return retorno; 
    }

    TElemento *anterior = malloc(sizeof (TElemento)); 
    TElemento *proximo = malloc(sizeof (TElemento)); 
    proximo = list->inicio;
    anterior = list->inicio;
    int cont = 0; 
    while(proximo->prox != NULL){
        proximo = proximo->prox;
        cont++;
        if(indice == cont){
            anterior->prox = proximo->prox;
            retorno = proximo->valor;
            proximo->valor = 0;
            proximo->prox = NULL;
            return retorno;
        }
        anterior = proximo;
    }

    retorno = proximo->valor;
    proximo->valor = 0;
    return retorno;
}


int main () {
    TLista *list;
    int retorno; 

    list = cria_lista();

    retorno = insere_no_fim(list, 10);
    retorno = insere_no_fim(list, 4);
    retorno = insere_no_fim(list, 9);
    retorno = insere_no_fim(list, 7);

    retorno = remover(list, 0);

    printf("Retorno %d", retorno);

    retorno = remover(list, 0);
    printf("Retorno %d", retorno);


    return 0;
}