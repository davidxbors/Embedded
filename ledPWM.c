/*
  diming a led using a PWM
  the dim value is chosen by the computer
 */
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#define BVV(bit, val) ((val)?_BV(bit):0)

/* transfering oc to OCRA, which responsible for setting the duty cycle 
   on the led
*/ 
static void pwm_set_duty_cycle(uint8_t oc){
  OCR0A = oc;
}

// setup the pin6 as a pwm output pin
static void pwm_init(uint8_t oc){
  DDRD |= _BV(DDD6); //pin6 of portd
  TCCR0A =
    BVV(WGM00, 1) | BVV(WGM01, 1) /* fast pwm update on OCRA */
    | BVV(COM0A1, 1) | BVV(COM0A0, 0) /* non-inverting OC0A */
    | BVV(COM0B1, 0) | BVV(COM0B0, 0); // OC0B not connected
  pwm_set_duty_cycle(oc);
  TCCR0B =
    BVV(CS00, 1) | BVV(CS01, 0) | BVV(CS02, 1) /* F_CPU/1024 */
    | BVV(WGM02, 0) /* fast pwm update on ocra */
    | BVV(FOC0A, 0) | BVV(FOC0B, 0); //ignored
}

int main(void){
  pwm_init(0);

  while(1){
    pwm_set_duty_cycle(0);
    for(uint8_t i = 0; i < 101; i+=10){
      pwm_set_duty_cycle(i);
      _delay_ms(500);
    }
  }
}


