#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{
    int opcion, flag = 0, flag2 = 0;
    float num1, num2;

    do
    {
        printf("Calculadora\n\n");
        printf("1- Ingresar 1er operando (A= %.2f)\n", num1);
        printf("2- Ingresar 2do operando (B= %.2f)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        if(opcion < 1 || opcion > 9)
        {
            printf("Ingrese opcion valida\n");
        }

        switch(opcion)
        {
            case 1:
                printf("Ingrese primer operando: ");
                scanf("%f", &num1);
                flag = 1;
                break;

            case 2:
                printf("Ingrese segundo operando: ");
                scanf("%f", &num2);
                flag2 = 1;
                break;

            case 3:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El resultado de la suma es: %.2f\n", functionSuma(num1, num2));
                break;

            case 4:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El resultado de la resta es: %.2f\n", functionResta(num1, num2));
                break;

            case 5:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El resultado de la division es: %.2f\n", functionDivision(num1, num2));
                break;

            case 6:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El resultado de la multiplicacion es: %.2f\n", functionMultiplicacion(num1, num2));
                break;

            case 7:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El factorial del operando A es: %.2f\n", functionFactorial(num1));
                printf("El factorial del operando B es: %.2f\n", functionFactorial(num2));
                break;

            case 8:
                if(flag == 0 && flag2 == 0)
                {
                    printf("ERROR, no ha ingresado numeros para operar\n");
                    break;
                }
                printf("El resultado de la suma es: %.2f\n", functionSuma(num1, num2));
                printf("El resultado de la resta es: %.2f\n", functionResta(num1, num2));
                printf("El resultado de la division es: %.2f\n", functionDivision(num1, num2));
                printf("El resultado de la multiplicacion es: %.2f\n", functionMultiplicacion(num1, num2));
                printf("El factorial del operando A es: %.2f\n", functionFactorial(num1));
                printf("El factorial del operando B es: %.2f\n", functionFactorial(num2));
                break;

            case 9:
                printf("Usted esta saliendo del programa\n");
                opcion = 0;
                break;



        }

        system("pause");
        system("cls");

    }while(opcion != 0);

    return 0;
}
