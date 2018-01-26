
/*
assumes 16 mhz cpu clock
*/
void
hwservo_init()
{ 
// set up 2 PWM channels on PB1 and PB2 using Timer1 

  TCCR1A = 0;     // disable all PWM on Timer1 whilst we set it up 
  ICR1 = 39999;   // TOP: frequency is every 20ms

  // Configure timer 1 for WGM=1110 (Fast PWM mode) via ICR1, prescale=8
  TCCR1A = (1 << WGM11)
  TCCR1B = (1 << WGM13) | (1<<WGM12) | (1 << CS11);
                 
  // Set PB1 and PB2 as outputs
  DDRB |= _BV(1) |  _BV(2);
  // COM1x = 0b10: clear on match, set at BOTTOM
  TCCR1A |= 2 <<  6;  // enable PWM on port B1 in non-inverted compare mode 2
  TCCR1A |= 2 <<  4;  // enable PWM on port B2 in non-inverted compare mode 2 

  // initialize to 1.5ms pulse  
  OCR1A = 3000; // ICR1 * 1.5 / 20;
  OCR1B = 3000; // ICR1 * 1.5 / 20;
  
  // other pulse widths:
  // 2000: 1ms   "0 degrees"
  // 4000: 2ms	"180 degrees"

}

