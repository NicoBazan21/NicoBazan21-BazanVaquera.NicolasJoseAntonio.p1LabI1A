
#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct{

    int id;
    char descServ[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief muestra los datos de un indice de la estructura servicio
 *
 * \param hola eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio hola);


/** \brief muestra los elementos de la estrucutra servicio
 *
 * \param lista[] eServicio
 * \param tam int
 * \return int
 *
 */
int listarServicio(eServicio lista[], int tam);


/** \brief carga la descripcion de servicio en un puntero
 *
 * \param lista[] eServicio
 * \param tam int
 * \param tipo[] char
 * \param id int
 * \return int
 *
 */
int cargarServicio(eServicio lista[], int tam, char tipo[], int id);
