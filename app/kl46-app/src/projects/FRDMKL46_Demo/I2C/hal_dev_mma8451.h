

void hal_dev_mma8451_init(void); //prepare I2C port
uint8   hal_dev_mma8451_read_reg(uint8 addr);
void hal_dev_mma8451_write_reg(uint8 addr, uint8 data);
uint16 hal_dev_mma8451_test_reg_rw(void);
void hal_dev_mma8451_test_function(void);
extern void accel_init(void);
void accel_read(void);
void accel_test(void);
int iAcclReadX(void);
int iAcclReadY(void);
int iAcclReadZ(void);
