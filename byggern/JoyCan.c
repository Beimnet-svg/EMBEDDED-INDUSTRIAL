#include "JoyCan.h"
#include <util/delay.h>


void SendJoyPos(volatile char *adc, uint8_t x_start, uint8_t y_start){
    volatile uint8_t joyx = get_joystick_x(adc, x_start, y_start);
    volatile uint8_t joyy = get_joystick_y(adc, x_start, y_start);
    char joy1x[1];
    char joy2y[1];
    joy1x[0] = (char)joyx;
    joy2y[0] = (char)joyy;
    //printf("%d number1\r\n",joy1x[0]);
    volatile message_t messagex = make_message(1,1,joy1x);
    volatile message_t messagey = make_message(2,1,joy2y);
    //message_print(messagex);
    can_write(&messagex); 
    _delay_ms(10);
    can_write(&messagey);
}
