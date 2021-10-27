#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

    int id;
    char nombreColor[20];

}eColor;

#endif // COLOR_H_INCLUDED
#include "bicicleta.h"
#include "tipo.h"
#include "cliente.h"


/** \brief muestra los elementos en un dice de la estructura color
 *
 * \param hola eColor
 * \return void
 *
 */
void mostrarColores(eColor hola);


/** \brief muestra los elementos de la estructura color
 *
 * \param lista[] eColor
 * \param tam int
 * \return int
 *
 */
int listarColores(eColor lista[], int tam);


/** \brief carga la descripcion del color a un puntero
 *
 * \param lista[] eColor
 * \param tam int
 * \param tipo[] char
 * \param id int
 * \return int
 *
 */
int cargarColores(eColor lista[], int tam, char tipo[], int id);


/** \brief valida que el id del color existe
 *
 * \param color[] eColor
 * \param tam int
 * \param iD int
 * \return int
 *
 */
int validarIdcolor(eColor color[], int tam, int iD);


/** \brief muestra bicicletas pedidas por color
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
int mostrarBicicletasColor(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColor color[],int tamC, eCliente cliente[], int tamCli, int idIngresado);
