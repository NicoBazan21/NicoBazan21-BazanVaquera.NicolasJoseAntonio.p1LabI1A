#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

    int id;
    char descTipo[20];

}eTipo;


#endif // TIPO_H_INCLUDED


/** \brief muestra los datos de la estructura tipo en un indice
 *
 * \param hola eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo hola);


/** \brief muestra los elementos de la estrucutra tipo
 *
 * \param lista[] eTipo
 * \param tam int
 * \return int
 *
 */
int listarTipos(eTipo lista[], int tam);


/** \brief carga la descripcion tipo a un puntero
 *
 * \param lista[] eTipo
 * \param tam int
 * \param tipo[] char
 * \param id int
 * \return int
 *
 */
int cargarTipo(eTipo lista[], int tam, char tipo[], int id);


/** \brief carga la descripcion tipo a un puntero
 *
 * \param tipo[] eTipo
 * \param tam int
 * \param idTipo int
 * \param descTipo[] char
 * \return int
 *
 */
int cargarDescTipo(eTipo tipo[], int tam, int idTipo, char descTipo[]);
