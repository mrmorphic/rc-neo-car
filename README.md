rc-neo-car
==========

This is a robotic experiment using an old RC car and fitting it out with new stuff.

The car has two servos that control speed and direction. As part of a previous project (rc-trick-car), an Arduino
was fitted to it to intercept values from the receiver and drive the servos. However, the old transmitter/receiver stopped
working reliably, so we determined it needed a better method of control.

The project is split into two Arduino projects:

 *	transmitter - this is the code for custom transmitter we built. It consists of an arduino readng values from a nintendo
 	nunchuck, and sending these to the car via a cheap 433MHz wireless transmitter. It is battery powered.
 *	car - this is the code for the car itself. It consists of the car, an arduino with a 433MHz receiver, and powered by a lipo.
 	Additional sensors may be added over time to give the car semi-autonomous behaviour.
