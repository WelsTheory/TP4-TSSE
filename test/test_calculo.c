/**
 * TP4 WILLIAMS LIMONCHI
 * 
 * La función Calculo, obtiene los datos del acelerómetro IMU6050 para saber el estado de la persona (Parada - Sentada - Caida)
 * para ello utilizo el Método de Integración de Simpson. Este método se utiliza para hallar la velocidad de caída cada cierta muestras.
 * Para verificar si el módulo calculo funciona correctamenta, se hicieron algunos test:
 * 
 * 1 - Se puede reiniciar el calculo de las muestras.
 * 2 - El Calculo de muestras sólo se efectua a partir de 3 muestras.
 * 3 - El Calculo de muestras se efectua a partir de 3 muestras.
 * 4 - Calcular 16 muestras y verificar el resultado.
 * 5 - El calculo de 16 muestras agregarle otros 3 muestras más y hallar el calculo final de las 19 muestras.
 * 
*/

#include "unity.h"
#include "calculo.h"

float area_t;

#define MUESTRAS_DATAS 16
#define MUESTRAS_DATO   3
#define MUESTRA_UNIDAD  1

void setup(void)
{
    Calculo_create(&area_t);
}

/**
 * Test de Reinicio de calculos 
 * 1 - Se puede reiniciar el calculo de las muestras.
*/
void test_ReinicioCalculo(void)
{
    float data[MUESTRAS_DATO] = {1.0, 4.0, 5.0};
    area_t = 1.0;
    Calculo_create(&area_t);
    Calculo_Integral(MUESTRAS_DATO, data);
    Reinicio_Integral();
    TEST_ASSERT_EQUAL_FLOAT(0.0, area_t);
}

/**
 * Test Calculo Una Muestra
 * 2 - El Calculo de muestras sólo se efectua a partir de 3 muestras. 
*/
void test_CalculoUnaMuestra(void)
{
    float data[MUESTRA_UNIDAD] = {1.0};
    Calculo_create(&area_t);
    Reinicio_Integral();
    Calculo_Integral(MUESTRA_UNIDAD, data);
    TEST_ASSERT_EQUAL_FLOAT(0.0, area_t);
}

/**
 * Test Calculo a partir de 3 Muestras
 * 3 - El Calculo de muestras se efectua a partir de 3 muestras.
*/
void test_CalculoTresMuestras(void)
{
    float data[MUESTRAS_DATO] = {1.0,1.0,1.0};
    Calculo_create(&area_t);
    Reinicio_Integral();
    Calculo_Integral(MUESTRAS_DATO, data);
    TEST_ASSERT_EQUAL_FLOAT(0.1666667, area_t);
}

/**
 * Test Verificacion de Muestras
 * 4 - Calcular 16 muestras y verificar el resultado. 
*/
void test_VerificacionDeMuestras(void)
{
    float data[MUESTRAS_DATAS] = {0.00f, 0.01f, 0.04f, 0.09f, 0.16f, 0.25f, 0.36f, 0.49f, 0.64f, 0.81f, 1.00f, 1.21f, 1.44f, 1.69f, 1.96f, 2.25f};
    Calculo_create(&area_t);
    Reinicio_Integral();
    Calculo_Integral(MUESTRAS_DATAS, data);
    TEST_ASSERT_EQUAL_FLOAT(1.125, area_t);
}

/**
 * Test Verificacion Sumatoria de Muestras
 * 5 - El calculo de 16 muestras agregarle otros 3 muestras más y hallar el calculo final de las 19 muestras.
*/
void test_VerificacionSumatoriaMuestras(void)
{
    float data[MUESTRAS_DATAS] = {0.00f, 0.01f, 0.04f, 0.09f, 0.16f, 0.25f, 0.36f, 0.49f, 0.64f, 0.81f, 1.00f, 1.21f, 1.44f, 1.69f, 1.96f, 2.25f};
    float dato[MUESTRAS_DATO] = {1.0,0.0,0.0};
    Calculo_create(&area_t);
    Reinicio_Integral();
    Calculo_Integral(MUESTRAS_DATAS, data);
    Calculo_Integral(MUESTRAS_DATO, dato);
    TEST_ASSERT_EQUAL_FLOAT(1.333333, area_t);
}





