#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

#define BUTTON_PORT PORTD // register for button output
#define BUTTON_PIN  PIND   // register for button input
#define BUTTON_BIT  PD2   // bit for button; digital pin 2
#define LED_PORT    PORTC // register for led output
#define LED_BIT     PC0   // bit for led; analog input 0
#define TOGGLED_TIME 1000 // time for led to stay in the toggled state
#define DEBOUNCE_TIME 250 // time to press the button to consider it pressed
#define LED_DDR     DDRC

void init_io();
int button_is_pressed();
void toggle_led();

int main(void)
{
  init_io();
  while(1)
    {
      if(button_is_pressed())
	{
	  toggle_led();
	  _delay_ms(TOGGLED_TIME);
	}
    }
}

/* brief
   initializes the led and buttons i/o
 */
void init_io(){
  //set led pin as digital output
  LED_DDR = _BV(LED_BIT);
  //led's initial state is off
  LED_PORT &= ~_BV(LED_BIT);
  //turn on internal pull-up resistor for the switch
  BUTTON_PORT |= _BV(BUTTON_BIT); //WROOONG
}

/* brief
   checks if button is pressed
   returns 1 if it is pressed
   returns 0 otherwise
 */
int button_is_pressed(){
  if(bit_is_clear(BUTTON_PIN, BUTTON_BIT))
    {
      _delay_ms(DEBOUNCE_TIME);
      if(bit_is_clear(BUTTON_PIN, BUTTON_BIT)) return 1;
    }
  return 0;
}

/* brief
   toggles the led's state
 */
void toggle_led(){
  LED_PORT ^= _BV(LED_BIT);
}
