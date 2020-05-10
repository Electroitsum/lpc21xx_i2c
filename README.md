# lpc21xx_i2c
I2C driver for NXP LPC2148(ARM-7)
This is a simple I2C driver header file for NXP LPC2148. you can use following functions for communication;-
i2c_begin(high value, low value)------------ This function can be used for the initializing the I2C communication. This function requires two arguments high and low which are nothing but the values of the clock register which will define the speed of communication, for example, you can put 100 for both which will set 300KHz speed.ex- i2c_begin(100 , 100);
ads_write(address of the slave)--------------This function takes slave address as argument an set the communication target(slave); for example- ads_write(0x20);
dat_write(data to be transmitted)------------By using this function we can transmit the data to particular a slave address. It takes data as argument for example- dat_write(0xff);
i2c_restart()------------ this function is used for restarting the communication and requires slave address again so after using this function specify address by using ads_write function. for ex- i2c_restart();
i2c_stop()------------ This function simply stop the communication with a specified slave. for ex- i2c_stop();
i2c_end()-------------- By using this function you can end the I2C communication and after this, you can't communicate to any I2C device. if you want to communicate again you have to use i2c_begin again. 
