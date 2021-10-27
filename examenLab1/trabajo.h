#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{

    int id;
    int idBici;
    int idServicio;
    int fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"

/** \brief init todos los elemntos del etrabajo en 0
 *
 * \param lista[] eTrabajo recibe struct etrabajo
 * \param tam int   recibe el tamaño del struct
 * \return int
 *
 */
int inicializarTrabajo(eTrabajo lista[], int tam);

/** \brief dar de alta un trabajo relacionado con 4 structuras
 *
 * \param lista[] eBicicleta    recibe estructura bicicleta
 * \param tam int   recibe el tamaño de bicicltea
 * \param pIdTrabajo int*   recibe puntero de idtrabajo autoincrementativo
 * \param listTrabajo[] eTrabajo    recibe estructura trabajo
 * \param tamTrabajo int    recibe tamaño del trabajo
 * \param listServicio[] eServicio  structurca servicio
 * \param tamS int  tamaño servicio
 * \param fecha[] eFecha    estructura fecha
 * \param tamFe int tamaño de fecha
 * \param total[] int   recibe un array paralelo independiente para almacenar precios
 * \return int
 *
 */
int altaTrabajo(eBicicleta lista[], int tam,int* pIdTrabajo, eTrabajo listTrabajo[], int tamTrabajo, eServicio listServicio[], int tamS, eFecha fecha[], int tamFe, int total[]);

/** \brief muestra un trabajo recibido por parametros y punteros
 *
 * \param lista eTrabajo
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha eFecha
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo lista, eServicio listServ[], int tamSer, eFecha fecha);

/** \brief recibe las estructuras para hacer otra llamada para mostrar iterando cada elemento de la esstructura
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha[] eFecha
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[]);

/** \brief recibe estructura trabajo y un id ingresado por el usuario para mostrar los datos correspondientes con ese id
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha[] eFecha
 * \param idIngresado int
 * \return int
 *
 */
int mostrarTrabajosPorId(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int idIngresado);


/** \brief recibe estructura trabajo e id y muestra datos correspondientes con el trabajo realizado
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha[] eFecha
 * \param idIngresado int
 * \return int
 *
 */
int mostrarTrabajosPorIdTrabajo(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int idIngresado);

/** \brief muestra trabajos con los datos correspondientes
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha[] eFecha
 * \return int
 *
 */
int mostrarTrabajosPlus(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[]);

/** \brief recibe fecha y trabajos para mostrar solo los que coincidan con la fecha ingresada
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \param listServ[] eServicio
 * \param tamSer int
 * \param fecha[] eFecha
 * \param diaI int
 * \param mesI int
 * \param anioI int
 * \return int
 *
 */
int mostrarTrabajosPorFecha(eTrabajo lista[],int tam, eServicio listServ[], int tamSer, eFecha fecha[], int diaI, int mesI, int anioI);

