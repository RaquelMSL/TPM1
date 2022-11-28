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
    int marca;
    int modelo;
}vehiculo;

typedef struct{
int doc;
long int nro_doc;
long long num_tramite;

}documento;

typedef struct{
float ing_M_garante;
documento doc_garante;
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

void IngresarDoc (documento *D,int docx,int nro_docx,long long num_tramitex ){
    (*D).doc = docx;
    (*D).nro_doc = nro_docx;
    (*D).num_tramite = num_tramitex;
}
void Ingresar_cliente  ( cliente *C, char *NyApx, long long Cuit, float ing_Mx,int docx,int nro_docx,long long num_tramitex   ){
    strcpy((*C).NyAp,NyApx);
    (*C).cuit = Cuit;
    (*C).ing_Men = ing_Mx;
    IngresarDoc(&C->doc,docx,nro_docx,num_tramitex );
}
void Ingresar_garante  ( garante *G,float ing_M_garantex, int docx,int nro_docx,long long num_tramitex){
    (*G).ing_M_garante = ing_M_garantex ;
    IngresarDoc(&G->doc_garante,docx,nro_docx,num_tramitex);
}
void Ingresar_Vehiculo  ( vehiculo *V, char patx[],float valor_tasacionx, int marcax,int modelox){
    strcpy((*V).pat,patx);
    //(*V).pat = patx;
    (*V).valor_tasacion = valor_tasacionx;
    (*V).marca = marcax;
    (*V).modelo = modelox;
}
void Ingresar_Fecha  ( fecha *f, int diax, int mesx, int aniox ){
    (*f).dia = diax;
    (*f).mes = mesx;
    (*f).anio = aniox;
}
float calcInteres(float capiE,float vTotal){
float porcentaje=(100*capiE)/vTotal;
if(porcentaje>=0.3)
{
  return 9.5;
}
else{
    if(porcentaje>=0.2){
        return 12.3;
    }
    else{
        if(porcentaje>=0.1){
            return 21.8;
        }
        else{ return 50;}
    }
}
}
prenda Ingresar_Prenda ( float capital_entregadox,int cantidad_cuotasx,int cantidad_cuotas_pagasx, cliente cx, vehiculo vx, fecha fecha_inix, fecha fecha_finx, garante gx ) {
    prenda p;
    p.capital_entregado = capital_entregadox;
    p.interes_mensual=calcInteres(capital_entregadox,vx.valor_tasacion);
    p.cantidad_cuotas = cantidad_cuotasx;
    p.cantidad_cuotas_pagas = cantidad_cuotas_pagasx;
    p.C=cx;
    p.V=vx;
    p.fecha_ini= fecha_inix;
    p.fecha_fin= fecha_finx;
    p.G=gx;
    return p;
}


int recModelo(prenda p){
    return p.V.modelo;
}
cliente rec_cliente(prenda p){
    return p.C;
    }
garante rec_garante(prenda p){
    return p.G;
}
int vigente(prenda p){
    return (p.cantidad_cuotas-p.cantidad_cuotas_pagas);
}
float calcMontoTotal(prenda p){
    float apagar=(p.V.valor_tasacion-p.capital_entregado),montoMensual;
    montoMensual=(apagar/p.cantidad_cuotas)*p.interes_mensual/100;
    return (montoMensual*p.cantidad_cuotas)+p.capital_entregado;
}

void iniGarante(garante *g){
    (*g).ing_M_garante=-1;
}
float recIngMensual_G(prenda p){
    return p.G.ing_M_garante;
}
float recIngMensual_C(prenda p){
    return p.C.ing_Men;
}
vehiculo recAuto(prenda p){
    return p.V;
}
void modificaMac(prenda *p,int nx){
    (*p).V.marca=nx;
}
int recMac (vehiculo p){
    return (p.marca);
}
char* recPat (vehiculo p){
    return (p.pat);
}
float recVal_Tasa (vehiculo p){
    return (p.valor_tasacion);
}
int recMod (vehiculo p){
    return (p.modelo);
}

void modificar_cuotasPagas(prenda *p,int n){
(*p).cantidad_cuotas_pagas+=n;
}
int recCant_cuotas (prenda p){
    return (p.cantidad_cuotas);
}
int recCant_cuotasPagas (prenda p){
    return (p.cantidad_cuotas_pagas);
}
float recCap_entregado (prenda p){
    return (p.capital_entregado);
}
float recInteres (prenda p){
    return (p.interes_mensual);
}

void modificaMesFIN(prenda *p,int mesx){
(*p).fecha_fin.mes=mesx;
}
void restAnio(prenda *p){
(*p).fecha_fin.anio--;
}
fecha   recFech_inicio (prenda p){
    return (p.fecha_ini);
}
int recDia(fecha f){
return f.dia;
}
int recMes(fecha f){
return f.mes;
}
int recAnio(fecha f){
return f.anio;
}
fecha recFech_fin (prenda p){
    return (p.fecha_fin);
}
cliente rec_Cliente(prenda p){
 return p.C;
}
char* recNyApe (cliente p){
    return (p.NyAp);
}
long long  recCuil (cliente p){
    return (p.cuit);
}
float ingMensual_cliente (cliente p){
    return (p.ing_Men);
}

documento recDoc_Cliente(prenda p){
return p.C.doc;
}

documento recDoc_Garante(prenda p){
return p.G.doc_garante;
}
documento recDoc_Garante2(prenda *p){
return p->G.doc_garante;
}

int recTipo_doc (documento p){
    return (p.doc);
}
long int recNum_doc (documento p){
    return (p.nro_doc);
}
long long recNum_tramite (documento p){
    return (p.num_tramite);
}
#endif // CLIENTE_PRENDARIO_H_INCLUDED
