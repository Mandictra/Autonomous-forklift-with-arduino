# **Arduino Uno Motor Control with PS3 Controller and HC-05 Bluetooth Module**
This project demonstrates how to control DC motors and an RC car using a PS3 controller connected to an Arduino Uno through an HC-05 Bluetooth module. The code enables bidirectional communication between the Arduino and the HC-05 module while controlling motor directions and speeds based on PS3 controller inputs.
## Components Needed
•	Arduino Uno
•	HC-05 Bluetooth module
•	PS3 controller
•	Motor driver (if required)
•	DC motors
•	Jumper wires
•	Breadboard
•	USB cable for Arduino
### Wiring Connections
HC-05 Bluetooth Module
•	VCC to 5V on Arduino
•	GND to GND on Arduino
•	TXD to RX (Pin 0) on Arduino
•	RXD to TX (Pin 1) on Arduino
Motor Connections
•	Enable Right Motor to PWM-capable Pin 3
•	Right Motor Pin 1 to Digital Pin 4
•	Right Motor Pin 2 to Digital Pin 6
•	Enable Left Motor to PWM-capable Pin 5
•	Left Motor Pin 1 to Digital Pin 7
•	Left Motor Pin 2 to Digital Pin 8
•	DC Motor Pin 1 to Digital Pin 9
•	DC Motor Pin 2 to Digital Pin 10
#### Code Explanation
Constants
•	MAX_MOTOR_SPEED: Defines the maximum speed for the motors (0 to 255).
•	SoftwareSerial BTSerial(0, 1): Initializes serial communication with the HC-05 module on pins 0 (RX) and 1 (TX).
Functions
•	notify(): Handles motor control based on PS3 controller inputs.
o	rotateDCMotor(true): Moves the DC motor forward.
o	rotateDCMotor(false): Moves the DC motor backward.
o	rotateMotor(speed1, speed2): Controls the RC car movement.
•	onConnect(): Callback when the PS3 controller connects.
•	onDisconnect(): Callback when the PS3 controller disconnects.
•	rotateDCMotor(direction): Sets the direction of the DC motor.
•	stopDCMotor(): Stops the DC motor.
•	rotateMotor(rightMotorSpeed, leftMotorSpeed): Controls the speed and direction of the right and left motors.
Setup
•	setUpPinModes(): Initializes the pin modes for motor control.
•	setup(): Configures the serial communications, PS3 controller callbacks, and initializes motors.
Loop
•	loop(): Handles data transmission between the HC-05 module and the Serial Monitor for AT command configuration and general Bluetooth communication.
##### Getting Started
1.	Connect the Hardware: Make the necessary connections as described in the wiring section.
2.	Upload the Code: Upload the provided code to your Arduino Uno.
3.	Configure HC-05: Open the Serial Monitor and set the baud rate to 9600. You can now send AT commands to configure the HC-05 module if needed.
4.	Pair the PS3 Controller: Ensure your PS3 controller is paired with the HC-05 module.
5.	Control the Motors: Use the PS3 controller to control the motors as per the provided logic in the notify() function.
AT Commands for HC-05 Configuration
•	Enter AT mode by holding the button on the HC-05 module while powering it up.
•	AT: Check communication.
•	AT+ROLE=0: Set HC-05 as a slave.
•	AT+PSWD="1234": Set the pairing password.
•	AT+UART=9600,0,0: Set baud rate to 9600.
Example Usage
1.	Forward Movement: Press the L2 button on the PS3 controller.
2.	Backward Movement: Press the R2 button on the PS3 controller.
3.	Turn Left: Press the left directional button.
4.	Turn Right: Press the right directional button.
5.	DC Motor Control: Use the up and down buttons to control the DC motor direction.
##### Troubleshooting
•	No Response from HC-05: Check the wiring and ensure the baud rate is correctly set.
•	PS3 Controller Not Connecting: Ensure the controller is paired and the HC-05 is in the correct mode.
•	Motor Not Moving: Verify power connections and ensure the motor driver is functioning.

