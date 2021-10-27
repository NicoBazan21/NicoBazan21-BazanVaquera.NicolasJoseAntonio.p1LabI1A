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

/** \brief inicializa el isempty de la estrucutra bici en 0
 *
 * \param lista[] eBicicleta recibe la estructura
 * \param tam int   y el tamaño
 * \return int
 *
 */
int inicializarBicicletas(eBicicleta lista[], int tam)
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
/** \brief muestra un indice de la structura bicileta
 *
 * \param recibe la estructura
 * \param   y el resto de datos para mostrar una sola iteracion
 de los datos necesarios
 * \return
 *
 */

void mostrarBicicleta(eBicicleta lista, eTipo tipos[],int tamT, eColor colores[], int tamC, eCliente cliente, int tamCli)
{
    char descTipos[20];
    cargarDescTipo(tipos, tamT, lista.idTipo, descTipos);
    char descColor[20];
    cargarColores(colores, tamC, descColor, lista.idColor);


    printf(" %6s  %d    %10s %10s %10s   %.2f   %c\n",
        cliente.nombre,
        lista.id,
        lista.marca,
        descTipos,
        descColor,
        lista.rodado,
        lista.material
        );
}


/** \brief recibe todos los estructura disponibles para mostrar los elementos de cada uno
 *
 * \param lista[] eBicicleta    recibe estructura bicicleta
 * \param tam int   tamaño de ebicicltea
 * \param tipo[] eTipo  estructura tipo
 * \param tamT int  tamaño de eTipo
 * \param color[] eColor    color
 * \param tamC int  tamaño de eColor
 * \param cliente[] eCliente    cliente
 * \param tamCli int    tamaño de eCliente
 * \return int
 *
 */
int mostrarBicicletas(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***Listado de Bicicletas***\n");
        printf("---------------------------------------------------------------\n");
        printf(" Nombre     Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("---------------------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0)
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

/** \brief ingresa rodados meidante un puntero
 *
 * \param rodado float*
 * \return int
 *
 */
int ingresarRodado(float* rodado)
{
    int todoOk = 0;
    float aux;

    if(rodado!=NULL)
    {
        printf("Ingrese rodado(20, 26, 27.5, 29): ");
        fflush(stdin);
        scanf("%f",&aux);
        while(aux != 20 && aux != 26 && aux != 27.5 && aux != 29)
        {
            printf("Rodado invalido. Reingrese el rodado.\n");
            fflush(stdin);
            scanf("%f",&aux);
        }
        *rodado=aux;
    todoOk = 1;
    }
    return todoOk;
}

/** \brief da de alta una bicicltea inicializando su isemptu en 0
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param pId int*
 * \param tipos[] eTipo
 * \param tamT int
 * \param colores[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \param contadorA int*
 * \param contadorC int*
 * \return int
 *
 */
int altaBicicleta(eBicicleta lista[], int tam, int* pId, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente cliente[], int tamCli, int* contadorA, int* contadorC)
{
    int todoOk = 0;
    int indice;
    char auxMarca[20];
    char auxNombre[20];
    char auxSexo;

    int auxTipo;
    int tipoMin = 1000;
    int tipoMax = 1003;

    int auxColor;
    int colorMin = 5000;
    int colorMax = 5004;

    char material;

    float rodado;

    if(lista != NULL && tam > 0 && pId != NULL)
    {
        indice=buscarLibre(lista, tam);

        if(indice==-1)
        {
            printf("No hay lugar. \n");
        }
        else
        {
            pedirCadena(auxNombre, 20, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");

            printf("Ingrese sexo f/m: ");
            fflush(stdin);
            scanf("%c", &auxSexo);

            while(auxSexo != 'f' && auxSexo != 'm')
            {
                printf("Error. Reingrese sexo f/m: ");
                fflush(stdin);
                scanf("%c", &auxSexo);
            }

            pedirCadena(auxMarca, 20, "Ingrese Marca: ", "Error, marca invalida. Ingrese marca nuevamente: ");
            system("cls");
            listarTipos(tipos, 4);
            pedirEntero(&auxTipo, "Ingrese el tipo de bicicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
            fflush(stdin);
            listarColores(colores, 5);
            pedirEntero(&auxColor, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", colorMin, colorMax);

            ingresarRodado(&rodado);

            printf("Ingrese material carbono o alumunio (c o a): ");
            fflush(stdin);
            scanf("%c", &material);

            while(material != 'c' && material != 'a')
            {
                printf("Error. Reingrese material, carbono o alumunio (c o a): ");
                fflush(stdin);
                scanf("%c", &material);
            }

            if(material == 'c')
            {
                (*contadorC)++;
            }
            if(material == 'a')
            {
                (*contadorA)++;
            }

            strlwr(auxNombre);
            auxNombre[0] = toupper(auxNombre[0]);

            strlwr(auxMarca);
            auxMarca[0] = toupper(auxMarca[0]);

            lista[indice].id=*pId;

            cliente[indice].id=*pId;
            strcpy(cliente[indice].nombre, auxNombre);
            cliente[indice].sexo=auxSexo;


            (*pId)++;
            strcpy(lista[indice].marca, auxMarca);
            lista[indice].rodado=rodado;
            lista[indice].idTipo=auxTipo;
            lista[indice].idColor=auxColor;
            lista[indice].material=material;
            lista[indice].isEmpty=0;

            todoOk=1;
        }
    }
    return todoOk;
}

/** \brief inicializa el isempty de un indice de la eestructura en 1
 *
 * \param list eBicicleta*
 * \param len int
 * \return int
 *
 */
int bajaBicicleta(eBicicleta* list, int len)
{
    int buscarId;
    int encontrarId;

    pedirEntero(&buscarId, "Ingrese el id a buscar: ", "Error. Id Invalido. Ingrese id nuevamente: ", 0, 1000);
    int todoOk = 0;
    int indice;

    if(list != NULL && len > 0)
    {
        indice=findBicicletaById(list, len, buscarId);

        if(indice != -1)
        {

            list[indice].isEmpty=1;
            todoOk=1;

        }

    }

    return todoOk;

}

/** \brief modifica los datos de un indice de la estructura bicicleta
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int
 *
 */
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT)
{
    int todoOk=0;
    int indice;
    int buscarId;
    char confirmar;
    int auxTipo = 0;
    int tipoMin = 1000;
    int tipoMax = 1003;
    int marcaCambio = 0;
    float auxRodado;
    int rodadoCambio = 0;

    char seguir = 'n';

    int min = 0;
    int max =20010;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        printf("     ***  Menu Modificar  ***\n\n");

        pedirEntero(&buscarId, "Ingrese el id: ", "Error. Id Invalido. Ingrese id nuevamente: ", min, max);
        indice=findBicicletaById(lista, tam, buscarId);
        printf("\n");

        if(indice == -1)
        {
            printf("No existe esta bicicleta. \n");
        }
        else
        {
            printf("Marca de la bicicleta ingresada: %s \n", lista[indice].marca);
            pedirCaracter(&confirmar, "\nDesea modificarlo? s/n", "Cancelando...", 's');

            if(confirmar=='s')
            {
                do{
                    system("cls");
                    switch(menuModificacion())
                    {
                        case 1:
                            listarTipos(tipos, 4);
                            pedirEntero(&auxTipo, "Ingrese el tipo de bicicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                            lista[indice].idTipo=auxTipo;
                            marcaCambio=1;
                            break;
                        case 2:
                            ingresarRodado(&auxRodado);
                            lista[indice].rodado=auxRodado;
                            rodadoCambio=1;
                            break;
                        case 3:
                            pedirCaracter(&seguir, "Desea salir? s/n", "Saliendo...", 'n');
                            break;
                        default:
                            printf("Opcion invalida\n");
                            break;
                    }

                    system("pause");
                }while(seguir == 'n');
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion. \n");
            }
            if(marcaCambio)
            {
                printf("Se ha cambiado el tipo a: %d\n", lista[indice].idTipo);
            }
            if(rodadoCambio)
            {
                printf("Se ha cambiado el rodado a: %.2f \n", lista[indice].rodado);

            }
            if(!marcaCambio && !rodadoCambio)
            {
                printf("No se modifico nada. \n");
            }
        }
    }
    return todoOk;

}

/** \brief encuentra una bicicleta por id y devuelve el indice si existe
 *
 * \param list eBicicleta*
 * \param len int
 * \param iDe int
 * \return int
 *
 */
int findBicicletaById(eBicicleta* list, int len,int iDe)
{
    int indice = -1;

    if(list != NULL && len > 0 && (iDe > -1 && iDe <= len))
    {
        for(int i = 0; i <= len; i++)
        {
            if(list[i].id == iDe && list[i].isEmpty == 0)
            {
                indice=i;
                break;
            }
        }
    }
        if(indice == -1)
        {
            printf("No existe la bicicleta. \n");
        }
    return indice;
}

/** \brief inf
 *
 * \param list[] eBicicleta
 * \param tam int
 * \param criterio int
 * \param cliente[] eCliente
 * \return int
 *
 */
int ordenar(eBicicleta list[], int tam, int criterio, eCliente cliente[])
{
    int todoOk = 0;

    eBicicleta auxiliar;
    char auxNombre[20];
    char auxNombreAux[20];

    if(list != NULL && tam > 0)
    {

        for(int i=0;i<tam-1;i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                if(criterio==1 && ((list[i].idTipo < list[j].idTipo) ||
                   (list[i].idTipo == list[j].idTipo && list[i].rodado < list[j].rodado)))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;

                    strcpy(auxNombre, cliente[j].nombre);
                    strcpy(cliente[j].nombre, cliente[i].nombre);
                    strcpy(cliente[i].nombre, auxNombre);

                }
                else
                if(criterio==2 && ((list[i].idTipo > list[j].idTipo) ||
                (list[i].idTipo > list[j].idTipo && list[i].rodado > list[j].rodado)))
                {
                       auxiliar=list[i];
                        list[i]=list[j];
                        list[j]=auxiliar;

                        strcpy(auxNombre, cliente[j].nombre);
                        strcpy(cliente[j].nombre, cliente[i].nombre);
                        strcpy(cliente[i].nombre, auxNombre);
                }



                }

            }
        }

    }


    return todoOk;
}

/** \brief muestra las bicicletas por marca ingresada
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \param marca[] char
 * \return int
 *
 */
int mostrarBicicletasMarca(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, char marca[])
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***INFORME Bicis por Marca***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");

        strlwr(marca);
        marca[0] = toupper(marca[0]);


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && strcmp(lista[i].marca, marca)==0)
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

/** \brief muestra las bicicletas por marca y color ingresado
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \param marca[] char
 * \param idIngresado int
 * \return int
 *
 */
int mostrarBicicletasMarcaColor(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, char marca[], int idIngresado)
{
    int todoOk=0;

    int holis=0;

    int contador = 0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***INFORME Bicis por Marca***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");

        strlwr(marca);
        marca[0] = toupper(marca[0]);

        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && strcmp(lista[i].marca, marca)==0 && lista[i].idColor == idIngresado)
           {
                mostrarBicicleta(lista[i], tipo,tamT, color, tamC, cliente[i], tamCli);
                holis=1;
                contador++;
           }
        }


        if(!holis)
        {
            printf("No hay bicis para mostrar.\n");
        }
        else
        {
            if(contador >= 2)
            {
                            printf("Del color y marca ingresados hay : %d bici.\n", contador);

            }
            else
            {
                printf("Del color y marca ingresados hay una sola bici.\n");
            }
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}

/** \brief muestra las bicicletas por color y tipo ingresado
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \param tipoIngresado int
 * \param idIngresado int
 * \return int
 *
 */
int mostrarBicicletasColorTipo(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, int tipoIngresado, int idIngresado)
{
    int todoOk=0;

    int holis=0;

    int contador = 0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***INFORME Bicis por Marca***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].idTipo==tipoIngresado && lista[i].idColor == idIngresado)
           {
                mostrarBicicleta(lista[i], tipo,tamT, color, tamC, cliente[i], tamCli);
                holis=1;
                contador++;
           }
        }


        if(!holis)
        {
            printf("No hay bicis para mostrar.\n");
        }
        else
        {
            if(contador >= 2)
            {
                            printf("Del color y tipo ingresados hay : %d bicis.\n", contador);

            }
            else
            {
                printf("Del color y tipo ingresados hay una sola bici.\n");
            }
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}


/** \brief muestra las bicicletas por id
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \param idIngresado int
 * \return int
 *
 */
int mostrarBicicletasId(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, int idIngresado)
{
    int todoOk=0;

    int holis=0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {

        system("cls");
        printf("\t ***Informe trabajo por ID de bici***\n");
        printf("-----------------------------------------------------\n");
        printf("  Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");

        idIngresado++;

        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0 && lista[i].id == idIngresado)
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


/** \brief muestra las bicicletas por tipo
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param idTipo int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int mostrarBiciTipo(eBicicleta lista[], int tam, eTipo tipo[], int tamT, int idTipo, eColor color[], int tamC, eCliente cliente[], int tamCli)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idTipo == idTipo)
            {
                mostrarBicicleta(lista[i], tipo, tamT, color, tamC, cliente[i], tamCli);
            }
        }

        todoOk=1;
    }

    return todoOk;
}


/** \brief informes bicicletas por tipo
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamT int
 * \param color[] eColor
 * \param tamC int
 * \param cliente[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int informeBicisPorTipo(eBicicleta lista[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC, eCliente cliente[], int tamCli)
{
    int todoOk = 0;


    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0)
    {   system("cls");
        printf("\t ***Informe trabajo por ID de bici***\n");
        printf("---------------------------------------------------------------\n");
        printf("  Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("---------------------------------------------------------------\n");

        for(int i = 0; i < tamT; i++)
        {
            printf("Tipo: %s\n\n", tipo[i].descTipo);
            mostrarBiciTipo(lista, tam, tipo, tamT, tipo[i].id,color, tamC,cliente, tamCli);
            printf("\n");
        }

        todoOk=1;
    }

    return todoOk;
}


/** \brief menu de informes
 *
 * \return int
 *
 */
int menuInformes()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 12;

    printf("           ***Menu Informes***\n");
    printf("--------------------------------------------------------\n");
    printf(" 1. INFORME BICIS POR COLOR\n");
    printf(" 2. INFORME BICIS POR TIPO\n");
    printf(" 3. INFORME CANTIDAD DE BICIS DE ALUMINIO O CARBONO\n");
    printf(" 4. INFORME BICIS POR TIPO\n");
    printf(" 5. INFORME BICIS POR TIPO Y COLOR INGRESADO\n");
    printf(" 6. MOSTRAR TRABAJOS POR ID\n");
    printf(" 7. MOSTRAR TRABAJOS POR FECHA\n");
    printf(" 8. MOSTRAR PRECIO TOTAL DE SERVICIO\n");
    printf("Extras: \n");
    printf(" 9. INFORME BICIS POR MARCA\n");
    printf(" 10. INFORME BICIS POR COLOR y MARCA\n");
    printf(" 11. PEDIR BICI INFORMAR DE SERVICIOS\n");
    printf(" 12. Salir\n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;


}
/*
int mostrarBicicletasMayorMarca(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli)
{
    int todoOk=0;

    int holis=0;

    int cantidadLoc[5] = {0};
    int idAux = 0;
    int mayor;
    int flag = 1;
    if(lista != NULL && tam > 0 && tipo != NULL && tamT > 0 && color != NULL && tamC > 0)
    {
        system("cls");
        printf("\t ***Informe de Bicicletas Mayor Marca***\n");
        printf("-----------------------------------------------------\n");
        printf(" Nombre Id\t    Marca\tTipo\t  Color\t  Rodado   Material\t\n");
        printf("-----------------------------------------------------\n");

        for(int i = 0; i < tamT; i++)
        {
            //printf("%s: ", localidades[i].descripcion);
            idAux=tipo[i].id;

            for(int f = 0; f < tam; f++)
            {
                if(lista[f].isEmpty == 1 && lista[f].idTipo == idAux)
                {
                   cantidadLoc[i]++;
                }
            }
        }

        for(int h = 0; h < tamT; h++)
        {
            if(flag)
            {
                mayorHabitante=cantidadLoc[h];
                flag = 0;
            }
            else
            {
                if(mayorHabitante < cantidadLoc[h])
                {
                    mayorHabitante=cantidadLoc[h];
                }
            }
        }


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0)
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

*/
/*
int todoOk=0;
    int cantidadLoc[5] = {0};
    int idAux = 0;
    int mayorHabitante;
    int flag = 1;


    system("cls");

    if(lista != NULL && tam > 0 && localidades != NULL && tamloc > 0)
    {
        printf("Cantidad de personas en la localidad:\n");
        for(int i = 0; i < tamloc; i++)
        {
            //printf("%s: ", localidades[i].descripcion);
            idAux=localidades[i].id;

            for(int f = 0; f < tam; f++)
            {
                if(lista[f].isEmpty == 1 && lista[f].idLocalidad == idAux)
                {
                   cantidadLoc[i]++;
                }
            }
        }

        for(int h = 0; h < tamloc; h++)
        {
            if(flag)
            {
                mayorHabitante=cantidadLoc[h];
                flag = 0;
            }
            else
            {
                if(mayorHabitante < cantidadLoc[h])
                {
                    mayorHabitante=cantidadLoc[h];
                }
            }
        }

        for(int k = 0; k < tamloc; k++)
        {
            if(mayorHabitante == cantidadLoc[k])
            {
                printf("Localidad: %s \n", localidades[k].descripcion);
            }
        }


*/






/*

int informeBicisColor(eBicicleta lista[], int tam, eColor color[], int tamC)
{
    int todoOk = 0;
    int buscar;
    system("cls");
    printf("Informe de personas");

    if(lista != NULL && tam > 0 && color != NULL && tamC > 0)
    {
        listarColores(color, tamC);

        printf("Ingrese el color que desea buscar: ");
        scanf("%d", &buscar);

        while(!validarIdcolor(color, tamC, buscar))
        {
            listarColores(color, tamC);
            printf("Id Invalido. Ingrese nueva localidad.");
            scanf("%d", &buscar);
        }

        mostrarPersonasIdLocalidad(lista, tam, localidades, tamloc, buscar);

        todoOk=1;
    }


    return todoOk;
}
*/

