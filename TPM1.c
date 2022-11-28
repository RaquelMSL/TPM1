#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "cliente_prendario.h"
#include "lista.h"

const char *MARCAS[3]={"Ford\0","Fiat\0","MAZDA\0"};
const char *MODELOS[3][3]={{"Focus\0","RS GT\0","Mustang\0"},{"Focus\0","RS GT\0","Mustang\0"},{"Focus\0","RS GT\0","Mustang\0"}};
const char *TIPODOC[6]={"DNI","PAS","CF","CIPE","LC","LE"};

int main()
{ lista L;
 init(&L);
int op,n,i,marcax,modelox;float sumx;
long int nro_docX;
long long int nro_tramiteX;
 do{
    printf("________________________________________________________________________________\n");
    printf(" 1:Leer un cliente_prendario\n 2:Leer N clientes_prendrios\n 3:Buscar vehiculos y prendas de un cliente\n");
    printf(" 4:Mostrar todas las prendas\n 5:Modificar datos garantes\n 6:Modificar cuotas pagadas\n");
    printf(" 7:Modifica marca por MAZDA\n 8:Marca de vehiculo mas vendido\n 9:Listar las 10 personas con prendas vigentes con el menor numero de cuotas\n");
    printf(" 10:Listar prendas de vehiculos para un modelo dado\n 11:Mostrar prendas con el mayor y el menor monto\n");
    printf(" 12:Mostrar todas las prendas activas\n 13:Mostrar la suma de monto total de las prendas vigente\n");
    printf(" 14:Listar clientes sin garantes\n 15:Mostrar cantidad de prendas con garante\n");
    printf(" 16:Mostrar monto total por un cliente\n 17:Guardar\n 18:Precargar\n 19:EXIT\n");
    printf("________________________________________________________________________________\n");

    printf(" seleccione una opcion:");
    scanf("%d",&op);getchar();
    switch(op)
    {
    case 1:system("cls");
        reset(&L);
        cargar_prenda(&L);
        break;
    case 2:
        system("cls");
        reset(&L);
        cargar_Clientes(&L);
        break;
    case 3:system("cls");
           printf("leer numero de documento");
           scanf("%ld",&nro_docX);fflush(stdin);
           printf("leer numero de tramite");
           scanf("%lld",&nro_tramiteX);fflush(stdin);
           Inciso4(L,nro_docX,nro_tramiteX);
           getchar();
        break;
    case 4:
        system("cls");
        Inciso5(L);
        getchar();
        break;
    case 5:system("cls");
            printf("lea la cantidad de garante a modificar");
            scanf("%d",&n);
            for(i=0;i<n;i++){
            printf("leer numero de documento");
            scanf("%ld",&nro_docX);fflush(stdin);
            printf("leer numero de tramite");
            scanf("%lld",&nro_tramiteX);fflush(stdin);
            Inciso6(L,nro_docX,nro_tramiteX);}
            getchar();
        break;
    case 6:system("cls");
           printf("leer numero de documento");
           scanf("%ld",nro_docX);fflush(stdin);
           printf("leer numero de tramite");
           scanf("%lld",nro_tramiteX);fflush(stdin);
           Inciso7(L,nro_docX,nro_tramiteX);
        break;
    case 7:system("cls");
        do{
        printf("\nlea una marca 1:Ford 2:Fiat 3:Chevrolet");
        scanf("%d",&marcax);
        }while(marcax<1 || marcax>3);
        Inciso8(L,marcax,4);
        break;
    case 8:system("cls");
        printf("la Marca mas vendidas es %s",MARCAS[Buscar_Marca_masVendida(L)]);
        break;
    case 9:system("cls");
        Inciso10(L);
        break;
    case 10:system("cls");
        do{
        printf("\nlea un modelo: \n1:Focus 2:RS 3:GT Mustang\n4:Focus 5:RS 6:GT Mustang\n7:Focus 8:RS 9:GT Mustang");
        scanf("%d",&modelox);
        }while(modelox<1 || modelox>9);
        PrendaSegun_Modelo(L,modelox);
        break;
    case 11:system("cls");
        //inciso12
        break;
    case 12:system("cls");
        Inciso13(L);
        break;
    case 13:system("cls");
        if(isempty!=1){
         reset(&L);
         Inciso14(L,&sumx);
         printf("la suma de lo monto total de le las prendas vigente es %0.2f",sumx);
    }
    else{printf("error");}
        break;
    case 14:Inciso16(L);
        break;
    case 15:
        if(isempty!=1){
         reset(&L);
         printf("cantidad de prendas con garante:%d",contarGarantes(L));
         getchar();
    }
    else{printf("error");}
        break;
    case 16:
           printf("leer numero de documento");
           scanf("%ld",nro_docX);
           printf("leer numero de documento");
           scanf("%lld",nro_tramiteX);
           Inciso18(L,nro_docX,nro_tramiteX);
        break;
    case 17:
        break;
    case 18:
    default:printf("error");
    }
system("cls");
 }while(op!=19);



    return 0;
}

vehiculo cargar_auto(){
    int modelo,marca;
float valor_tasacion;
char patente [35];
vehiculo vx;

    printf("Ingrese la patente del vehiculo\n");
gets(patente);
do{
    printf("Ingrese la opcion de la marca a utilizar 1)Ford 2)Fiat 3)Chevrolet\n");
    scanf("%d",&marca);fflush(stdin);
}while(marca < 1 || marca > 3);
switch(marca){
    case 1: do{
            printf("Ingrese la opcion del modelo 1)Focus RS 2)GT 3)Mustang\n");
            scanf("%d",&modelo);fflush(stdin);
            }while(modelo <1 || modelo >3);
            break;
    case 2: do{
            printf("Ingrese la opcion del modelo 1)Focus RS 2) GT 3)Mustang\n");
            scanf("%d",&modelo);fflush(stdin);
            }while(modelo <1 || modelo >3);
            break;
    case 3:do{
            printf("Ingrese la opcion del modelo 1)Camaro SS GT Mustang\n");
            scanf("%d",&modelo);fflush(stdin);
            }while(modelo <1 || modelo >3);
            break;
}
printf("Ingrese el valor de tasacion \n");
scanf("%f",&valor_tasacion);fflush(stdin);
Ingresar_Vehiculo(&vx,patente,valor_tasacion,marca,modelo);
return vx;
}

garante cargarGarante(){
int tipo_doc;
float ingreso_m;
long int numero;
long long int n_tramite;
garante gx;

do{
    printf("ingrese daros de garante\n");
    printf("\nInserte el numero de la opcion que indique su tipo de documento:\n  1:DNI 2:PAS 3:CF 4:CIPE 5:LC 6:LE \n  ");
    scanf("%d",&tipo_doc);fflush(stdin);
}while(tipo_doc < 1 || tipo_doc > 4);
printf("Ingrese el numero de tramite del documento \n");
scanf("%lld",&n_tramite);fflush(stdin);
printf("Ingrese el numero del documento \n");
scanf("%d",&numero); fflush(stdin);
printf("Ingrese el monto del ingreso mensual del garante \n");
scanf("%f",&ingreso_m);fflush(stdin);
Ingresar_garante(&gx,ingreso_m,tipo_doc,numero,n_tramite);
return gx;
}

cliente cargarCliente(){
int tipo_doc;
float ingreso_m;
char nyap [35];
long int numero;
long long int n_tramite,cuit;
cliente cx;

do{
    printf("\nInserte el numero de la opcion que indique su tipo de documento:\n  1:DNI 2:PAS 3:CF 4:CIPE 5:LC 6:LE \n  ");
    scanf("%d",&tipo_doc);fflush(stdin);
}while(tipo_doc < 1 || tipo_doc > 6);
printf("Ingrese el numero de tramite del documento \n");
scanf("%lld",&n_tramite);fflush(stdin);
printf("Ingrese el numero del documento \n");
scanf("%d",&numero); fflush(stdin);
printf("Ingrese el nombre del cliente \n");
gets(nyap);
printf("Ingrese el monto del ingreso mensual del cliente \n");
scanf("%f",&ingreso_m);fflush(stdin);
printf("Ingrese el cuit del cliente \n");
scanf("%lld",&cuit);fflush(stdin);
Ingresar_cliente(&cx,nyap,cuit,ingreso_m,tipo_doc,numero,n_tramite);
return cx;
}

void cargar_prenda(lista *L){
int cant_cuotas,cant_cuotas_pagas,diax,mesx,aniox;
float interes_m,cap_entregado;
fecha ini,fin;
cliente cx;
vehiculo vx;
garante gx;
prenda px;
iniGarante(&gx);
cx=cargarCliente();
if(cx.ing_Men<100000){
gx=cargarGarante();
}
vx=cargar_auto();
//solicitamos datos para la prenda
printf("Ingrese el valor del capital entregado \n");
scanf("%f",&cap_entregado);fflush(stdin);
interes_m=calcInteres(cap_entregado,recVal_Tasa(vx));
printf("Ingrese la cantidad de cuotas min 12\n");
scanf("%d",&cant_cuotas);fflush(stdin);
printf("Ingrese el dia de inicio \n");
scanf("%d",&diax);fflush(stdin);
printf("Ingrese el mes de inicio \n");
scanf("%d",&mesx);fflush(stdin);
printf("Ingrese el anio de inicio \n");
scanf("%d",&aniox);fflush(stdin);
Ingresar_Fecha(&ini,diax,mesx,aniox);
mesx=mesx+cant_cuotas;
while(mesx>12){
mesx=mesx-12;
aniox+=1;
}
Ingresar_Fecha(&fin,diax,mesx,aniox);
if(aniox<2022)
{
cant_cuotas_pagas=cant_cuotas;
}
else
	{
	aniox=2022-ini.anio;
	mesx=11-ini.mes;
	cant_cuotas_pagas=(aniox*12)+mesx;
	}
px=Ingresar_Prenda(cap_entregado,cant_cuotas,cant_cuotas_pagas,cx,vx,ini,fin,gx);
insert(L,px);
}

void cargar_Clientes(lista *lx){
    int n,i;
    do{
        printf("lea la cantidad de cliente_prenda a ingresar");
        scanf("%d",&n);
    }while(n<0);
    for(i=0;i<n;i++)
        cargar_prenda(lx);
        getchar();
}

prenda buscaNroyTramite(lista lx,long int nroX,long long int nro_TrX,int *flagX){//Inciso3
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
        if((recNum_doc(recDoc_Cliente(aux))!=nroX || recNum_tramite(recDoc_Cliente(aux))!=nro_TrX)) {(*flagX)=-1;}
        else{
            return copy(lx);
        }
        }
    }

void Inciso4(lista L,long int nroX,long long int nro_TrX){
    prenda aux;int flag=1;
    aux=buscaNroyTramite(L,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
            vehiculo auxv=recAuto(aux);garante auxg=rec_garante(aux);
        printf("datos de vehiculo:\n patente:%s valor tasacion:%0.2f marca:%s modelo:%s\n\n",auxv.pat,auxv.valor_tasacion,
               MARCAS[recMac(recAuto(aux))-1],MODELOS[recMac(recAuto(aux))-1][recMod(recAuto(aux))-1]);
        printf("datos de prenda:\n cantidad de cuotas:%d cantidad de cuotas pagadas:%d\n",aux.cantidad_cuotas,aux.cantidad_cuotas_pagas);
        printf("interes mensual:%0.2f capital entregado:%0.2f\n",recInteres(aux),recCap_entregado(aux));
        printf("fecha inicio: %d/%d/%d ",recDia(recFech_inicio(aux)),recMes(recFech_inicio(aux)),recAnio(recFech_inicio(aux)));
        printf(" fecha fin: %d/%d/%d\n",recDia(recFech_fin(aux)),recMes(recFech_fin(aux)),recAnio(recFech_fin(aux)));
        if(auxg.ing_M_garante>0)
        {
            printf("numero doc garante:%ld ingreso mensual garante:%0.2f",auxg.doc_garante.nro_doc,auxg.ing_M_garante);
        }
    }
}

void Inciso5(lista lx){
    if(isempty(lx)==1) printf("error");
    else{
        cliente auxc;vehiculo auxv;
        reset(&lx);
            do{
                auxc=rec_cliente(copy(lx));auxv=recAuto(copy(lx));
                printf("datos del titular:\n NyAP:%s Tipo de documento:%s numero de documento:%ld numero de tramite:%lld",auxc.NyAp,TIPODOC[auxc.doc.doc-1],auxc.doc.nro_doc,auxc.doc.num_tramite);getchar();
                printf("\ndatos de vehiculo:\n patente:%s valor tasacion:%0.2f marca:%s modelo:%s\n\n",auxv.pat,auxv.valor_tasacion,MARCAS[auxv.marca-1],MODELOS[auxv.marca-1][auxv.modelo-1]);getchar();
                forward(&lx);
            }while(Isoos(lx)!=1);
    }
}

void buscaNroyTramite2(lista *lx,long int nroX,long long int nro_TrX,int *flagX){//Inciso3
    if(isempty(*lx)==1){
        (*flagX)=-1;
        }
    else{
        reset(lx);
        prenda aux=copy(*lx);
        while(Isoos(*lx)!=1 && (recNum_doc(recDoc_Cliente(aux))!=nroX || recNum_tramite(recDoc_Cliente(aux))!=nro_TrX))
        {
            forward(lx);
            aux=copy(*lx);
        }
        if((recNum_doc(recDoc_Cliente(aux))!=nroX || recNum_tramite(recDoc_Cliente(aux))!=nro_TrX)) {(*flagX)=-1;}

        }
    }

void Inciso6(lista *lx,long int nroX,long long int nro_TrX){
    prenda aux;float ingX;int flag=1;
    buscaNroyTramite2(lx,nroX,nro_TrX,&flag);
    if(flag!=1) printf("error\n");
    else{
        aux=copy(*lx);
        garante auxg=rec_garante(aux);
        if(auxg.ing_M_garante>0){
        printf("lea nuevo ingreso mensual de garante:");
        scanf("%f",&ingX);
        auxg.ing_M_garante=ingX;
        aux.G=auxg;
        setVipd(lx,aux);
        }
        else{printf("el cliente no requiere garante");}
    }

}

void Inciso7(lista *lx,long int nroX,long long int nro_TrX){
    prenda aux;int flag=1,m,nx,mesx;
    buscaNroyTramite2(lx,nroX,nro_TrX,&flag);
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

int Inciso8(lista l, int marca, int cambio){
	int cant =0;prenda aux;
	if (isempty (l)==1){
		return -1;}
	else{
		reset(&l);
		while(Isoos(l)!=1){
			aux=copy(l);
			if (recMac(recAuto(aux))==marca){
				modificaMac(&aux,cambio); //cambio es la variable donde viene la marca dada por el usuariopara remplazar
				cant=cant+1;
			}
			forward(&l);
		}
	}
	return(cant);
}

int Buscar_Marca_masVendida(lista l){//inciso9
	int cant =0;
	int aux[2]={0,0,0};
	prenda auxp;
	if (isempty (l)==1)
		return(-1);
	else{
		reset(&l);
		while(Isoos(l)!=1){
			auxp=copy(l);
			if (recMac(recAuto(auxp))==1)
				aux[0]+=1;
			else{
				if (recMac(recAuto(auxp))==2)
					aux[1]+=1;
				else
					aux[2]+=1;
			}
			forward(&l);
		}
	if (aux[0]>aux[1]){
		if(aux[0]>aux[2])
			return(0);

		else{
			return(2);}}
	else{
		if (aux[1]>aux[2])
			return(1);
		else
			{return(2);}
	}
}
}

void Inciso10(lista p){
    lista lx;init(&lx);
    prenda aux;
	cliente auxCliente;
	vehiculo auxAuto;
	fecha auxfecha;
	garante auxGarante;
	documento auxdoc_garante, auxdoc_cliente;

    if(isempty(p)!=1) printf("error");
    else{
        reset(&p);
        prenda aux=copy(p);
        while(Isoos(p)!=1){
            if(vigente(aux)>0){
                insert(&lx,aux);}
            forward(&p);
            aux=copy(p);
        }
        ordenaMenorFechaFin(&lx);
        reset(&lx);
        while(Isoos(lx)!=1){
            //imprime datos cliente
				auxCliente= rec_cliente(copy(lx));
				auxdoc_cliente=recDoc_Cliente(copy(lx));
				printf("Nombre: %s \n",auxCliente.NyAp);
				printf("Cuit: %d\n",auxCliente.cuit);
				printf("Ingreso Mensual: %0.2f\n", auxCliente.ing_Men);
				printf("Tipo de documento: %d\n",auxdoc_cliente.doc );
				printf("Numero de documento:%d\n",auxdoc_cliente.nro_doc );
				printf("Numero de tramite: %lld\n",auxdoc_cliente.num_tramite );
				//imprime datos garante
				auxGarante= rec_garante(copy(lx));
				auxdoc_garante=recDoc_Garante(copy(lx));
				printf("Ingreso mensual del garante: %0.2f\n", auxGarante.ing_M_garante);
				printf("%d\n", auxdoc_garante.doc);
				printf("Numero de documento: %d\n", auxdoc_garante.nro_doc);
				printf("Numero de tramite: %lld\n", auxdoc_garante.num_tramite);
				//imprime datos del vehiculo
				auxAuto=recAuto(copy(lx));
				printf("Patente: %s\n", auxAuto.pat);
				printf("Valor de tasacion: %0.2f\n", auxAuto.valor_tasacion);
				printf("Marca del vehiculo: %d\n", auxAuto.marca);
				printf("Modelo del vehiculo: %d\n", auxAuto.modelo);
				//imprime datos de la prenda
				printf("Capital entregado: %0.2f\n", aux.capital_entregado);
				printf("Interes mensual: %0.2f\n", aux.interes_mensual);
				printf("cantidad de cuotas a pagar:%d\n", aux.cantidad_cuotas);
				printf("Cantidad decuotas pagas: %d\n", aux.cantidad_cuotas_pagas);
				//imprime fecha de inicio
				printf("%d fecha inicio", aux.fecha_ini.dia);
				printf("%d", aux.fecha_ini.mes);
				printf("%d\n", aux.fecha_ini.anio);
				//imprime fecha fin
				printf("%d fecha fin", aux.fecha_fin.dia);
				printf("%d", aux.fecha_fin.mes);
				printf("%d\n", aux.fecha_fin.anio);
				forward(&lx);
        }
    }
}

void PrendaSegun_Modelo(lista l,int modelo){//inciso11
	prenda aux;
	cliente auxCliente;
	vehiculo auxAuto;
	fecha auxfecha;
	garante auxGarante;
	documento auxdoc_garante, auxdoc_cliente;
	if (isempty(l)==1)
		printf("error");
	else{
		reset (&l);
		while(Isoos(l)!=1){
                aux=copy(l);
			if (recModelo(aux)==modelo){
				//imprime datos cliente
				auxCliente= rec_cliente(copy(l));
				auxdoc_cliente=recDoc_Cliente(copy(l));
				printf("Nombre: %s \n",auxCliente.NyAp);
				printf("Cuit: %d\n",auxCliente.cuit);
				printf("Ingreso Mensual: %0.2f\n", auxCliente.ing_Men);
				printf("Tipo de documento: %d\n",auxdoc_cliente.doc );
				printf("Numero de documento:%d\n",auxdoc_cliente.nro_doc );
				printf("Numero de tramite: %lld\n",auxdoc_cliente.num_tramite );
				//imprime datos garante
				auxGarante= rec_garante(copy(l));
				auxdoc_garante=recDoc_Garante(copy(l));
				printf("Ingreso mensual del garante: %0.2f\n", auxGarante.ing_M_garante);
				printf("%d\n", auxdoc_garante.doc);
				printf("Numero de documento: %d\n", auxdoc_garante.nro_doc);
				printf("Numero de tramite: %lld\n", auxdoc_garante.num_tramite);
				//imprime datos del vehiculo
				auxAuto=recAuto(copy(l));
				printf("Patente: %s\n", auxAuto.pat);
				printf("Valor de tasacion: %0.2f\n", auxAuto.valor_tasacion);
				printf("Marca del vehiculo: %d\n", auxAuto.marca);
				printf("Modelo del vehiculo: %d\n", auxAuto.modelo);
				//imprime datos de la prenda
				printf("Capital entregado: %0.2f\n", aux.capital_entregado);
				printf("Interes mensual: %0.2f\n", aux.interes_mensual);
				printf("cantidad de cuotas a pagar:%d\n", aux.cantidad_cuotas);
				printf("Cantidad decuotas pagas: %d\n", aux.cantidad_cuotas_pagas);
				//imprime fecha de inicio
				printf("%d fecha inicio", aux.fecha_ini.dia);
				printf("%d", aux.fecha_ini.mes);
				printf("%d\n", aux.fecha_ini.anio);
				//imprime fecha fin
				printf("%d fecha fin", aux.fecha_fin.dia);
				printf("%d", aux.fecha_fin.mes);
				printf("%d\n", aux.fecha_fin.anio);
			}
			forward(&l);
		}
	}
}

void Inciso13(lista l){
	prenda aux;
	cliente auxCliente;
	vehiculo auxAuto;
	fecha auxfecha;
	garante auxGarante;
	documento auxdoc_garante, auxdoc_cliente;
	if (isempty(l)==1)
		printf("error");
	else{
		reset (&l);
		while(Isoos(l)!=1){
                aux=copy(l);
			if (vigente(aux)>0){
				//imprime datos cliente
				auxCliente= rec_cliente(copy(l));
				auxdoc_cliente=recDoc_Cliente(copy(l));
				printf("Nombre: %s \n",auxCliente.NyAp);
				printf("Cuit: %d\n",auxCliente.cuit);
				printf("Ingreso Mensual: %0.2f\n", auxCliente.ing_Men);
				printf("Tipo de documento: %d\n",auxdoc_cliente.doc );
				printf("Numero de documento:%d\n",auxdoc_cliente.nro_doc );
				printf("Numero de tramite: %lld\n",auxdoc_cliente.num_tramite );
				//imprime datos garante
				auxGarante= rec_garante(copy(l));
				auxdoc_garante=recDoc_Garante(copy(l));
				printf("Ingreso mensual del garante: %0.2f\n", auxGarante.ing_M_garante);
				printf("%d\n", auxdoc_garante.doc);
				printf("Numero de documento: %d\n", auxdoc_garante.nro_doc);
				printf("Numero de tramite: %lld\n", auxdoc_garante.num_tramite);
				//imprime datos del vehiculo
				auxAuto=recAuto(copy(l));
				printf("Patente: %s\n", auxAuto.pat);
				printf("Valor de tasacion: %0.2f\n", auxAuto.valor_tasacion);
				printf("Marca del vehiculo: %d\n", auxAuto.marca);
				printf("Modelo del vehiculo: %d\n", auxAuto.modelo);
				//imprime datos de la prenda
				printf("Capital entregado: %0.2f\n", aux.capital_entregado);
				printf("Interes mensual: %0.2f\n", aux.interes_mensual);
				printf("cantidad de cuotas a pagar:%d\n", aux.cantidad_cuotas);
				printf("Cantidad decuotas pagas: %d\n", aux.cantidad_cuotas_pagas);
				//imprime fecha de inicio
				printf("%d fecha inicio", aux.fecha_ini.dia);
				printf("%d", aux.fecha_ini.mes);
				printf("%d\n", aux.fecha_ini.anio);
				//imprime fecha fin
				printf("%d fecha fin", aux.fecha_fin.dia);
				printf("%d", aux.fecha_fin.mes);
				printf("%d\n", aux.fecha_fin.anio);
			}
			forward(&l);
		}
	}
}

void Inciso14(lista lx,float *sx){//!antes de invocar usar isempty y reset
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
//!inciso15 es igual 7
void Inciso16(lista lx){
    if(isempty(lx)==1) printf("error");
    else{
        reset(&lx);
        while(Isoos(lx)!=1)
            {
                if(recIngMensual_G(copy(lx))>0){
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

int contarGarantes(lista lx){//!antes de invocar usar isempty y reset inciso17
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

