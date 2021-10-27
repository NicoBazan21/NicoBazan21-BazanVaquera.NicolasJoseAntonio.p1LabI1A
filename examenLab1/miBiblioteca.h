#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED



#endif // MIBIBLIOTECA_H_INCLUDED


int menu();


/** \brief valida que en las cadenas no haya numeros
 *
 * \param name char*
 * \param tam int
 * \return int
 *
 */
int validarNumCadenas(char* name, int tam);

/** \brief pide una cadena y muestra un mensaje de pedido y uno de error
 *
 * \param cadena[] char
 * \param tam int
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \return int
 *
 */
int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[]);

/** \brief pide un caracter y muestra un mensaje de pedido y uno de error
 *
 * \param caracter char*
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \param si char
 * \return int
 *
 */
int pedirCaracter(char *caracter, char mensajeUno[], char mensajeError[], char si);


/** \brief pide un flotante y muestra un mensaje de pedido y uno de error
 *
 * \param numero float*
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \param min float
 * \param max float
 * \return int
 *
 */
int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max);


/** \brief pide un entero y muestra un mensaje de pedido y uno de error
 *
 * \param numero int*
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \param min int
 * \param max int
 * \return int
 *
 */
int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max);

/** \brief busca un indice libre en la estructura bicicleta
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eBicicleta lista[], int tam);

/** \brief muestra el menu para modificar bicicleta
 *
 * \return int
 *
 */
int menuModificacion();

