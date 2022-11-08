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
char doc[6];
int nro_doc;

}documento;

typedef struct{
float ing_M_garante;
documento doc_garante[6];
}garante;

typedef struct{
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

void Ingresar_cliente  ( cliente *C, char NyApx, long long Cuit, float ing_Mx   ){
    (*C).NyAp = NyApx;
    (*C).cuit = Cuit;
    (*C).ing_Men = ing_Mx;
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
#endif // CLIENTE_PRENDARIO_H_INCLUDED
