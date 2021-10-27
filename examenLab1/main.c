#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "color.h"
#include "miBiblioteca.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "cliente.h"
#include "fecha.h"

#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4


int main()
{
    char seguir = 'n';
    char seguirDos='n';
    int nextId=1;
    int nextIdTrabajo=1;
    int criterio;
    int flag=0;

    int contadorA = 0;
    int contadorC = 0;


    int total[TAM] = {0};

    eBicicleta lista[TAM];
    eTrabajo listTrab[TAM];
    eCliente listCliente[TAM];
    eFecha listFecha[TAM];


eTipo tipos[TAM_T] = {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"},
    };
    int tipoMin =1000;
    int tipoMax = 1003;

eColor colores[TAM_C] = {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"},
    };

    int colorMin = 5000;
    int colorMax = 5004;
eServicio servicio[TAM_S] = {
        {20000, "Limpieza", 30},
        {20001, "Parche", 400},
        {20002, "Centrado", 500},
        {20003, "Cadena", 450},
    };

    inicializarBicicletas(lista, TAM);
    inicializarTrabajo(listTrab, TAM);

    int colorIngresado;
    int idIngresado;
    int tipoIngresado;
    int idMin = 0;
    int idMax = TAM;

    char auxMarca[20];

    int auxDia;
    int auxMes;
    int auxAnio;

    int auxdiaMin = 1;
    int auxdiaMax = 31;

    int auxmesMax = 12;

    int auxAnioMax = 2021;

    //hardcodearBicis(lista, TAM, TAM, &nextId);

    do{
        switch(menu())
        {
            case 1:
                if(!altaBicicleta(lista, TAM, &nextId, tipos, TAM_T, colores, TAM_C,listCliente, TAM, &contadorA, &contadorC))
                {
                    printf("Ocurrio un error al dar de alta.\n");
                }
                flag = 1;
                break;
            case 2:
                if(flag)
                {
                    if(!mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM))
                    {
                        printf("Ocurrio un error al mostrar bicis\n");
                    }
                    if(!modificarBicicleta(lista, TAM, tipos, TAM_T))
                    {
                        printf("Ocurrio un error al modificar\n");
                    }
                }
                else
                {
                    printf("Primero hay que ingresar una bici\n");
                }
                break;
            case 3:
                if(flag)
                {
                    mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                    if(bajaBicicleta(lista,TAM))
                    {
                        printf("Baja exitosa. \n");
                    }
                }
                else
                {
                    printf("Primero hay que ingresar una bici\n");
                }
                break;
            case 4:
                if(flag)
                {
                    printf("Ingrese 1 para descendente\n Ingrese 2 para ascendente: ");
                    scanf("%d", &criterio);
                    ordenar(lista, TAM, criterio, listCliente);
                    if(!mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM))
                    {
                        printf("Ocurrio un error al mostrar bicis\n");
                    }
                }
                else
                {
                    printf("Primero hay que ingresar una bici\n");
                }
                break;
            case 5:
                system("cls");
                if(!listarTipos(tipos, TAM_T))
                {
                    printf("Ocurrio un error al listar tipos\n");
                }
                break;
            case 6:
                if(!listarColores(colores, TAM_C))
                {
                    printf("Ocurrio un error al listar colores\n");
                }
                break;
            case 7:
                if(!listarServicio(servicio, TAM_S))
                {
                    printf("Ocurrio un error al listar servicios\n");
                }
                break;
            case 8:
                if(flag)
                {
                    mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);

                    altaTrabajo(lista, TAM, &nextIdTrabajo, listTrab, TAM, servicio, TAM_S, listFecha, TAM, total);

                }
                else
                {
                    printf("Primero hay que ingresar una bici\n");
                }
                break;
            case 9:
                if(flag)
                {
                    mostrarTrabajos(listTrab, TAM, servicio, TAM_S, listFecha);
                }
                else
                {
                    printf("Primero hay que ingresar una bici\n");
                }
                break;
            case 10:
                listarColores(colores, TAM_C);
                pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                mostrarBicicletasColor(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, colorIngresado);
                break;
            case 11:
                listarTipos(tipos, TAM_T);
                pedirEntero(&tipoIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                mostrarBicicletasTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, tipoIngresado);
                break;
            case 12:
                if(contadorA > contadorC)
                {
                    printf("Hay mas bicis de Aluminio que de Carbono.\n En total de aluminio: %d \n", contadorA);
                }
                else
                {
                    if(contadorC > contadorA)
                    {
                        printf("Hay mas bicis de Carbono que de Aluminio.\n En total de carbono: %d \n", contadorC);
                    }
                    else
                    {
                        printf("Hay la misma cantidad de bicis de aluminio que de carbono.\n");
                    }
                }
                break;
            case 13:
                informeBicisPorTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                break;
            case 14:
                listarColores(colores, TAM_C);
                pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                listarTipos(tipos, TAM_T);
                pedirEntero(&tipoIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                mostrarBicicletasColorTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, tipoIngresado, colorIngresado);
                break;
            case 15:
                mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                pedirEntero(&idIngresado, "Ingrese id de la bicicleta: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                mostrarTrabajosPorId(listTrab, TAM, servicio, TAM_S, listFecha, idIngresado);

                break;
            case 16:
                pedirEntero(&auxDia, "Ingrese el dia: ", "Error. Reingrese el dia: ", auxdiaMin, auxdiaMax);
                pedirEntero(&auxMes, "Ingrese el mes: ", "Error. Reingrese el mes: ", auxdiaMin, auxmesMax);
                pedirEntero(&auxAnio, "Ingrese el anio: ", "Error. Reingrese el anio: ", auxdiaMin, auxAnioMax);

                mostrarTrabajosPorFecha(listTrab, TAM, servicio, TAM_S, listFecha, auxDia, auxMes, auxAnio);
                break;
            case 17:
                mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                pedirEntero(&idIngresado, "Ingrese id de la bicicleta: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                printf("La suma de los importes de la bici seleccinoada es: %d", total[idIngresado]);

                break;
            case 18:
                mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                pedirCadena(auxMarca, 20, "Ingrese la marca que desea buscar: ", "Error. Reingrese marca: ");
                mostrarBicicletasMarca(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, auxMarca);
                break;
            case 19:
                listarColores(colores, TAM_C);
                pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                pedirCadena(auxMarca, 20, "Ingrese la marca que desea buscar: ", "Error. Reingrese marca: ");
                mostrarBicicletasMarcaColor(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, auxMarca, colorIngresado);
                break;
            case 20:
                mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                mostrarTrabajosPlus(listTrab, TAM, servicio, TAM_S, listFecha);
                pedirEntero(&idIngresado, "Ingrese id del trabajo: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                //mostrarTrabajosPorId(listTrab, TAM, servicio, TAM_S, listFecha, idIngresado);
                mostrarBicicletasId(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, idIngresado);
                break;
            case 30:
                pedirCaracter(&seguir, "Desea salir? s/n", "Saliendo...", 'n');
                break;

            case 29:
                do{
                system("cls");
                    switch(menuInformes())
                    {
                        case 1:
                            listarColores(colores, TAM_C);
                            pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                            mostrarBicicletasColor(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, colorIngresado);
                            break;
                        case 2:
                            listarTipos(tipos, TAM_T);
                            pedirEntero(&tipoIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                            mostrarBicicletasTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, tipoIngresado);
                            break;
                        case 3:
                            if(contadorA > contadorC)
                            {
                                printf("Hay mas bicis de Aluminio que de Carbono.\n En total de aluminio: %d \n", contadorA);
                            }
                            else
                            {
                                if(contadorC > contadorA)
                                {
                                    printf("Hay mas bicis de Carbono que de Aluminio.\n En total de carbono: %d \n", contadorC);
                                }
                                else
                                {
                                    printf("Hay la misma cantidad de bicis de aluminio que de carbono.\n");
                                }
                            }
                            break;
                        case 4:
                            informeBicisPorTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                            break;
                        case 5:
                            listarColores(colores, TAM_C);
                            pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                            listarTipos(tipos, TAM_T);
                            pedirEntero(&tipoIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                            mostrarBicicletasColorTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, tipoIngresado, colorIngresado);
                            break;
                        case 6:
                            mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                            pedirEntero(&idIngresado, "Ingrese id de la bicicleta: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                            mostrarTrabajosPorId(listTrab, TAM, servicio, TAM_S, listFecha, idIngresado);

                            break;
                        case 7:
                            pedirEntero(&auxDia, "Ingrese el dia: ", "Error. Reingrese el dia: ", auxdiaMin, auxdiaMax);
                            pedirEntero(&auxMes, "Ingrese el mes: ", "Error. Reingrese el mes: ", auxdiaMin, auxmesMax);
                            pedirEntero(&auxAnio, "Ingrese el anio: ", "Error. Reingrese el anio: ", auxdiaMin, auxAnioMax);

                            mostrarTrabajosPorFecha(listTrab, TAM, servicio, TAM_S, listFecha, auxDia, auxMes, auxAnio);
                            break;
                        case 8:
                            mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                            pedirEntero(&idIngresado, "Ingrese id de la bicicleta: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                            printf("La suma de los importes de la bici seleccinoada es: %d", total[idIngresado]);

                            break;
                        case 9:
                            mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                            pedirCadena(auxMarca, 20, "Ingrese la marca que desea buscar: ", "Error. Reingrese marca: ");
                            mostrarBicicletasMarca(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, auxMarca);
                            break;
                        case 10:
                            listarColores(colores, TAM_C);
                            pedirEntero(&colorIngresado, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);
                            pedirCadena(auxMarca, 20, "Ingrese la marca que desea buscar: ", "Error. Reingrese marca: ");
                            mostrarBicicletasMarcaColor(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, auxMarca, colorIngresado);
                            break;
                        case 11:
                            mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM);
                            mostrarTrabajosPlus(listTrab, TAM, servicio, TAM_S, listFecha);
                            pedirEntero(&idIngresado, "Ingrese id del trabajo: ", "Error, id de tipo invalido. Reingrese: ", idMin, idMax);
                            //mostrarTrabajosPorId(listTrab, TAM, servicio, TAM_S, listFecha, idIngresado);
                            mostrarBicicletasId(lista, TAM, tipos, TAM_T, colores, TAM_C, listCliente, TAM, idIngresado);
                            break;
                        case 12:
                            pedirCaracter(&seguirDos, "Desea salir? s/n", "Saliendo...", 'n');
                            break;
                    }
                system("pause");

                }while(seguirDos == 'n');
            break;

        }


    system("pause");

    }while(seguir == 'n');


    return 0;
}
