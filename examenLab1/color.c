
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
#include "cliente.h"


void mostrarColores(eColor hola)
{

    printf("  %d   %14s\t\n",
            hola.id,
            hola.nombreColor
            );

}

int listarColores(eColor lista[], int tam)
{
    int todoOk=0;

    if(lista!=NULL&&tam>0)
    {
        system("cls");
        printf("\t ***Colores de bicicleta***\n");
        printf("-----------------------------------------------\n");
        printf("  Id\t    Descripcion\n");
        printf("-----------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarColores(lista[i]);
        }
        todoOk=1;
    }
    return todoOk;
}


int cargarColores(eColor lista[], int tam, char tipo[], int id)
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && tipo != NULL && id > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(id==lista[i].id)
            {
                strcpy(tipo, lista[i].nombreColor);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int validarIdcolor(eColor color[], int tam, int iD)
{

    int existe = 0;

    if(color != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(color[i].id == iD)
            {
                existe=1;
                break;
            }
        }
    }
    return existe;
}

/*
int mostrarBicisIdColor(eBicicleta lista[], int tam, eColor colores[], int tamC, int idColor)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***Informe de Bicicletas por color***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idColor == idColor)
            {
                mostrarBicicleta(lista[i], , tam);
                mostrarBicicleta(lista[i], tipo,tamT, color, tamC, cliente[i], tamCli);
            }
        }

        todoOk=1;
    }

    return todoOk;
}
*/

int mostrarBicicletasColor(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, int idIngresado)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***Listado de Bicicletas***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].idColor == idIngresado)
           {
                mostrarBicicleta(lista[i], tipo,tamT, color, tamC, cliente[i], tamCli);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay bicis para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}


int mostrarBicicletasTipo(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, int idIngresado)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***Listado de Bicicletas***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].idTipo == idIngresado)
           {
                mostrarBicicleta(lista[i], tipo,tamT, color, tamC, cliente[i], tamCli);
                holis=1;
           }
        }

        if(!holis)
        {
            printf("No hay bicis para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}
