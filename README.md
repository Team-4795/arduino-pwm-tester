# arduino-pwm-tester
servo-PWM generator with keypad, LCD, and potentiometers using arduino



Arduino hardware hookup

PWM output:
  pin 15 PB1/OC1A - arduino 9 -  pwm out 1
  pin 16 PB2/OC1B - arduino 10 - pwm out 2

other digital outputs:
  PD2  arduino 2       PD2 software serial to LCD display
  PB5 arduino 13  - LED connected on most Arduino boards.  blinks heartbeat

analog inputs:
  analog 0 - potentiometer input for pwm 1
  analog 1 - potentiometer input for pwm 2
  analog 2 - additional analog input displayed on LCD for sensor testing

keypad: 5 keys on port D.

PD7    Up
PD6    Down
PD5    Enter
PD4    Right
PD3    Left





