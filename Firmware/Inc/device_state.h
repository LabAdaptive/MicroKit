#ifndef DEV_STATE
#define DEV_STATE


#define STATE_RESERVED 0x00
#define STATE_GPIO 0x01
#define STATE_ADC  0x02
#define STATE_PWM  0x04
#define STATE_I2C  0x08
#define STATE_SPI  0x10
#define STATE_UART 0x20


/*struct holds state of a multi purpose min 
  as well as its capibilities */

typedef struct 
{
	uint8_t current_function;
 	uint8_t ext;
	uint8_t capibilties;
} PinFunctions;


/* Struct that holds device state info */

typedef struct 
{
	PinFunctions pins[64];

} DeviceState;


/* initialize device state struct */
uint8_t DeviceStateInit(DeviceState * d)
{	
    d->pins[0]->current_function = 0x00;
    d->pins[0]->ext              = 0x00;
    d->pins[0]->capibilities     = 0x00;

    d->pins[1]->current_function = 0x00;
    d->pins[1]->ext              = 0x00;
    d->pins[1]->capibilities     = 0x00;

    d->pins[2]->current_function = 0x00;
    d->pins[2]->ext              = 0x00;
    d->pins[2]->capibilities     = 0x00;

    d->pins[3]->current_function = 0x00;
    d->pins[3]->ext              = 0x00;
    d->pins[3]->capibilities     = 0x00;

    d->pins[4]->current_function = 0x00;
    d->pins[4]->ext              = 0x00;
    d->pins[4]->capibilities     = 0x00;

    d->pins[5]->current_function = 0x00;
    d->pins[5]->ext              = 0x00;
    d->pins[5]->capibilities     = 0x00;

    d->pins[6]->current_function = 0x00;
    d->pins[6]->ext              = 0x00;
    d->pins[6]->capibilities     = 0x00;

    d->pins[7]->current_function = 0x00;
    d->pins[7]->ext              = 0x00;
    d->pins[7]->capibilities     = 0x00;

    d->pins[8]->current_function = 0x00;
    d->pins[8]->ext              = 0x00;
    d->pins[8]->capibilities     = 0x00;

    d->pins[9]->current_function = 0x00;
    d->pins[9]->ext              = 0x00;
    d->pins[9]->capibilities     = 0x00;

    d->pins[10]->current_function = 0x00;
    d->pins[10]->ext              = 0x00;
    d->pins[10]->capibilities     = 0x00;

    d->pins[11]->current_function = 0x00;
    d->pins[11]->ext              = 0x00;
    d->pins[11]->capibilities     = 0x00;

    d->pins[12]->current_function = 0x00;
    d->pins[12]->ext              = 0x00;
    d->pins[12]->capibilities     = 0x00;

    d->pins[13]->current_function = 0x00;
    d->pins[13]->ext              = 0x00;
    d->pins[13]->capibilities     = 0x00;

    d->pins[14]->current_function = 0x00;
    d->pins[14]->ext              = 0x00;
    d->pins[14]->capibilities     = 0x00;

    d->pins[15]->current_function = 0x00;
    d->pins[15]->ext              = 0x00;
    d->pins[15]->capibilities     = 0x00;

    d->pins[16]->current_function = 0x00;
    d->pins[16]->ext              = 0x00;
    d->pins[16]->capibilities     = 0x00;

    d->pins[17]->current_function = 0x00;
    d->pins[17]->ext              = 0x00;
    d->pins[17]->capibilities     = 0x00;

    d->pins[18]->current_function = 0x00;
    d->pins[18]->ext              = 0x00;
    d->pins[18]->capibilities     = 0x00;

    d->pins[19]->current_function = 0x00;
    d->pins[19]->ext              = 0x00;
    d->pins[19]->capibilities     = 0x00;

    d->pins[20]->current_function = 0x00;
    d->pins[20]->ext              = 0x00;
    d->pins[20]->capibilities     = 0x00;

    d->pins[21]->current_function = 0x00;
    d->pins[21]->ext              = 0x00;
    d->pins[21]->capibilities     = 0x00;

    d->pins[22]->current_function = 0x00;
    d->pins[22]->ext              = 0x00;
    d->pins[22]->capibilities     = 0x00;

    d->pins[23]->current_function = 0x00;
    d->pins[23]->ext              = 0x00;
    d->pins[23]->capibilities     = 0x00;

    d->pins[24]->current_function = 0x00;
    d->pins[24]->ext              = 0x00;
    d->pins[24]->capibilities     = 0x00;

    d->pins[25]->current_function = 0x00;
    d->pins[25]->ext              = 0x00;
    d->pins[25]->capibilities     = 0x00;

    d->pins[26]->current_function = 0x00;
    d->pins[26]->ext              = 0x00;
    d->pins[26]->capibilities     = 0x00;

    d->pins[27]->current_function = 0x00;
    d->pins[27]->ext              = 0x00;
    d->pins[27]->capibilities     = 0x00;

    d->pins[28]->current_function = 0x00;
    d->pins[28]->ext              = 0x00;
    d->pins[28]->capibilities     = 0x00;

    d->pins[29]->current_function = 0x00;
    d->pins[29]->ext              = 0x00;
    d->pins[29]->capibilities     = 0x00;


}
}
#endif
