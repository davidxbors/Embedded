#include <avr/io.h>
#include <util/delay.h>

#define DELAY 1000

int main(void){
  // pd7 is output
  DDRD = _BV(PD7);

  while(1){
    // set pd7 on digital high
    PORTD |= _BV(PD7);
    _delay_ms(DELAY);
   
    // set pd7 on digital low
    PORTD &= ~_BV(PD7);
    _delay_ms(DELAY);
  }
}
