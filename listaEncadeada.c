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
            proximo = NULL;
            return retorno;
        }
        anterior = proximo;
    }

    retorno = proximo->valor;
    proximo = NULL;
    return retorno;
}

int tamanho(TLista *list){
    int tamanho = 0;

    if(list->inicio == NULL){
        return -1;
    }

    TElemento *aux = malloc(sizeof (TElemento));
    aux = list->inicio;
    tamanho++;

    while(aux->prox != NULL){
        aux = aux->prox;
        tamanho++;
    }

    return tamanho;
}

void destruir(TLista *list){

    TElemento *aux = malloc(sizeof (TElemento)); 
    TElemento *proximo = malloc(sizeof (TElemento)); 
    aux = list->inicio;
    while(aux->prox != NULL){
        proximo = aux->prox;
        aux = NULL;
        aux = proximo;
    }

    list->inicio = NULL;    
}

int busca_posicao(TLista *list, int indice){

    if(indice <= 0){
        return list->inicio->valor;
    }

    TElemento *aux = malloc(sizeof (TElemento));
    int cont = 0;

    aux = list->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
        if(indice == cont){
            return aux->valor;
        }
    }

    return aux->valor;
}

int busca_valor(TLista *list, int valor){

    if(list->inicio->valor == valor){
        return 0; 
    }

    TElemento *aux = malloc(sizeof (TElemento));
    int cont = 0;

    aux = list->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
        if(aux->valor == valor){
            return cont;
        }
    }

    return -1;
}

int main () {
    TLista *list;
    int retorno; 

    list = cria_lista();

    retorno = insere_no_fim(list, 10);
    retorno = insere_no_fim(list, 4);
    retorno = insere_no_fim(list, 9);
    retorno = insere_no_fim(list, 7);

    //Busca valor
    retorno = busca_valor(list, 445);
    if(retorno < 0){
        printf("Nao encontrou\n");
    }else{
        printf("Retorno %d\n", retorno);
    }

    retorno = busca_valor(list, 4);
    if(retorno < 0){
        printf("Nao encontrou\n");
    }else{
        printf("Retorno %d\n", retorno);
    }

    //Busca posicao
    retorno = busca_posicao(list, 2);
    printf("Retorno %d\n", retorno);

    //Tamanho
    retorno = tamanho(list);
    if(retorno < 0){
        printf("Lista nao existe\n");
    }else{
        printf("Tamanho %d\n", retorno);
    }

    //Remover
    retorno = remover(list, 2);
    printf("Removido %d\n", retorno);

    //Tamanho
    retorno = tamanho(list);
    if(retorno < 0){
        printf("Lista nao existe\n");
    }else{
        printf("Tamanho %d\n", retorno);
    }

    //Destruido
    destruir(list);

    //Tamanho
    retorno = tamanho(list);
    if(retorno < 0){
        printf("Lista nao existe\n");
    }else{
        printf("Tamanho %d\n", retorno);
    }

    return 0;
}