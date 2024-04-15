// PIC12F629 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 4000000
#define Led GPIO2

int contador = 0;

void init(void)
{
    //CONFIGURA LOS PINES COMO ENTRADA O SALIDA
    TRISIO = 0b11111011;
    
    //SELECCIONAMOS TIMER 0
    T0CS = 0;
    PSA = 0;
    
    //CONFIGURA EL PRESCALER EN 255
    PS2 = 1;
    PS1 = 1;
    PS0 = 1;
    
    TMR0 = 255;
    
    //HABILITAR INTERRUPCIONES
    T0IE = 1; 
    GIE = 1;
}

void __interrupt() inter(void)
{
    if(T0IF)
    {
        contador += 1;
        if(contador >= 16)
        {
            if(Led = 0)
                Led = 1;
            else
                Led = 0;
            contador = 0;
        }
        T0IF = 0;
    }
}

void main(void) 
{
    init();
    
    while(1)
    {
        
    }
    return;
}
