#include <Wire.h>
#include <WiiChuck.h>
#include "VirtualWire.h"
#include "packet.h"

WiiChuck chuck = WiiChuck();

void setup() {
	// set up wireless transmitter
	vw_set_ptt_inverted(true);
	vw_set_tx_pin(12);
	vw_setup(2000);

	// set up the nunchuck
	chuck.begin();
	chuck.update();
	//chuck.calibrateJoy();
    Serial.begin(115200);
}

// This is a struct containing all the values we'll transmit.
nunchuck_data buffer;

void loop() {
	// update from the nunchuck
	delay(20);
	chuck.update(); 

	// grab the values from the nunchuck into the buffer.
	buffer.joy_x = chuck.readJoyX();
	buffer.joy_y = chuck.readJoyY();
	buffer.roll = chuck.readRoll();
	buffer.pitch = chuck.readPitch();
	buffer.z_pressed = chuck.zPressed();
	buffer.c_pressed = chuck.cPressed();

	vw_send((uint8_t *) (&buffer), sizeof(nunchuck_data));
	vw_wait_tx();
}
