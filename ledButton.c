#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* /brief inits the button and the les
 * /params no params
 */
void init_io(){
  //led13
  DDRB  |= _BV(DDB0); //anlog0
  PORTB |= _BV(PORTB0); //initial state is off

  //button
  DDRB &= ~_BV(DDB4);    //set portb4 as input aka  digital pin 12
  PORTB |= _BV(PORTB4);  //enable internal pull-up
}

/* \brief toggles led state
 * \params no params
 */
void toggle_led(){
  PORTB ^= _BV(PORTB0); //toggle led's state
}

/* \brief tells if the button is pressed or not
 * \params no params
 */
int is_button_pressed(){
  if(bit_is_clear(PINB, PINB4)){
    _delay_ms(25);
    if(bit_is_set(PINB, PINB4)) return 1;
  }
  return 0;
}

int main(void){
  init_io();
  while(1){
    if(is_button_pressed())
      toggle_led();
  }
}
