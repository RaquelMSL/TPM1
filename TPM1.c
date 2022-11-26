#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente_prendario.h"
#include "lista.h"

const char *MARCAS[]={"Ford\0","Fiat\0","Chevrolet\0"};
const char *MODELOS[3][3]={{"Focus\0","RS GT\0","Mustang\0"},{"Focus\0","RS GT\0","Mustang\0"},{"Focus\0","RS GT\0","Mustang\0"}};
const char *TIPODOC[]={"DNI","PAS","CF","CIPE","LC","LE"};

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
    case 3://Inciso4();
        break;
    case 4://Inciso5();
        break;
    case 5:printf("lea la cantidad de garante a modificar");
            //scanf("%d",&n);
            //for(i=0;i<n;i++){
            //printf("lea nro y nrotramite");
            //Inciso6(L,aux_nro,aux_nrotramite);}
        break;
    case 6://Inciso7
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
    printf("Ingrese la opción de la marca a utilizar 1)Ford 2)Fiat 3)Chevrolet\n");
    scanf("%d",&marca);getchar();
}while(marca < 1 || marca > 3);
switch(marca){
    case 1: do{
            printf("Ingrese la opción del modelo 1)Focus RS 2)GT 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }while(modelo <1 || modelo >3);
    case 2: do{
            printf("Ingrese la opción del modelo 1)Focus RS 2) GT 3)Mustang\n");
            scanf("%d",&modelo);getchar();
            }while(modelo <1 || modelo >3);
    case 3:do{
            printf("Ingrese la opción del modelo 1)Camaro SS GT Mustang\n");
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
iniGarante(&gx);
cx=cargarCliente();
if(recIngMensual_C<100000){
gx=cargarGarante();}
vx=cargar_auto();
//solicitamos datos para la prenda
printf("Ingrese el valor del capital entregado \n");
scanf("%f",&cap_entregado);getchar();
interes_m=calcInteres(cap_entregado,recVal_Tasa(vx));
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

prenda buscaNroyTramite(lista lx,long int nroX,long long int nro_TrX,int *flagX)
{
    if(isempty(lx)==1){
        (*flagX)=-1;
        }
    else{
        reset(&lx);
        prenda aux=copy(lx);
        while(Isoos(lx)!=1 && (recNum_doc(recDoc_Cliente(aux))!=nroX || recNum_tramite(recDoc_Cliente(aux))!=nro_TrX))
        {
            forward(&lx);
            aux=copy(lx);
        }
        if(Isoos(lx)==1) {(*flagX)=-1;}
        else{
            return copy(lx);
        }
        }
    }

void Inciso4(lista lx,long int nroX,long long int nro_TrX)
{prenda aux;int flag=1;
    aux=buscaNroyTramite(lx,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
        printf("datos de vehiculo:\n patente:%s valor tasacion:%0.2f marca:%s modelo:%s\n\n",recPat(recAuto(aux)),
               recVal_Tasa(recAuto(aux)),MARCAS[recMac(recAuto(aux))-1],MODELOS[recMac(recAuto(aux))-1][recMod(recAuto(aux))-1]);
        printf("datos de prenda:\n cantidad de cuotas:%d cantidad de cuotas pagadas:%d\n");
        printf("interes mensual:%0.2f capital entregado:%0.2f\n",recInteres(aux),recCap_entregado(aux));
        printf("fecha inicio: %d/%d/%d",recDia(recFech_inicio(aux)),recMes(recFech_inicio(aux)),recAnio(recFech_inicio(aux)));
        printf("fecha fin: %d/%d/%d",recDia(recFech_fin(aux)),recMes(recFech_fin(aux)),recAnio(recFech_fin(aux)));
    }
}

void Inciso5(lista lx)
{
    if(isempty(lx)==1) printf("error");
    else{
        reset(&lx);
        while(Isoos(lx)!=1)
            {
                printf("datos del titular:\n NyAP:%s Tipo de documento:%s numero de documento:&d",
                       recNyApe(rec_Cliente(copy(lx))),
                       TIPODOC[recTipo_doc(recDoc_Cliente(copy(lx)))-1],recNum_doc(recDoc_Cliente(copy(lx))));
                printf("datos de vehiculo:\n patente:%s valor tasacion:%0.2f marca:%s modelo:%s\n\n",recPat(recAuto(copy(lx))),
                       recVal_Tasa(recAuto(copy(lx))),MARCAS[recMac(recAuto(copy(lx)))-1],
                       MODELOS[recMac(recAuto(copy(lx)))-1][recMod(recAuto(copy(lx)))-1]);
                forward(&lx);
            }
    }
}

void Inciso6(lista lx,long int nroX,long long int nro_TrX)
{prenda aux;float ingX;int flag=1;
    aux=buscaNroyTramite(lx,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
        printf("lea nuevo ingreso mensual de garante");
        scanf("%f",&ingX);
        setIngreso_Mensual_Garante(&aux,ingX);
    }

}

void Inciso7(lista lx,long int nroX,long long int nro_TrX){
    prenda aux;int flag=1,m,nx,mesx;
    aux=buscaNroyTramite(lx,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
        m=recCant_cuotas(aux)-recCant_cuotasPagas(aux);
        do{
            printf("lea cantidad de cuotas a adelantar maximo %d",m);
            scanf("%d",&nx);
        }while(nx<0 && nx>m);
        modificar_cuotasPagas(&aux,nx);
        mesx=recMes(recFech_fin(aux))-nx;
        if(mesx<1){
            mesx+=12;
            restAnio(&aux);
        }
        modificaMesFIN(&aux,mesx);
        }
}

void Inciso16(lista lx)
{
    if(isempty(lx)==1) printf("error");
    else{
        reset(&lx);
        while(Isoos(lx)!=1)
            {
                if(recIngMensual_C(copy(lx))<0){
                printf("datos del titular:\n NyAP:%s Tipo de documento:%s numero de documento:&d",
                       recNyApe(rec_Cliente(copy(lx))),
                       TIPODOC[recTipo_doc(recDoc_Cliente(copy(lx)))-1],recNum_doc(recDoc_Cliente(copy(lx))));
                printf("datos de vehiculo:\n patente:%s valor tasacion:%0.2f marca:%s modelo:%s\n\n",recPat(recAuto(copy(lx))),
                       recVal_Tasa(recAuto(copy(lx))),MARCAS[recMac(recAuto(copy(lx)))-1],
                       MODELOS[recMac(recAuto(copy(lx)))-1][recMod(recAuto(copy(lx)))-1]);
                forward(&lx);
            }
            }
    }
}

int contarGarantes(lista lx){//!antes de invocar usar isempty y reset
    if(Isoos(lx)==1){
            if(recIngMensual_C(copy(lx))>0) return 1;
            else{return 0;}
            }
    else{
        if(recIngMensual_C(copy(lx))>0){
            forward(&lx);
            return 1+contarGarantes(lx);
        }
        else{
            forward(&lx);
            return 0+contarGarantes(lx);}
    }
}

void Inciso18(lista lx,long int nroX,long long int nro_TrX){
    prenda aux;int flag=1;
    aux=buscaNroyTramite(lx,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
        printf("nro_cliente:%ld monto total:%0.2f",nroX,calcMontoTotal(aux));
    }
}

void Inciso14(lista lx,int *sx){//!antes de invocar usar isempty y reset
    if(Isoos(lx)==1 && vigente(copy(lx))==0)
    (*sx)=calcMontoTotal(copy(lx));
    else{
        if(vigente(copy(lx))==0){
            (*sx)=calcMontoTotal(copy(lx));
            forward(&lx);
            Inciso14(lx,sx);
        }
        else{
            forward(&lx);
            Inciso14(lx,sx);
        }
    }
}
