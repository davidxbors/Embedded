#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void){
  // set pin5 of portb for output -> Led13
  DDRB |= _BV(DDB5);

  while(1){
    //set pin5 on high
    PORTB |= _BV(PORTB5);
    _delay_ms(BLINK_DELAY_MS);
    
    //set pin5 on low
    PORTB &= ~_BV(PORTB5);
    _delay_ms(BLINK_DELAY_MS);
  }
}
