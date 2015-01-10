

#include "common.h"
#include "hal_i2c.h"
#include "hal_dev_mag3110.h"

#define MAG3110_I2C_ADDRESS (0x0E<<1)
#ifdef FRDM_REVA
#define I2C_MAG  I2C1_BASE_PTR
#else
#define I2C_MAG  I2C0_BASE_PTR
#endif



//Variables magnetómetro///
signed short mag_x, mag_y, mag_z;
signed short Mresultx, Mresulty, Mresultz;
int Mtestx,Mtesty,Mtestz;

//I2C1 es usado por el magnetómetro
void hal_dev_mag3110_init(void)
{
#ifdef FRDM_REVA
  hal_i2c1_init(I2C_MAG);   //I2C1 is used in REVA
#endif
  
}

// this delay is very important, it may cause w-r operation failure.
static void pause(void)
{
    int n;
    for(n=0; n<40; n++)
        asm("nop");
}
uint8 hal_dev_mag3110_read_reg(uint8 addr)
{
    uint8 result;

    i2c_start(I2C_MAG);
    i2c_write_byte(I2C_MAG, MAG3110_I2C_ADDRESS | I2C_WRITE);
    
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_write_byte(I2C_MAG, addr);
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_repeated_start(I2C_MAG);
    i2c_write_byte(I2C_MAG, MAG3110_I2C_ADDRESS | I2C_READ);
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_set_rx_mode(I2C_MAG);

    i2c_give_nack(I2C_MAG);
    result = i2c_read_byte(I2C_MAG);
    i2c_wait(I2C_MAG);

    i2c_stop(I2C_MAG);
    result = i2c_read_byte(I2C_MAG);
    pause();
    return result;
}

void hal_dev_mag3110_write_reg(uint8 addr, uint8 data)
{
    i2c_start(I2C_MAG);

    i2c_write_byte(I2C_MAG, MAG3110_I2C_ADDRESS|I2C_WRITE);
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_write_byte(I2C_MAG, addr);
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_write_byte(I2C_MAG, data);
    i2c_wait(I2C_MAG);
    i2c_get_ack(I2C_MAG);

    i2c_stop(I2C_MAG);
    pause();
}

/******Funciones del Magnetómetro*********/
void mag_init(void)
{
    hal_dev_mag3110_init();      //Initialize I2C modules
    hal_dev_mag3110_write_reg(MAG_CTRL_REG1,0x00); //Standby mode
    hal_dev_mag3110_write_reg(MAG_CTRL_REG2,0x80); //Auto reset
    hal_dev_mag3110_write_reg(MAG_CTRL_REG1,0x01); //Active
}

void mag_read(void)
{
    if((hal_dev_mag3110_read_reg(0x00)&0xf) != 0)
    {
            
      mag_x   = hal_dev_mag3110_read_reg(0x01)<<8;
      mag_x  |= hal_dev_mag3110_read_reg(0x02);

      mag_y   = hal_dev_mag3110_read_reg(0x03)<<8;
      mag_y  |= hal_dev_mag3110_read_reg(0x04);

      mag_z   = hal_dev_mag3110_read_reg(0x05)<<8;
      mag_z  |= hal_dev_mag3110_read_reg(0x06);
  
      Mresultx   = hal_dev_mag3110_read_reg(0x01)<<8;
      Mresultx  |= hal_dev_mag3110_read_reg(0x02);
      
      Mresulty   = hal_dev_mag3110_read_reg(0x03)<<8;
      Mresulty  |= hal_dev_mag3110_read_reg(0x04);

      Mresultz   = hal_dev_mag3110_read_reg(0x05)<<8;
      Mresultz  |= hal_dev_mag3110_read_reg(0x06);
    }
}

void mag_test(void)
{
 mag_read();
 Mtestx = Mresultx;
 Mtesty = Mresulty;
 Mtestz = Mresultz;

 printf("\n\r Magenotometer Values");
 printf("\n\rx = %d \t",Mtestx);
 printf("y = %d \t",Mtesty);
 printf("z = %d \n\r",Mtestz);
  
}

int iMagReadX(void) {
   if((hal_dev_mag3110_read_reg(0x00)&0xf) != 0)
    {
      mag_x   = hal_dev_mag3110_read_reg(0x01)<<8;
      mag_x  |= hal_dev_mag3110_read_reg(0x02);
      
      Mresultx   = hal_dev_mag3110_read_reg(0x01)<<8;
      Mresultx  |= hal_dev_mag3110_read_reg(0x02);
    }
    return Mresultx;
}

int iMagReadY(void) {
     if((hal_dev_mag3110_read_reg(0x00)&0xf) != 0)
    {
      mag_y   = hal_dev_mag3110_read_reg(0x03)<<8;
      mag_y  |= hal_dev_mag3110_read_reg(0x04);

      Mresulty   = hal_dev_mag3110_read_reg(0x03)<<8;
      Mresulty  |= hal_dev_mag3110_read_reg(0x04);      
    }
    return Mresulty;
}

int iMagReadZ(void) {
       if((hal_dev_mag3110_read_reg(0x00)&0xf) != 0)
    {
      mag_z   = hal_dev_mag3110_read_reg(0x05)<<8;
      mag_z  |= hal_dev_mag3110_read_reg(0x06);

      Mresultz   = hal_dev_mag3110_read_reg(0x05)<<8;
      Mresultz  |= hal_dev_mag3110_read_reg(0x06);
    }
    return Mresultz;
}



