#include <stdio.h>
#include <stdarg.h>
#include "sam/sam3x/include/sam.h"
#include "time.h"
#include "uart.h"
#include "can.h"
#include "servoandPWM.h"



/*
 * Remember to update the Makefile with the (relative) path to the uart.c file.
 * This starter code will not compile until the UART file has been included in the Makefile. 
 * If you get somewhat cryptic errors referencing functions such as _sbrk, 
 * _close_r, _write_r, _fstat etc, you have most likely not done that correctly.

 * If you get errors such as "arm-none-eabi-gcc: no such file", you may need to reinstall the arm gcc packages using
 * apt or your favorite package manager.
 */
//#include "../path_to/uart.h"




int main()
{
    SystemInit();

    WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer

    //Uncomment after including uart above
    uart_init(84000000, 9600);
    can_init1();

    int i =0;
    printf("Hei");
    
    CanMsg m= {};
   
    CanMsg m2= {};

    while(1){

    can_rx1(&m);
    can_rx2(&m2);
    printf("\n\rMsgx : \n\r");
   can_printmsg(m);
   printf("\n\r");
   printf("Msgy : \n\r");
   can_printmsg(m2);

   printf("\n\r++++++++++++++++++++++++++++++++++++++++++++\n\r");
    for(int i = 0; i < 10000000; i++){}

}}


/*message_t message1 = make_message(1,1,"3");
    int a = get_message_data(message1);
    printf("a: %d\n", a);*/
/*
PMC->PMC_PCER0 |= (1<<ID_PIOB);

    PIOB->PIO_OER = PIO_PB13;
    PIOB->PIO_PER = PIO_PB13;

    PIOB->PIO_CODR = PIO_PB13;



    
    
    printf("\rThis is a test\n\r");
   while(1){
        PIOB->PIO_CODR = PIO_PB13;}*/





    /*
    PMC->PMC_PCER0 |= (1<<ID_PIOB);
    PIOB->PIO_OER = PIO_PB13;
    PIOB->PIO_PER = PIO_PB13;

    PIOB->PIO_CODR = PIO_PB13;

    

    
    
    printf("\rThis is a test\n\r");
   while(1){
    PIOB->PIO_CODR = PIO_PB13;
    for(int i =0; i< 1000000; i++){
        
    }
    PIOB->PIO_SODR = PIO_PB13;
    for(int i =0; i< 1000000; i++){
        
    }

        }*/