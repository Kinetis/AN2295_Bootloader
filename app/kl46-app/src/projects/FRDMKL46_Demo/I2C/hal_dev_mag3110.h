


//Registros del Magnetometro///
#define MAG_DR_STATUS 0x00
#define MAG_OUT_X_MSB 0x01
#define MAG_OUT_X_LSB 0x02
#define MAG_OUT_Y_MSB 0x03
#define MAG_OUT_Y_LSB 0x04
#define MAG_OUT_Z_MSB 0x05
#define MAG_OUT_Z_LSB 0x06
#define MAG_WHO_AM_I  0x07
#define MAG_SYSMOD    0x08
#define MAG_OFF_X_MSB 0x09
#define MAG_OFF_X_LSB 0x0A
#define MAG_OFF_Y_MSB 0x0B
#define MAG_OFF_Y_LSB 0x0C
#define MAG_OFF_Z_MSB 0x0D
#define MAG_OFF_Z_LSB 0x0E
#define MAG_DIE_TEMP  0x0F
#define MAG_CTRL_REG1 0x10
#define MAG_CTRL_REG2 0x11


void hal_dev_mag3110_init(void); //prepare I2C port
void mag_init(void);
uint8   hal_dev_mag3110_read_reg(uint8 addr);
void hal_dev_mag3110_write_reg(uint8 addr, uint8 data);
uint16 hal_dev_mag3110_test_reg_rw(void);
void hal_dev_mag3110_test_function(void);
int iMagReadX(void);
int iMagReadY(void);
int iMagReadZ(void);
