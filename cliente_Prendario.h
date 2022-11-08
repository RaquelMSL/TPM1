#ifndef CLIENTE_PRENDARIO_H_INCLUDED
#define CLIENTE_PRENDARIO_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}fecha;

typedef struct{
    char pat[20];
    float valor_tasacion;
    char marca[20];
    char modelo[30];
}vehiculo;

typedef struct{
int doc[6];
int nro_doc;
long long num_tramite;

}documento;

typedef struct{
float ing_M_garante;
documento doc_garante[6];
}garante;

typedef struct{
documento doc;
char NyAp[30];
long long cuit;
float ing_Men;
}cliente;

typedef struct{
cliente C;
garante G;
vehiculo V;
float capital_entregado;
float interes_mensual;
int cantidad_cuotas;
int cantidad_cuotas_pagas;
fecha fecha_ini;
fecha fecha_fin;
}prenda;

void IngresarDoc (documento *D,char docx[],int nro_docx,long long num_tramitex ){
    (*D).doc = docx;
    (*D).nro_doc = nro_docx;
    (*D).num_tramite = num_tramitex;
}
void Ingresar_cliente  ( cliente *C, char NyApx, long long Cuit, float ing_Mx,documento docx   ){
    (*C).NyAp = NyApx;
    (*C).cuit = Cuit;
    (*C).ing_Men = ing_Mx;
    (*C).doc = docx;
}

void Ingresar_garante  ( garante *G,float ing_M_garantex, documento doc_garantex[]){
    (*G).ing_M_garante = ing_M_garantex ;
    (*G).doc_garante = doc_garantex;

}

void Ingresar_Vehiculo  ( vehiculo *V, char patx[],float valor_tasacionx, char marcax[],char modelox[] ){
    (*V).part = patx;
    (*V).valor_tasacion = valor_tasacionx;
    (*V).marca = marcax;
    (*V).modelo = modelox;

}

void Ingresar_Fecha  ( fecha *f, int diax, int mesx, int aniox ){
    (*f).dia = diax;
    (*f).mes = mesx;
    (*f).anio = aniox;

}

void Ingresar_Prenda ( prenda *P,float capital_entregadox,float interes_mensualx,int cantidad_cuotasx,int cantidad_cuotas_pagasx, cliente cx, vehiculo vx, fecha fecha_inix, fecha fecha_finx, garante gx ) {
    (*P).capital_entregado = capital_entregadox;
    (*P).intereses_mensual=intereses_mensualx;
    (*P).catidad_cuotas = catidad_cuotasx;
    (*P).cantidad_cuotas_pagas = cantidad_cuotas_pagasx;
    (*P).C = cx;
    (*P).V=  vx;
    (*P).fecha_ini =fecha fecha_inix;
    (*P).fecha_fin = fecha fecha_finx;
    (*P).G = gx;
}

int recMac (vehiculo p){
    return (p.marca);
}
int vehiculo recPat (vehiculo p){
    return (p.pat);
}
float vehiculo recValT (vehiculo p){
    return (p.valor_tasacion);
}
int vehiculo rectMod (vehiculo p){
    return (p.modelo);
}
int prenda recCant_cuotas (prenda p){
    return (p.cantidad_cuotas);
}
int prenda recCant_cuotasPagas (prenda p){
    return (p.cantidad_cuotas_pagas);
}
float prenda recCap_entregado (prenda p){
    return (p.capital_entregado);
}
float  prenda recInteres (prenda p){
    return (p.interes_mensual);
}
fecha   recFech_inicio (prenda p){
    return (p.fecha_ini);
}
fecha recFech_fin (prenda p){
    return (p.fecha_fin);
}
char* recNyApe (cliente p){
    return (p.NyAp);
}
int recCuil (cliente p){
    return (p.cuit);
}
float ingMensual_cliente (cliente p){
    return (p.ing_Men);
}
int recTipo_doc (documento p){
    return (p.doc);
}
int recNum_doc (documento p){
    return (p.nro_doc);
}
int recNum_tramite (documento p){
    return (p.num_tramite);
}
#endif // CLIENTE_PRENDARIO_H_INCLUDED
