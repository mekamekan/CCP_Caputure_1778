/**
  PWM11 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm11.c

  @Summary
    This is the generated driver implementation file for the PWM11 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM11.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm11.h"

/**
  Section: PWM11 APIs
*/

void PWM11_Initialize(void)
{
    // set the PWM11 to the options selected in the User Interface

     //PHIE disabled; DCIE disabled; OFIE disabled; PRIE disabled; 
    PWM11INTE = 0x00;

     //PHIF cleared; OFIF cleared; DCIF cleared; PRIF cleared; 
    PWM11INTF = 0x00;

     //PS Divide_clock_src_by_2; CS FOSC; 
    PWM11CLKCON = 0x10;

     //LDS LD5_trigger; LDT disabled; LDA do_not_load; 
    PWM11LDCON = 0x00;

     //OFM independent_run; OFS OF5_match; OFO match_incrementing; 
    PWM11OFCON = 0x00;

     //PWM11PHH 0; 
    PWM11PHH = 0x00;

     //PWM11PHL 0; 
    PWM11PHL = 0x00;

     //PWM11DCH 0; 
    PWM11DCH = 0x00;

     //PWM11DCL 0; 
    PWM11DCL = 0x00;

     //PWM11PRH 255; 
    PWM11PRH = 0xFF;

     //PWM11PRL 255; 
    PWM11PRL = 0xFF;

     //PWM11OFH 0; 
    PWM11OFH = 0x00;

     //PWM11OFL 31; 
    PWM11OFL = 0x1F;

     //PWM11TMRH 0; 
    PWM11TMRH = 0x00;

     //PWM11TMRL 0; 
    PWM11TMRL = 0x00;

     //MODE standard_PWM; POL active_hi; EN enabled; 
    PWM11CON = 0x80;

}    


void PWM11_Start(void)
{
    PWM11CONbits.EN = 1;		
}

void PWM11_Stop(void)
{
    PWM11CONbits.EN = 0;		
}

bool PWM11_CheckOutputStatus(void)
{
    return (PWM11CONbits.OUT);		
}

void PWM11_LoadBufferSet(void)
{
    PWM11LDCONbits.LDA = 1;		
}

void PWM11_PhaseSet(uint16_t phaseCount)
{
    PWM11PHH = (phaseCount>>8);        //writing 8 MSBs to PWMPHH register
    PWM11PHL = (phaseCount);           //writing 8 LSBs to PWMPHL register
}

void PWM11_DutyCycleSet(uint16_t dutyCycleCount)
{
    PWM11DCH = (dutyCycleCount>>8);	//writing 8 MSBs to PWMDCH register
    PWM11DCL = (dutyCycleCount);	//writing 8 LSBs to PWMDCL register		
}

void PWM11_PeriodSet(uint16_t periodCount)
{
    PWM11PRH = (periodCount>>8);	//writing 8 MSBs to PWMPRH register
    PWM11PRL = (periodCount);	//writing 8 LSBs to PWMPRL register		
}

void PWM11_OffsetSet(uint16_t offsetCount)
{
    PWM11OFH = (offsetCount>>8);	//writing 8 MSBs to PWMOFH register
    PWM11OFL = (offsetCount);	//writing 8 LSBs to PWMOFL register		
}

uint16_t PWM11_TimerCountGet(void)
{
    return ((uint16_t)((PWM11TMRH<<8) | PWM11TMRL));       		
}

bool PWM11_IsOffsetMatchOccured(void)
{
    return (PWM11INTFbits.OFIF);		
}

bool PWM11_IsPhaseMatchOccured(void)
{
    return (PWM11INTFbits.PHIF);	
}

bool PWM11_IsDutyCycleMatchOccured(void)
{
    return (PWM11INTFbits.DCIF);		
}

bool PWM11_IsPeriodMatchOccured(void)
{
    return (PWM11INTFbits.PRIF);		
}

/**
 End of File
*/


