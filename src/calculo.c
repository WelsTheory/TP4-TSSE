
/* File inclusion */
#include "calculo.h"

/* Function definition */
static float * area;
uint16_t conta = 0;

void Calculo_create(float * dato)
{
    area = dato;
}

void Calculo_Integral(uint16_t total_muestras, float data[total_muestras])
{
    float dato;
    for(conta = 0; conta < total_muestras; conta++){
        dato = Integration_Simpson_Method(data[conta], 0);
    } 
    *area = dato;
}

void Reinicio_Integral(void)
{
    float dato;
    dato = Integration_Simpson_Method(0.0,1);
    *area = dato;
}

float Integration_Simpson_Method(float y_val, uint8_t reset){
    
    static float f_x[3] = {0.0, 0.0,0.0};
    static float total_area = 0.0;
    float  delta_area = 0.0;
    static uint8_t integral_count = 0; 
    
    if(reset == 0){
    
        /* Actualizar los valores almacenados de y (SIEMPRE) */
        f_x[2] = f_x[1];
        f_x[1] = f_x[0];
        f_x[0] = y_val;
        
        /* Calcular delta de area */
        integral_count++;
        
        if(integral_count >= 2){
            integral_count = 0;
            delta_area = (DELTA_X / 3.0) * (f_x[0] + 4*f_x[1] + f_x[2]);
        }
        
        total_area += delta_area;
    
    }else{
        
        f_x[2] = 0.0;
        f_x[1] = 0.0;
        f_x[0] = 0.0;
        total_area = 0.0;
        integral_count = 0;
    
    }
    return total_area;
}