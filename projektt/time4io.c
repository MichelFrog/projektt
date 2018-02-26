#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw(void){
    int sw= ((PORTD & 0xf00)>> 8);
    return  sw;
}
int getbtns (void){                //NEW 0001 1110 0000 (5 BTN4,6 BTN3,7 BTN2, 8 BTN1)
    int btn= ((PORTD & 0x1e0)>> 5);// OLD 1110 0000 (5,6,7)
    return btn;
}
