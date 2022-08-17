/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

unsigned int g_rising_value;
unsigned int g_falling_value;
unsigned int g_pulse_width;

void Rising_interrupt(unsigned int rising_value);
void Falling_interrupt(unsigned int falling_value);
void putch(char data);
/*
                         Main application
 */
void main(void)
{
    
    int flag = 0;
    unsigned int duty = 0;
    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    CCP1_SetCallBack(Rising_interrupt);
    CCP2_SetCallBack(Falling_interrupt);
    
    
    while (1)
    {
        // Add your application code
        if(65535 <= duty){
            
            flag = 1;
            
        }
        else if(0 >= duty){
            
            flag = 0;
            
        }
        
        if(flag == 0) duty++;
        if(flag == 1) duty--;
        
        PWM11_DutyCycleSet(duty);
        PWM11_LoadBufferSet();
        
        printf("\rduty:%u",duty);
        printf("width:%u",g_pulse_width);
        printf("r_pulse%u",g_rising_value);
        printf("f_pulse%u\n",g_falling_value);
        
    }
}
void Rising_interrupt(unsigned int rising_value){
    
    g_rising_value = rising_value;
    
}
void Falling_interrupt(unsigned int falling_value){
    
    g_falling_value = falling_value;
    
    if(g_rising_value > g_falling_value){
        
        //g_pulse_width = (65535 - g_falling_value) + g_rising_value;
        ;
    }
    else
        g_pulse_width = g_falling_value - g_rising_value;
    
}
void putch(char data){
    
    EUSART_Write(data);
    
}

/**
 End of File
*/