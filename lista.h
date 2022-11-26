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

int isempty (lista L){
return(L.cab ==NULL);}

prenda copy (lista L){
return L.aux->vipd; }

void insert (lista *L, prenda elemento){
nodo *nuevo;
nuevo=(nodo*)malloc(sizeof(nodo));
(*nuevo).vipd=elemento;
if ( (L->cab==NULL)== 1 )
    {
    (*L).cab=nuevo;
    (*nuevo).puntero=(*L).ultimo;
    (*L).ultimo=(*L).cab;
    (*L).aux=(*L).cab; }
else {
        (*L).aux=nuevo;
        (*nuevo).puntero=(*L).ultimo;
        (*L).ultimo=nuevo;
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

void supress (lista *L){}

int Isoos(lista L){
 return (L.ultimo==NULL);
}
#endif // LISTA_H_INCLUDED
