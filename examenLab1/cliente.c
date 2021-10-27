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


int cargarDescCliente(eCliente listCliente[], int tam, int idCliente, char nombreCliente[])
{
    int todoOk=0;

    if(listCliente!= NULL && tam > 0 && nombreCliente!= NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(listCliente[i].id==idCliente)
            {
                strcpy(nombreCliente, listCliente[i].nombre);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
