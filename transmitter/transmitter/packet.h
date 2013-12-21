#ifndef _CAR_PACKET_H_
#define _CAR_PACKET_H_

typedef struct nunchuck_data {
	int joy_x;
	int joy_y;
	int roll;
	int pitch;

	boolean z_pressed;
	boolean c_pressed;
} nunchuck_data;

#endif
