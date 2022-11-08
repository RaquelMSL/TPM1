#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct {
prenda vipd;
struct nodo *puntero;
}nodo;


typedef struct {
nodo *cab;
nodo *ultimo;
nodo *aux;
}lista;


void init (lista *L){
(*L).cab=NULL;
(*L).ultimo=NULL;
(*L).aux=NULL;
}

int isemty (lista L){
return(if L.cab ==NULL)}

int copy (lista *L){
return(L.ultimo)}

void insert (lista *L, prenda elemento){
nodo *nuevo;
nuevo=(nodo*)malloc(sizeof(nodo));
nuevo.vipd=elemento;
if ( isemty(L) )// isempty
    {
    (*L).cab=nuevo;
    nuevo.puntero=(*L).ultimo;
    (*L).cursor=(*L).cab;
    (*L).cursor_aux=(*L).cab; }
else {
        (*L).aux=nuevo;
        nuevo.puntero=(*L).ultimo;
        (*L).cursor=nuevo;
}

}

void reset (lista *L){
(*L).ultimo=(*L).cab;
(*L).aux=(*L).cab;
}

void forward (lista *L){
(*L).aux=(*L).ultimo;
(*L).ultimo=(*L).ultimo;
}

void supress (lista *L){

}




#endif // LISTA_H_INCLUDED
