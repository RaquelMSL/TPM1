#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente_prendario.h"
#include "lista.h"

vehiculo cargar_auto();
garante cargarGarante();
cliente cargarCliente();
void cargar_prenda(lista *L);
void cargar_Clientes(lista *L);
//int buscar_por_doc (prenda *p,lista *L,n_tramite,numero,?);


int main()
{ lista *L;
 init(&L);
int op;

 do{
    printf("1:Leer un cliente_prendario 2:Leer N clientes_prendrios 3:Buscar vehiculos y prendas de un cliente\n");
    printf("4:Mostrar todas las prendas 5:Modificar datos garantes  6:Modificar cuotas pagadas\n");

    printf("seleccione una opcion:");
    scanf("%d",&op);
    switch(op)
    {
    case 1:cargar_prenda(&L);
        break;
    case 2:cargar_Clientes(&L);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }

 }while(op!=5);




    return 0;
}

vehiculo cargar_auto()
{
    int modelo,marca;
float valor_tasacion;
char patente [35];
vehiculo vx;

    printf("Ingrese la patente del vehiculo\n");
gets(patente);
do{
    printf("Ingrese la opción de la marca a utilizar \n 1)Ford \n 2)Fiat \n 3)Chevrolet\n");
    scanf("%d",&marca);getchar();
}while(marca < 1 || marca > 3);
switch(marca){
    case 1: do{
            printf("Ingrese la opción del modelo \n 1)Focus RS \n 2)GT \n 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }while(modelo <1 || modelo >3);
    case 2: do{
            printf("Ingrese la opción del modelo \n 1)Focus RS \n 2) GT \n 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }while(modelo <1 || modelo >3);
    case 3:do{
            printf("Ingrese la opción del modelo \n 1)Camaro SS \n GT \n Mustang\n");
            scanf("%d",&modelo);getchar();
            }while(modelo <1 || modelo >3);

}
printf("Ingrese el valor de tasacion \n");
scanf("%d",&valor_tasacion);getchar();
Ingresar_Vehiculo(&vx,patente,valor_tasacion,marca,modelo);
return vx;
}

garante cargarGarante()
{
int tipo_doc;
float ingreso_m;
long int numero;
long long int n_tramite;
garante gx;

do{
    printf("\nInserte el numero de la opción que indique su tipo de documento  1)Libreta Civica  2) Libreta de Enrolamiento  3)DNI  4)Cedula (dni extranjero) \n  ");
    scanf("%d",&tipo_doc);getchar();
}while(tipo_doc < 1 || tipo_doc > 4);
printf("Ingrese el numero de tramite del documento \n");
scanf("%lld",&n_tramite);getchar();
printf("Ingrese el numero del documento \n");
scanf("%d",&numero); getchar();
printf("Ingrese el monto del ingreso mensual del cliente \n");
scanf("%f",&ingreso_m);getchar();
Ingresar_garante(&gx,ingreso_m,tipo_doc,numero,n_tramite);
return gx;
}

cliente cargarCliente()
{
int tipo_doc;
float ingreso_m;
char nyap [35];
long int numero;
long long int n_tramite,cuit;
cliente cx;

do{
    printf("\nInserte el numero de la opción que indique su tipo de documento  1)Libreta Civica  2) Libreta de Enrolamiento  3)DNI  4)Cedula (dni extranjero) \n  ");
    scanf("%d",&tipo_doc);getchar();
}while(tipo_doc < 1 || tipo_doc > 4);
printf("Ingrese el numero de tramite del documento \n");
scanf("%lld",&n_tramite);getchar();
printf("Ingrese el numero del documento \n");
scanf("%d",&numero); getchar();
printf("Ingrese el nombre del cliente \n");
gets(nyap);
printf("Ingrese el monto del ingreso mensual del cliente \n");
scanf("%f",&ingreso_m);getchar();
printf("Ingrese el cuit del cliente \n");
scanf("%lld",&cuit);getchar();
Ingresar_cliente(&cx,nyap,cuit,ingreso_m,tipo_doc,numero,n_tramite);
return cx;
}

void cargar_prenda(lista *L)
{
int cant_cuotas,cant_cuotas_pagas,diax,mesx,aniox;
float interes_m,cap_entregado;
fecha ini,fin;
cliente cx;
vehiculo vx;
garante gx;
prenda px;

cx=cargarCliente();

gx=cargarGarante();

vx=cargar_auto();
//solicitamos datos para la prenda
printf("Ingrese el valor del capital entregado \n");
scanf("%f",&cap_entregado);getchar();
printf("Ingrese el interes mensual de la prenda \n");
scanf("%f",&interes_m);getchar();
printf("Ingrese la cantidad de cuotas \n");
scanf("%d",&cant_cuotas);getchar();
printf("Ingrese el dia de inicio \n");
scanf("%d",&diax);getchar();
printf("Ingrese el mes de inicio \n");
scanf("d%",&mesx);getchar();
printf("Ingrese el año de inicio \n");
scanf("&d",&aniox);getchar();
Ingresar_Fecha(&ini,diax,mesx,aniox);
mesx+=cant_cuotas;
do{
mesx-=12;
aniox+=1;
}while(mesx>12);
Ingresar_Fecha(&fin,diax,mesx,aniox);
if(aniox<2022)
{
cant_cuotas_pagas=cant_cuotas;
}
else
	{
	aniox=2022-recAnio(ini);
	mesx=11-recMes(ini);
	cant_cuotas_pagas=(aniox*12)+mesx;
	}
//Terminamos de solicitar datos para la prenda y llamamos la funcion de cliente_prendario.h
Ingresar_Prenda(&px,cap_entregado,cant_cuotas,cant_cuotas_pagas,cx,vx,ini,fin,gx);
//insertamos un nuevo nodo en la lista
insert(&L,px);
}

void cargar_Clientes(lista *lx)
{int n,i;
    do{
        printf("lea la cantidad de cliente_prenda a ingresar");
        scanf("%d",&n);
    }while(n<0);
    for(i=0;i<n;i++)
        cargar_prenda(&lx);
}

prenda buscaNroyTramite()

/*
void mostrar_vehiculo_y_prenda(prenda *p,lista *L,int marca,int modelo,?){
    int r;
    char mar_x[35],mod_x[35];
    switch (marca){
        case 1: strcpy(mar_x,"Ford");
        case 2: strcpy(mar_x,"Fiat");
     Default: strcpy(mar_x,"Chevrolet");
   if(marca==1){
     switch(modelo){
        case 1: strcpy(mod_x,"Focus RS");
        case 2: strcpy(mod_x,"GT");
        default: strcpy(mod_x,"Mustang");}
      else (marca==2){
          switch(modelo)
    reset(*L)
    r=search(*L,n_tramite,numero);
    if(r>0){
       printf("El nombre del cliente es %s \n el numero de documento del cliente es %ld \n el tipo de documento es %s \n el numero de tramite del cliente es %lld",p.C.NyAp,p.C.doc.nro_doc);
*/
