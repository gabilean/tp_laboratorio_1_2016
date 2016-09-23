#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersonas;

/**
 * Obtiene los datos de la persona.
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @return void
 */
void obtenerDato(EPersonas lista[], int tam);

/**
 * Inhabilita los datos de una persona
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @return void
 */
void borrarDato(EPersonas lista[], int tam);

 /**
 * Ordena los datos alfabeticamente
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @return void
 */
void ordenarDato(EPersonas lista[], int tam);

 /**
 * Inicializa vector estado de todo el array de estructuras
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @return void
 */
 void iniciaVector(EPersonas lista[], int tam);

/**
 * Obtiene el primer indice libre del array
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersonas lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas
 * @param dni el dni a ser buscado en el array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersonas lista[], int tam, int dni);

/**
 * Muestra un grafico indicando cantidad de personas clasificadas por edad
 * @param lista el array se pasa como parametro
 * @param tam cantidad de personas.
 * @return void
 */

void graficoDato(EPersonas lista[], int tam);


#endif // TP2_H_INCLUDED
