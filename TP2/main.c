#include <stdio.h>
#include <stdlib.h>
#include "TP2.h"

#define MAX 20

int main()
{
    EPersonas persona[MAX];
    iniciaVector(persona, MAX);
    char seguir='s';
    int opcion=0;
    int flag = 0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nOpcion: ");
        scanf("%d",&opcion);

        if(opcion <= 0 || opcion >5)
        {
            printf("Ingrese una opcion valida\n");
        }

        switch(opcion)
        {
            case 1:

                obtenerDato(persona, MAX);
                flag = 1;
                break;

            case 2:

                if(flag != 1)
                {
                    printf("ERROR, no hay personas cargadas en el sistema.\n");
                    break;
                }
                borrarDato(persona, MAX);
                break;

            case 3:

                 if(flag != 1)
                {
                    printf("ERROR, no hay personas cargadas en el sistema.\n");
                    break;
                }
                ordenarDato(persona, MAX);
                break;

            case 4:

                if(flag != 1)
                {
                    printf("ERROR, no hay personas cargadas en el sistema.\n");
                    break;
                }
                graficoDato(persona, MAX);
                break;
            case 5:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
