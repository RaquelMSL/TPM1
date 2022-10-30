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
float capital_entregado;
float interes_mensual;
int cantidad_cuotas;
int cantidad_cuotas_pagas;
fecha fecha_ini;
fecha fecha_fin;
}prenda;

typedef struct{
char doc[6];
int nro_doc;
char NyAp[30];
int cuit;
float ing_M;
float ing_M_garante;
char doc_garante[6];
int nro_doc_garante;
}clientePrendario;






#endif // CLIENTE_PRENDARIO_H_INCLUDED
