#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED



typedef struct{

    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    char material;
    float rodado;
    int isEmpty;

}eBicicleta;

#endif // BICICLETA_H_INCLUDED

//No dejo los prototipos porque me saltó dos veces un error que me cerraba el programa y no lo pude solucionar...
//soy consciente de que faltan los doxygen pero esq cuando metia los INCLUDE se llenaba la consola de errores
//y me tildaba la computadora... mil disculpas profe!
//de todas maneras el codigo DOXYGEN que va en este archivo LO DEJO ESCRITO en el bicicleta.C
