

#include "common.h"
#include "hal_i2c.h"
#include "hal_dev_mma8451.h"

//Variables acelerometro///
signed short accel_x, accel_y, accel_z;
signed short Aresultx, Aresulty, Aresultz;
char aux1;
int Atestx,Atesty,Atestz;

#define MMA8451_I2C_ADDRESS (0x1d<<1)
#define I2C0_B  I2C0_BASE_PTR

//I2C0 es usado por el acelerometro

void hal_dev_mma8451_init(void)
{
  hal_i2c0_init(I2C0_B);
}

// this delay is very important, it may cause w-r operation failure.
static void pause(void)
{
    int n;
    for(n=0; n<40; n++)
        asm("nop");
}
uint8 hal_dev_mma8451_read_reg(uint8 addr)
{
    uint8 result;

    i2c_start(I2C0_B);
    i2c_write_byte(I2C0_B, MMA8451_I2C_ADDRESS | I2C_WRITE);
    
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, addr);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_repeated_start(I2C0_B);
    i2c_write_byte(I2C0_B, MMA8451_I2C_ADDRESS | I2C_READ);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_set_rx_mode(I2C0_B);

    i2c_give_nack(I2C0_B);
    result = i2c_read_byte(I2C0_B);
    i2c_wait(I2C0_B);

    i2c_stop(I2C0_B);
    result = i2c_read_byte(I2C0_B);
    pause();
    return result;
}
void hal_dev_mma8451_write_reg(uint8 addr, uint8 data)
{
    i2c_start(I2C0_B);

    i2c_write_byte(I2C0_B, MMA8451_I2C_ADDRESS|I2C_WRITE);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, addr);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_write_byte(I2C0_B, data);
    i2c_wait(I2C0_B);
    i2c_get_ack(I2C0_B);

    i2c_stop(I2C0_B);
    pause();
}

///****Funciones del Acelerometro******//
void accel_init(void)
{
    unsigned char tmp;
    hal_dev_mma8451_init();      //Initialize I2C modules
    tmp = hal_dev_mma8451_read_reg(0x2a);
    hal_dev_mma8451_write_reg(0x2a,tmp|0x01);
}

void accel_read(void)
{
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
        accel_x   = hal_dev_mma8451_read_reg(0x01)<<8;
        accel_x  |= hal_dev_mma8451_read_reg(0x02);
        accel_x >>= 2;

        accel_y   = hal_dev_mma8451_read_reg(0x03)<<8;
        accel_y  |= hal_dev_mma8451_read_reg(0x04);
        accel_y >>= 2;

        accel_z   = hal_dev_mma8451_read_reg(0x05)<<8;
        accel_z  |= hal_dev_mma8451_read_reg(0x06);
        accel_z >>= 2;

        Aresultx   = hal_dev_mma8451_read_reg(0x01)<<8;
        Aresultx  |= hal_dev_mma8451_read_reg(0x02);
        Aresultx >>= 8;

        Aresulty   = hal_dev_mma8451_read_reg(0x03)<<8;
        Aresulty  |= hal_dev_mma8451_read_reg(0x04);
        Aresulty >>= 8;

        Aresultz   = hal_dev_mma8451_read_reg(0x05)<<8;
        Aresultz  |= hal_dev_mma8451_read_reg(0x06);
        Aresultz >>= 8;

    }
}

void accel_test(void)
{
 accel_read();
 Atestx = Aresultx;
 Atesty = Aresulty;
 Atestz = Aresultz;

 printf("\n\r Acelerometer Values");
 printf("\n\rx = %d \t",Atestx);
 printf("y = %d \t",Atesty);
 printf("z = %d \n\r",Atestz);
  
}

int iAcclReadX(void) {
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
        accel_x   = hal_dev_mma8451_read_reg(0x01)<<8;
        accel_x  |= hal_dev_mma8451_read_reg(0x02);
        accel_x >>= 2;
      
        Aresultx   = hal_dev_mma8451_read_reg(0x01)<<8;
        Aresultx  |= hal_dev_mma8451_read_reg(0x02);
        Aresultx >>= 8;
    }
    return Aresultx;
}

int iAcclReadY(void) {
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
        accel_y   = hal_dev_mma8451_read_reg(0x03)<<8;
        accel_y  |= hal_dev_mma8451_read_reg(0x04);
        accel_y >>= 2;
        
        Aresulty   = hal_dev_mma8451_read_reg(0x03)<<8;
        Aresulty  |= hal_dev_mma8451_read_reg(0x04);
        Aresulty >>= 8;
    }
    return Aresulty;
}

int iAcclReadZ(void) {
    if((hal_dev_mma8451_read_reg(0x00)&0xf) != 0)
    {
        accel_z   = hal_dev_mma8451_read_reg(0x05)<<8;
        accel_z  |= hal_dev_mma8451_read_reg(0x06);
        accel_z >>= 2;

        Aresultz   = hal_dev_mma8451_read_reg(0x05)<<8;
        Aresultz  |= hal_dev_mma8451_read_reg(0x06);
        Aresultz >>= 8;   
    }
    return Aresultz;
}
