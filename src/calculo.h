



/* File inclusion */
#include <stdint.h>

/* Macro definition */
#define DELTA_X     0.1    


/* Function declaration */
float Integration_Trapezoid_Method(float y_val, uint8_t reset);
float Integration_Midpoint_Method(float y_val, uint8_t reset);
float Integration_Simpson_Method(float y_val, uint8_t reset);
void Calculo_Integral(uint16_t total_muestras, float data[total_muestras]);
void Reinicio_Integral(void);

void Calculo_create(float * puntero);

