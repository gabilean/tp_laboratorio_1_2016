#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

/** \brief Calcular suma
 *
 * \param x recibe un numero
 * \param y recibe un numero
 * \return resultado de la suma
 *
 */

float functionSuma(float x, float y)
{
    return x + y;
}

/** \brief Calcular resta
 *
 * \param x recibe un numero
 * \param y recibe un numero
 * \return resultado de la resta
 *
 */

float functionResta(float x, float y)
{
    return x - y;
}

/** \brief Calcular division
 *
 * \param x recibe un numero
 * \param y recibe un numero
 * \return resultado de la division, si param y recibe 0 devuelve error
 *
 */

float functionDivision(float x, float y)
{
    if(y == 0)
    {
        printf("ERROR, no se puede dividir por 0");
    }

    return x/y;
}

/** \brief Calcular multiplicacion
 *
 * \param x recibe un numero
 * \param y recibe un numero
 * \return resultado de la multiplicacion
 *
 */

float functionMultiplicacion(float x, float y)
{
    return x*y;
}

/** \brief Calcular factorial
 *
 * \param x recibe un numero
 * \return factorial
 *
 */

float functionFactorial(int x)
{
    if(x > 1)
    return x*functionFactorial(x-1);
    return 1;
}

#endif // CALC_H_INCLUDED
