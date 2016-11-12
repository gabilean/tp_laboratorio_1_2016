#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
 * \brief Alta de peliculas
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 *
 */

void addMovie(EMovie movie[], int lenght)
{
    int indice;
    char auxNumeros[50];
    FILE* pMovie;
    //char BUFFER[1000];
    indice = isEmpty(movie, lenght);

    if(indice == -1)
    {
        printf("No hay mas espacio para seguir cargando peliculas\n");
    }
    else
    {
        movie[indice].id = indice;
        while(!getStringLetras("Ingrese nombre de pelicula: ", movie[indice].titulo))
        printf("ERROR, ingrese solo letras\n");
        while(!getStringLetras("Ingrese genero: ", movie[indice].genero))
        printf("ERROR, ingrese solo letras\n");
        while(!getStringNumeros("Ingrese duracion: ", auxNumeros))
        printf("ERROR, ingrese solo numeros\n");
        movie[indice].duracion = atoi(auxNumeros);
        getString("Ingrese descripcion: ", movie[indice].descripcion);
        while(!getStringNumeros("Ingrese puntaje: ", auxNumeros))
        printf("ERROR, ingrese solo numeros\n");
        movie[indice].puntaje = atoi(auxNumeros);
        printf("Ingrese link de imagen: ");
        scanf("%s", movie[indice].linkImagen);
        movie[indice].estado = 1;

        if((pMovie = fopen("Movies.dat", "a+b"))==NULL)
        {
            printf("No existe el archivo\n");
        }
        else
        {
            fwrite(movie, sizeof(movie), 2, pMovie);
            fclose(pMovie);
        }
    }
}


/**
 * \brief Generacion de pagina web
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 *
 */


void generateWeb(EMovie movie[], int lenght)
{
    FILE* pFile;
    int i;

    pFile = fopen("Peliculas.html", "a");

    if(pFile == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    for(i = 0; i < lenght; i++)
    {
        if(movie[i].estado == 1)
        {
            fprintf(pFile, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''>", movie[i].linkImagen);
            fprintf(pFile, "</a><h3><a href='#'>%s</a></h3><ul>", movie[i].titulo);
            fprintf(pFile, "<li>Género:%s</li>", movie[i].genero);
            fprintf(pFile, "<li>Puntaje:%d</li>", movie[i].puntaje);
            fprintf(pFile, "<li>Duracion:%d</li></ul>", movie[i].duracion);
            fprintf(pFile, "<p>%s</p></article>", movie[i].descripcion);
        }

    }

    fclose(pFile);

}


/**
 * \brief Busca indice libre en el array de peliculas
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return indice con campo estado en 0
 *
 */

int isEmpty(EMovie movie[], int lenght)
{
    int i;
    int indice = -1;

    for(i = 0; i < lenght; i++)
    {
        if(movie[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/**
 * \brief Busqueda de pelicula
 * \param movie array de la estructura de peliculas
 * \param index indice que va a ser utilizado para la busqueda
 * \param lenght cantidad de peliculas máximas
 * \return -1 si no se encontro indice solicitado o i correspondiente al indice existente
 *
 */


int findMovie(EMovie movie[], int index, int lenght)
{
    int i;
    int indice = -1;

    for(i = 0; i < lenght; i++)
    {
        if(index == movie[i].id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/**
 * \brief Inicializador de estado y id
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */


void initMovie(EMovie movie[], int lenght)
{
    int i;

    for(i = 0; i < lenght; i++)
    {
        movie[i].estado = 0;
        movie[i].id = 0;
    }
}

/**
 * \brief Elimina un elemento del array de estructuras
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */


void deleteMovie(EMovie movie[], int lenght)
{
    int auxId;
    int indice;

    showMovies(movie, lenght);

    printf("Ingrese id de pelicula a eliminar: ");
    scanf("%d", &auxId);

    if(findMovie(movie, auxId, lenght) == -1)
    printf("ERROR, no se encontro la pelicula solicitada.\n");
    else
    {
        indice = auxId;
        showMovie(movie[indice]);
        if(validaS_N())
        {
            movie[auxId].estado = 0;
        }
        else
        {
            printf("Cancelando opreacion...\n");
        }
    }
}

/**
 * \brief Modificar campo de pelicula
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */

void modifyMovie(EMovie movie[], int lenght)
{
    int auxId;
    int indice;
    char auxNumeros[50];

    showMovies(movie, lenght);

    printf("Ingrese id de pelicula a modificar: ");
    scanf("%d", &auxId);

    if(findMovie(movie, auxId, lenght) == -1)
    printf("ERROR, no se encontro la pelicula solicitada.\n");
    else
    {
        indice = auxId;
        showMovie(movie[indice]);
        if(validaS_N())
        {
            switch(menuModifyMovie())
            {
                case 1:
                    while(!getStringLetras("Ingrese nombre de pelicula: ", movie[indice].titulo))
                    printf("ERROR, ingrese solo letras\n");
                    break;
                case 2:
                    while(!getStringLetras("Ingrese genero: ", movie[indice].genero))
                    printf("ERROR, ingrese solo letras\n");
                    break;
                case 3:
                    while(!getStringNumeros("Ingrese duracion: ", auxNumeros))
                    printf("ERROR, ingrese solo numeros\n");
                    movie[indice].duracion = atoi(auxNumeros);
                    break;
                case 4:
                    getString("Ingrese descripcion: ", movie[indice].descripcion);
                    break;
                case 5:
                    while(!getStringNumeros("Ingrese puntaje: ", auxNumeros))
                    printf("ERROR, ingrese solo numeros\n");
                    movie[indice].puntaje = atoi(auxNumeros);
                    break;
                case 6:
                    printf("Ingrese link de imagen: ");
                    scanf("%s", movie[indice].linkImagen);
                    break;

                default:
                    printf("Opcion incorrecta.\n");
            }
        }
        else
        {
            printf("Cancelando opreacion...\n");
        }
    }
}

/**
 * \brief Menu de opciones modificar pelicula
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return opcion elegida del 1 al 6
 */

int menuModifyMovie(EMovie movie[], int lenght)
{
    int opcion;

    printf("Que desea modificar?\n\n");

    printf("1. Titulo\n");
    printf("2. Genero\n");
    printf("3. Duracion\n");
    printf("4. Descripcion\n");
    printf("5. Puntaje\n");
    printf("6. Link Imagen\n");

    printf("Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/**
 * \brief Muestra una pelicula
 * \param movie array de la estructura de peliculas
 * \return void
 */

void showMovie(EMovie movie)
{
    printf("%d - %s - %s - %d - %s - %d\n", movie.id, movie.titulo, movie.genero, movie.duracion, movie.descripcion, movie.puntaje);
}

/**
 * \brief Muestra array de peliculas
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */

void showMovies(EMovie movie[], int lenght)
{
    int i;

    printf("ID - Titulo - Genero - Duracion - Descripicion - Puntaje\n\n");

    for(i = 0; i < lenght; i++)
    {
        if(movie[i].estado == 1)
        printf("%d - %s - %s - %d - %s - %d\n", movie[i].id, movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion, movie[i].puntaje);
    }
}

/**
 * \brief Guarda los datos cargados en el array en un archivo
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */


void saveBin(EMovie movie[], int lenght)
{
    FILE *p;

    p = fopen("Movies.dat", "wb");

    if(p == NULL)
    {
        printf("ERROR, no se puede abrir archivo.");
        exit(1);
    }

    fwrite(movie, sizeof(movie), lenght, p);

    fclose(p);
}

/**
 * \brief Lee los datos del archivo y los copia en el array de peliculas
 * \param movie array de la estructura de peliculas
 * \param lenght cantidad de peliculas máximas
 * \return void
 */

void readBin(EMovie movie[], int lenght)
{
    FILE* p;

    p = fopen("Movies.dat", "rb");

    if(p == NULL)
    {
        p = fopen("Movies.dat", "wb");

        if(p == NULL)
        {
           printf("ERROR, no se puede abrir archivo.");
            exit(1);
        }

    }

    fread(movie, sizeof(movie), lenght, p);

    fclose(p);
}

/**
 * \brief Pregunta al usuario si desea continuar con el proceso actual
 * \param void
 * \return 1 si desea continuar y 0 si desea cancelar la operacion
 */

int validaS_N(void)
{
        char resp = 's';

        if(resp != 'n')
        {
            printf("\nDesea continuar? s/n\n");
            fflush(stdin);
            scanf("%c", &resp);
            resp = tolower(resp);

        }

    while(resp != 's' && resp != 'n')
    {
        printf("Ingerese un valor correcto, ¿Desea continuar?\n");
        fflush(stdin);
        scanf("%c", &resp);
        resp = tolower(resp);
    }

    if (resp == 's')
    {
        return 1;

    }else
    {
        return 0;

    }
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
    //scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */

void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}
