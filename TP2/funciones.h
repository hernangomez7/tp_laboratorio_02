#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Imprime en pantalla una entidad en lista
 * @param lista el array se pasa como parametro.
 * @return (void)
 */
void mostrarpersona(EPersona);

/**
 * llena una lista con datos
 * @param lista el array se pasa como parametro.
 * @param tamaño de lista.
 * @return (void)
 */

void cargarPersonas(EPersona[],int);

/**
 * ordena la lista por nombre
 * @param lista el array se pasa como parametro.
 * @param tamaño de lista.
 * @param modo de  ordena alfabeticamente o alrevèz.
 * @return (void)
 */
void MostpersOrde(EPersona[],int,int);

#endif // FUNCIONES_H_INCLUDED
