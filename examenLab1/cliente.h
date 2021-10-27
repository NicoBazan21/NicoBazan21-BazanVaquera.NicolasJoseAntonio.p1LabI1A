#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{

    int id;
    char nombre[20];
    char sexo;

}eCliente;
#endif // CLIENTE_H_INCLUDED


/** \brief carga la descripcion de un cliente a un putnero
 *
 * \param listCliente[] eCliente
 * \param tam int
 * \param idCliente int
 * \param nombreCliente[] char
 * \return int
 *
 */
int cargarDescCliente(eCliente listCliente[], int tam, int idCliente, char nombreCliente[]);
