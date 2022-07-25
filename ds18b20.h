/*
* ds18b20.h
*
* Created: 24.07.2022 16:53:12
*  Author: Clemens Hauser
*/


#ifndef DS18B20_H_
#define DS18B20_H_

#define F_CPU 8000000				//MODIFY TO YOUR CLOCK! IMPORTANT!

#define WIRE		PB0				//Pin One-Wire is connected to
#define WIRE_DDR	DDRB
#define WIRE_PORT	PORTB
#define WIRE_PIN	PINB

//ROM commands

#define ROMSEARCH	0xF0
#define ROMREAD		0x33
#define ROMMATCH	0x55
#define ROMSKIP		0xCC
#define ALARMSEARCH 0xEC

//Function commands

#define TCONVERT		0x44
#define SCRATCHPADWRITE 0x4E
#define SCRATCHPADREAD	0xBE
#define SCRATCHPADCOPY	0x48
#define RECALLE			0xB8
#define READPOWER		0xB4

//TIMINGS in us

#define DELAY_RESET			500
#define TIMESLOT_DUR		70
#define ONE_DUR				10
#define ZERO_DUR			70



void bus_init();

void bus_write_bit(char bit);
void bus_write_byte(char byte);

uint8_t bus_read_bit();
uint8_t bus_read_byte();

void req_temperature();
int32_t get_temperature();				//returns temperature in deg x 10,
										//returns 0xFFFF if conversion is in progress

#endif /* DS18B20_H_ */