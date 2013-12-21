#include "Arduino.h"
#include <VirtualWire.h>
#include "ServoTimer2.h"
#include "packet.h"

#define STEERING_SERVO_PIN  2

// @todo verify these numbers more accurately.
#define STEERING_ANGLE_HARD_LEFT   900
#define STEERING_ANGLE_STRAIGHT    1351
#define STEERING_ANGLE_HARD_RIGHT  1700

ServoTimer2 frontSteering;

void set_angle(int a);

void setup()
{
	// Set up VirtualWire to read receiver
	vw_set_ptt_inverted(true); // Required for DR3100
	vw_set_rx_pin(9);
	vw_setup(2000);  // Bits per sec

	pinMode(13, OUTPUT);

	vw_rx_start();       // Start the receiver PLL running
	Serial.begin(115200);

	frontSteering.attach(STEERING_SERVO_PIN);
}

// buffer where we read nunchuck data
nunchuck_data buffer;

void loop() {
	uint8_t bytes_read;

	if (vw_get_message((uint8_t *) (&buffer), &bytes_read)) // Non-blocking
	{
  /*
		Serial.print("joy_x:");
		Serial.print(buffer.joy_x);
		Serial.print("    joy_y:");
		Serial.print(buffer.joy_y);
		Serial.print("   roll:");
		Serial.print(buffer.roll);
		Serial.print("   pitch:");
		Serial.print(buffer.pitch);
		Serial.print("   z:");
		Serial.print(buffer.z_pressed);
		Serial.print("   c:");
		Serial.println(buffer.c_pressed);
*/
		int angle = map(buffer.joy_x, -124, 131, STEERING_ANGLE_HARD_LEFT, STEERING_ANGLE_HARD_RIGHT);
		set_angle(angle);
	}

}

void set_angle(int a) {
	frontSteering.write(a); 
	delay(15); 
}
