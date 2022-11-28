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
return L.ultimo->vipd; }

void insert(lista *L, prenda elemento){
nodo *nuevo;
nuevo=(nodo*)malloc(sizeof(nodo));
nuevo->vipd=elemento;
if ( (L->cab==NULL)== 1 )
    {
    L->cab=nuevo;
    nuevo->puntero=(*L).ultimo;
    L->ultimo=L->cab;
    L->aux=L->cab;
    }
else {
        L->cab=nuevo;
        nuevo->puntero=L->aux;
        L->aux=nuevo;
}

}

void reset (lista *L){
L->ultimo=L->cab;
L->aux=L->cab;
}

void forward (lista *L){
L->aux=L->ultimo;
L->ultimo=L->ultimo->puntero;
}

void setVipd(lista *l,prenda p){
    l->ultimo->vipd=p;
}

void supress (lista *L){}

int Isoos(lista L){
 return (L.ultimo==NULL);
}

void ordenaMenorFechaFin(lista *l) //l recibe una lista auxiliar con solo prendas vigentes
{prenda *pre;l->aux=l->cab;int x1,x2;

while(l->aux->puntero!=NULL)
{
l->ultimo=l->aux->puntero;
while(l->ultimo->puntero!=NULL)
{
x1=(l->aux->vipd.cantidad_cuotas - l->aux->vipd.cantidad_cuotas_pagas);
x2=(l->ultimo->vipd.cantidad_cuotas - l->ultimo->vipd.cantidad_cuotas_pagas);
if(x1 > x2){
(*pre)=l->ultimo->vipd;
l->ultimo->vipd=l->aux->vipd;
l->aux->vipd=(*pre);
}
l->ultimo=l->ultimo->puntero;
}
l->aux=l->aux->puntero;
}
}

#endif // LISTA_H_INCLUDED
 
