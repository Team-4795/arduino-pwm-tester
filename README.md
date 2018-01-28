
A servo-PWM generator with keypad, LCD, and potentiometers using arduino

# Arduino hardware hookup

##PWM output:
-  pin 15 PB1/OC1A - arduino 9 -  pwm output 1
-  pin 16 PB2/OC1B - arduino 10 - pwm output 2

##other digital outputs:
-  PD2  arduino 2   - software serial to LCD display
-  PB5  arduino 13  - LED connected on most Arduino boards.  blinks heartbeat

##analog inputs:
-  pin 23 PC0/ADC0 (analog 0) - potentiometer for pwm 1.  Leftmost slider pot.
-  pin 24 PC1/ADC1 (analog 1) - potentiometer for pwm 2.  Rightmost slider pot.
-  pin 26 PC2/ADC2 (analog 2 - additional analog input displayed on LCD for sensor testing

# keypad: 5 keys on port D.
Each key is a pushbutton switch that connects to ground when pressed.
optional series diodes could allow multiplexing, but we don't take advantage
of that.

- pin 13 PD7    "Up"   key
- pin 12 PD6    "Down" 
- pin 11 PD5    "Enter"
- pin 6  PD4    "Right"
- pin 5  PD3    "Left"


# Operation:

At poweron, or reset, both PWM outputs are centered (1500us).  This
commands connected motor controllers to "stop", or servos to center
position.  While in this centered mode, the input sliders are ignored.
Check the motor controllers' LEDs to make sure they are receiving the
PWM signal.  Most of them, including talon SR and talon SRX indicate:
- OFF - no power.  check power to controller.
- solid orange - power ON, PWM connected and signalling "stop":
- blinking orange - power ON, PWM not connected or disabled
	

To change from the PWM centered mode, use the keypad.

# Keypad operation:

The 5-key keypad changes operating modes.  The key functions are:

- LEFT, RIGHT: select a setting to change.
- UP, DOWN: change the displayed setting.
- CENTER:  no function

use the Left and Right keys to select a setting.  The currently
selected setting is displayed on the screen.  Available settings are:

- 1mode: mode for PWM 1.  choices are "center" or "variable"
	 	change to variable to enable the PWM output to be controlled
		by the slide potentiometer

-	1max: maximum pulse with for PWM 1.  Default is 2000 microseconds.
-	1min: minimum pulse width for PWM 1.  Default 1000 microseconds.
		changing these will limit or extend the position range
		available for a servo, or limit the maximum speed of a motor
		controller.

-	 2mode, 2max, 2min: similar to above, but affecting PWM 2


# Atmega328 coding notes:

Our two PWM outputs use Timer 1 and its 16-bit output-compare registers.



# Future enhancements

- Clearly ask user to center potentiometers and then press a key before proceeding to normal operation without needing to step through the mode menus.

- Use the center key for an emergency-stop function, that sets PWMs to center and asks user to re-center.

- move the AD2 display to a seperate screen.

- Support selecting between multiple different types of testing
  screens, of which PWM and analog-input are just two.

