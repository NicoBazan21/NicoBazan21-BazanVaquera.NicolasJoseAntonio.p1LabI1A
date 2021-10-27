#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "miBiblioteca.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int menu()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 30;

    system("cls");
    printf("\t ***Nomina de Bicicletas***\n");
    printf("------------------------------------\n");
    printf(" 1. ALTA BICICLETA\n");
    printf(" 2. MODIFICAR BICICLETA\n");
    printf(" 3. BAJA BICICLETA\n");
    printf(" 4. LISTAR BICICLETAS\n");
    printf(" 5. LISTAR TIPOS\n");
    printf(" 6. LISTAR COLORES\n");
    printf(" 7. LISTAR SERVICIOS\n");
    printf(" 8. ALTA TRABAJO\n");
    printf(" 9. LISTAR TRABAJOS\n");
    printf(" 29. INFORMES.\n");
    printf(" 30. Salir\n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;

}


int validarNumCadenas(char* name, int tam)
{
    int todoOk= 0;
    int okey;
    int error = 1;

    if(name != NULL && tam > 0)
    {
        do{
            error=0;
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);
                if(okey == 0)
                {
                    printf("Error. Ingreso con caracteres invalidos. Ingrese nuevamente: ");
                    gets(name);
                    tam=strlen(name);
                    error = 1;
                }
            }

        }while(error == 1);

        todoOk=1;
    }
    return todoOk;
}

int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[])
{
    int todoOk =0;
    char entrada[256];
    int tamEntrada;

    if(cadena != NULL && tam > 0 && mensajeUno != NULL && mensajeError != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        gets(entrada);
        tamEntrada = strlen(entrada);

        validarNumCadenas(entrada, tamEntrada);

        while(tamEntrada > tam || tamEntrada < 1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(entrada);
            tamEntrada=strlen(entrada);
        }

        strcpy(cadena, entrada);
        todoOk=1;
    }

    return todoOk;
}


int pedirCaracter(char *caracter, char mensajeUno[], char mensajeError[], char si)
{
    int todoOk = 0;

    if(caracter != NULL && mensajeError != NULL && mensajeUno != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%c", caracter);

        if(*caracter != si)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%c", caracter);
        }
    }


    return todoOk;
}

int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max)
{
    int todoOk =0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%f", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }

        todoOk=1;
    }


    return todoOk;
}

int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max)
{
    int todoOk=0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%d", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }

    todoOk=1;
    }

    return todoOk;
}

int buscarLibre(eBicicleta lista[], int tam)
{
    int libre = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 1; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}

int menuModificacion()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 4;

    printf("\t *** Modificacion de datos ***\n");
    printf("------------------------------------\n");

    printf("1. Modificar tipo\n");
    printf("2. Modificar rodado\n");
    printf("3. Salir \n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}
