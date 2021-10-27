#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "miBiblioteca.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"

int inicializarTrabajo(eTrabajo lista[], int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i<tam;i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }

    return todoOk;
}

int altaTrabajo(eBicicleta lista[], int tam,int* pIdTrabajo, eTrabajo listTrabajo[], int tamTrabajo, eServicio listServicio[], int tamS, eFecha fecha[], int tamFe, int total[])
{
    int todoOk = 0;
    int buscarId;
    int indice = -1;

    int servicio;

    int suma = 0;

    int serMin = 20000;
    int serMax = 20003;
    int min = 0;
    int max =20010;

    int auxDia;
    int auxMes;
    int auxAnio;

    int auxdiaMin = 1;
    int auxdiaMax = 31;

    int auxmesMax = 12;

    int auxAnioMax = 2021;

    //float suma= 0;

    if(lista != NULL && tam > 0 && pIdTrabajo != NULL)
    {
        printf("\n");
        printf("     ***  Alta trabajo  ***\n\n");

        pedirEntero(&buscarId, "Ingrese el id: ", "Error. Id Invalido. Ingrese id nuevamente: ", min, max);
        indice=findBicicletaById(lista, tam, buscarId);
        printf("\n");


        if(indice==-1)
        {
            printf("No hay lugar. \n");
        }
        else if(listTrabajo[indice].isEmpty == 0)
        {
            listarServicio(listServicio, tamS);

            pedirEntero(&servicio, "Ingrese id servicio: ", "Error. Reingrese id servicio: ", serMin, serMax);

            pedirEntero(&auxDia, "Ingrese el dia: ", "Error. Reingrese el dia: ", auxdiaMin, auxdiaMax);
            pedirEntero(&auxMes, "Ingrese el mes: ", "Error. Reingrese el mes: ", auxdiaMin, auxmesMax);
            pedirEntero(&auxAnio, "Ingrese el anio: ", "Error. Reingrese el anio: ", auxdiaMin, auxAnioMax);

            fecha[indice+1].dia=auxDia;
            fecha[indice+1].mes=auxMes;
            fecha[indice+1].anio=auxAnio;

            listTrabajo[indice+1].id=*pIdTrabajo;
            (*pIdTrabajo)++;
            switch(servicio)
            {
            case 20000:
                suma+=30;
                break;
            case 20001:
                suma+=400;
                break;
            case 20002:
                suma+=500;
                break;
            case 20003:
                suma+=450;
                break;
            }

            total[indice]+=suma;
            printf("%d", total[indice]);

            listTrabajo[indice+1].idBici=lista[indice].id;
            listTrabajo[indice+1].idServicio=servicio;
            listTrabajo[indice+1].fecha=indice;
            listTrabajo[indice+1].isEmpty=0;

            todoOk=1;
        }
        else
        {

            listarServicio(listServicio, tamS);

            pedirEntero(&servicio, "Ingrese id servicio: ", "Error. Reingrese id servicio: ", serMin, serMax);

            pedirEntero(&auxDia, "Ingrese el dia: ", "Error. Reingrese el dia: ", auxdiaMin, auxdiaMax);
            pedirEntero(&auxMes, "Ingrese el mes: ", "Error. Reingrese el mes: ", auxdiaMin, auxmesMax);
            pedirEntero(&auxAnio, "Ingrese el anio: ", "Error. Reingrese el anio: ", auxdiaMin, auxAnioMax);

            fecha[indice].dia=auxDia;
            fecha[indice].mes=auxMes;
            fecha[indice].anio=auxAnio;

            switch(servicio)
            {
            case 20000:
                suma+=30;
                break;
            case 20001:
                suma+=400;
                break;
            case 20002:
                suma+=500;
                break;
            case 20003:
                suma+=450;
                break;
            }

            total[indice]+=suma;
            printf("%d", total[indice]);

            listTrabajo[indice].id=*pIdTrabajo;
            (*pIdTrabajo)++;

            listTrabajo[indice].idBici=lista[indice].id;
            listTrabajo[indice].idServicio=servicio;
            listTrabajo[indice].fecha=indice;
            listTrabajo[indice].isEmpty=0;

            todoOk=1;
        }


    }
    suma = 0;
    return todoOk;
}

void mostrarTrabajo(eTrabajo lista, eServicio listServ[], int tamSer, eFecha fecha)
{
    char descServ[20];
    cargarServicio(listServ, tamSer, descServ, lista.idServicio);

    printf("       %d              %d           %10s  %d/%d/%d\n",
           lista.id,
           lista.idBici,
           descServ,
           fecha.dia,
           fecha.mes,
           fecha.anio
           );
}

int mostrarTrabajos(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[])
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\t ***Listado de Bicicletas***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id Trabajo\t   Id Bicicleta\t    Servicio Fecha\n");
        printf("-----------------------------------------------------\n");

        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0)
           {
                mostrarTrabajo(lista[i], listServ, tamSer, fecha[i]);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay trabajos para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

int mostrarTrabajosPorId(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int idIngresado)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\t ***Informe trabajo por ID de bici***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id Trabajo\t   Id Bicicleta\t    Servicio Fecha\n");
        printf("-----------------------------------------------------\n");



        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].idBici == idIngresado)
           {
                mostrarTrabajo(lista[i], listServ, tamSer, fecha[i]);
                holis=1;
           }
        }


        if(!holis)
        {
            printf("No hay trabajos para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

int mostrarTrabajosPorIdTrabajo(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int idIngresado)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\t ***Informe trabajo por ID de trabajo***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id Trabajo\t   Id Bicicleta\t    Servicio Fecha\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].id == idIngresado)
           {
                mostrarTrabajo(lista[i], listServ, tamSer, fecha[i]);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay trabajos para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

int mostrarTrabajosPlus(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[])
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\t ***Listado de trabajos realizados***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id Trabajo\t   Id Bicicleta\t    Servicio Fecha\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0)
           {
                mostrarTrabajo(lista[i], listServ, tamSer, fecha[i]);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay trabajos para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

int mostrarTrabajosPorFecha(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int diaI, int mesI, int anioI)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\t ***Listado de trabajos en la Fecha ingresada***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id Trabajo\t   Id Bicicleta\t    Servicio  Fecha\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && fecha[i].anio == anioI && fecha[i].mes == mesI && fecha[i].dia == diaI)
           {
                mostrarTrabajo(lista[i], listServ, tamSer, fecha[i]);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay trabajos para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}
