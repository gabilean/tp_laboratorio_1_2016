#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 50

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie[MAX];
    initMovie(movie, MAX);
    readBin(movie, MAX);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                addMovie(movie, MAX);
                break;
            case 2:
                deleteMovie(movie, MAX);
                break;
            case 3:
                modifyMovie(movie, MAX);
               break;
            case 4:
                generateWeb(movie, MAX);
                break;
            case 5:
                saveBin(movie, MAX);
                seguir = 'n';
                break;
            default:
                printf("Ingrese un valor correcto\n");
        }
        system("pause");
        system("cls");
    }

    return 0;
}
