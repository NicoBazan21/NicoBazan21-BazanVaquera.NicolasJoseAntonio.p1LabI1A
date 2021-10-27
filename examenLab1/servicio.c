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




void mostrarServicio(eServicio hola)
{

    printf("  %d   %14s\t $%.2f\n",
            hola.id,
            hola.descServ,
            hola.precio
            );

}

int listarServicio(eServicio lista[], int tam)
{
    int todoOk=0;

    if(lista!=NULL&&tam>0)
    {
        system("cls");
        printf("\t ***Servicios***\n");
        printf("-----------------------------------------------\n");
        printf("  Id\t     Descripcion\t Precio\n");
        printf("-----------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarServicio(lista[i]);
        }
        todoOk=1;
    }
    return todoOk;
}


int cargarServicio(eServicio lista[], int tam, char tipo[], int id)
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && tipo != NULL && id > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(id==lista[i].id)
            {
                strcpy(tipo, lista[i].descServ);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
