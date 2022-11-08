#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct {
prenda vipd;
struct nodo *puntero;
}nodo;


typedef struct {
nodo *acceso;
nodo *cursor;
nodo *cursor_aux;
}lista;


void init (lista *L){
(*L).acceso=NULL;
(*L).cursor=NULL;
(*L).cursor_aux=NULL;
}

int isemty (lista *L){
return(if L.acceso ==NULL)}

int copy (lista *L){
return(L.cursor)}

void insert (lista *L, prenda elemento){
nodo *nuevo;
nuevo=(nodo*)malloc(sizeof(nodo));
nuevo.vipd=elemento;
if ((*L).acceso==(*L).cursor){
    (*L).acceso=nuevo;
    nuevo.puntero=(*L).cursor;
    (*L).cursor=(*L).acceso;
    (*L).cursor_aux=(*L).acceso }
else {
        (*L).cursor_aux=nuevo;
        nuevo.puntero=(*L).cursor;
        (*L).cursor=nuevo;
}

}

void reset (lista *L){
(*L).cursor=(*L).acceso;
(*L).cursor_aux=(*L).acceso;
}

void forward (lista *L){
(*L).cursor_aux=(*L).cursor;
(*L).cursor=(*L).cursor;
}

void supress (lista *L){

}







#endif // LISTA_H_INCLUDED
