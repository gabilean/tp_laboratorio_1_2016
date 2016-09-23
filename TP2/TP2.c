#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "TP2.h"

void iniciaVector(EPersonas lista[], int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
        lista[i].edad = 0;
    }
}

void obtenerDato(EPersonas lista[], int tam)
{
    int i;
    char buffer[50];

    i = obtenerEspacioLibre(lista, tam);

    if(i == -1)
    {
        printf("No queda mas espacio para cargar personas\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(buffer);
        strlwr(buffer);
        buffer[0] = toupper(buffer[0]);
        strcpy(lista[i].nombre, buffer);

        printf("Ingrese edad: ");
        scanf("%d", &lista[i].edad);

        printf("Ingrese DNI: ");
        scanf("%d", &lista[i].dni);

        lista[i].estado = 1;
    }


}

void borrarDato(EPersonas lista[], int tam)
{
    int i;
    int dni;

    printf("Ingrese el dni de la persona que desea eliminar: ");
    scanf("%d", &dni);

    i = buscarPorDni(lista, tam, dni);

    if(i == -1)
    {
        printf("No se encuentra el DNI ingresado\n");
    }
    else
    {
        printf("Baja exitosa\n");
       lista[i].estado = 2;
    }


}

void ordenarDato(EPersonas lista[], int tam)
{
    int i;
    int j;
    char auxNom[50];
    int auxNum;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                strcpy(auxNom, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxNom);

                auxNum = lista[i].edad;
                lista[i].edad = lista[j].edad;
                lista[j].edad = auxNum;

                auxNum = lista[i].dni;
                lista[i].dni = lista[j].dni;
                lista[j].dni = auxNum;

            }
        }
    }

    printf("DNI\t\tNombre\tEdad\n");

    for(i = 0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        printf("%d\t\t%s\t%d\t%d\n", lista[i].dni, lista[i].nombre, lista[i].edad, lista[i].estado);
    }
}

int obtenerEspacioLibre(EPersonas lista[], int tam)
{
    int i;
    int libre = -1;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            libre = i;
            break;
        }
    }

    return libre;
}

int buscarPorDni(EPersonas lista[], int tam, int dni)
{
    int i;
    int foundDni = -1;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].dni == dni)
        {
            foundDni = i;
            break;
        }
    }

    return foundDni;
}

void graficoDato(EPersonas lista[], int tam)

{
     int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

      for(i = 0; i < tam ; i++)
    {
        if(lista[i].edad != 0 && lista[i].estado == 1)
        {
            if(lista[i].edad < 19)
            {
                hasta18++;
            }

            if(lista[i].edad >18 && lista[i].edad <36)
            {
                de19a35++;
            }

            if(lista[i].edad > 35)
            {
                mayorDe35++;
            }
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);

}

