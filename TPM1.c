#include <stdio.h><
#include <stdlib.h>
#include <string.h>
#include <cliente_prendario.h>
#include <lista.h>


void cargar_clientes(prenda p,lista *L, ? )


int main()
{



    return 0;
}

void cargar_clientes(prenda p,lista *L, ? )
{
int tipo_doc, cant_cuotas,cant_cuptas_pagas,modelo,marca,dia_ini,mes_ini,anio_ini,cant,numero;
float interes_m,ingreso_m, ingreso_m_gar,valor_tasacion,cap_entregado;
char patente [35],nyap [35];
fecha ini,fin;
long int cuit;
long long int n_tramite;
printf("\n Inserte el numero de la opción que indique su tipo de documento \n 1)Libreta Civica \n 2) Libreta de Enrolamiento \n 3)DNI \n 4)Cedula (dni extranjero) \n ");
scanf("%d",&tipo_doc);getchar();
while(tipo_doc < 1 || tipo_doc > 4){
    printf(" \n Ha ingresado un numero erróneo. Inserte el numero de la opción que indique su tipo de documento \n 1)Libreta Civica \n 2) Libreta de Enrolamiento \n 3)DNI \n 4)Cedula (dni extranjero) \n  ");
    scanf("%d",&tipo_doc);getchar();
}
printf("Ingrese el numero de tramite del documento \n");
scanf("%lld",&n_tramite);getchar();
printf("Ingrese el numero del documento \n");
scanf("%d",&numero); getchar();
printf("Ingrese el nombre del cliente \n");
gets(nyap);
printf("Ingrese el monto del ingreso mensual del cliente \n");
scanf("%f",&ingreso_m);getchar();
printf("Ingrese el cuit del cliente \n");
scanf("%ld",&cuit);getchar();
//asignamos los datos a una estructura auxiliar del tipo cliente para reutilizar las variables
p.c.doc.doc=tipo_doc;
p.c.doc.doc.nro_doc=numero;
p.c.doc.doc.num_tramite=n_tramite;
strcpy(p.c.NyAp,nyap);
p.c.ing_Men=ingreso_m;
//fin de la asignacion a cliente
printf("Ingrese el  ingreso mensual del garante \n");
scanf("%f",&ingreso_m_gar);getchar();
printf("Ingrese el numero de tramite del documento del garante \n");
scanf("%lld",&n_tramite);getchar();
printf("\n Inserte el numero de la opción que indique el tipo de documento del garante \n 1)Libreta Civica \n 2) Libreta de Enrolamiento \n 3)DNI \n 4)Cedula (dni extranjero) \n ");
scanf("%d",&tipo_doc);getchar();
while(tipo_doc < 1 || tipo_doc > 4){
    printf(" \n Ha ingresado un numero erróneo. Inserte el numero de la opción que indique su tipo de documento \n 1)Libreta Civica \n 2) Libreta de Enrolamiento \n 3)DNI \n 4)Cedula (dni extranjero) \n  ");
    scanf("%d",&tipo_doc);getchar();
}
printf("Ingrese el numero del documento del garante");
scanf("%d",&numero); getchar();
//Asignamos datos a un garante auxiliar
p.g.ing_M_garante=ingreso_m_gar;
p.g.doc_garante.doc=tipo_doc;
p.g.doc_garante.nro_doc=numero;
p.g.doc_garante.num_tramite=n_tramite;
//fin de la asginacion a garante
printf("Ingrese la patente del vehiculo\n");
gets(patente);
printf("Ingrese la opción de la marca a utilizar \n 1)Ford \n 2)Fiat \n 3)Chevrolet\n");
scanf("%d",&marca);getchar();
while(marca < 1 || marca > 3){
    printf("Error. Ingrese la opción de la marca a utilizar \n 1)Ford \n 2)Fiat \n 3)Chevrolet\n");
    scanf("%d",&marca);getchar();

}
switch(marca){
    case 1: printf("Ingrese la opción del modelo \n 1)Focus RS \n 2)GT \n 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            while(modelo <1 || modelo >3){
                printf("Error. Ingrese la opción del modelo \n 1)Focus RS \n 2)GT \n 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }
    case 2: printf("Ingrese la opción del modelo \n 1)Uno \n 2)Punto Evo Sport \n 3) Brava \n");
             scanf("%d",&modelo);getchar();
            while(modelo <1 || modelo >3){
                printf("Error. Ingrese la opción del modelo \n 1)Focus RS \n 2) GT \n 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }
    default:printf("Ingrese la opción del modelo \n 1)Camaro SS \n 2)Corvette Z06 \n 3)Brava \n");
             scanf("%d",&modelo);getchar();
            while(modelo <1 || modelo >3){
                printf("Error. Ingrese la opción del modelo \n 1)Camaro SS \n GT \n Mustang\n");
            scanf("%d",&modelo);getchar();
            }

}
printf("Ingrese el valor de tasacion \n");
scanf("%d",&valor_tasacion);getchar();
//asignamos valores a vehiculo auxiliar
strcpy(p.v.pat,patente);
p.v.valor_tasacion=valor_tasacion;
p.v.marca=marca;
p.v.modelo=modelo;
//fin de la asignacion del vehiculo
printf("Ingrese el valor del capital entregado \n");
scanf("%f",&p.capital_entregado);getchar();
printf("Ingrese el interes mensual de la prenda \n");
scanf("%f",&p.interes_mensual);getchar();
printf("Ingrese la cantidad de cuotas \n");
scanf("%d",&p.cantidad_cuotas);getchar();
printf("Ingrese la cantidad de cuotas pagadas \n");
scanf("%d",&p.cantidad_cuotas_pagas);getchar();
printf("Ingrese el dia de inicio \n");
scanf("%d",&p.fecha_ini.dia);getchar();
printf("Ingrese el mes de inicio \n");
scanf("d%",&p.fecha_ini.mes);getchar();
printf("Ingrese el año de inicio \n");
scanf("&d",&p.fecha_ini.anio);getchar();
printf("Ingrese el dia del final de la prenda \n");
scanf("%d",&p.fecha_fin.dia);getchar();
printf("Ingrese el mes del final de la prenda \n");
scanf("%d",&p.fecha_fin.mes);getchar();
printf("Ingrese el año del final de la prenda \n");
scanf("%d",&p.fecha_fin.anio);getchar();
//Fin de la asignacion a Prenda

}
