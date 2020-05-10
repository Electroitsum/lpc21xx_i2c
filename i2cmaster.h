#define AA 2
#define SI 3
#define STO 4
#define STA 5
#define I2EN 6
void wait(unsigned int delay)
{
while(delay--);
}
void i2c_begin(int hi, int lo ){
VPBDIV=0x02;                  
PINSEL0=1<<4|1<<6;
I2SCLH=hi;                            
I2SCLL=lo;
I2CONSET=1<<I2EN;

I2CONCLR=1<<3;
I2CONSET=1<<STA;
while(!(I2STAT==0x08));
}
void i2c_stop(void)                
{
 I2CONSET=(1<<STO);
}

void ads_write(unsigned char buffer){
I2CONSET|=1<<SI;
I2DAT=buffer;
wait(5000);
I2CONCLR=1<<SI;
wait(5000);
while(!(I2STAT==0x18));
}

void dat_write(unsigned char buffdata){
I2DAT=buffdata;
I2CONCLR=(1<<STA);
I2CONCLR=(1<<STO);
I2CONCLR=(1<<SI);
while(!(I2STAT==0x28));
}

void i2c_restart(void){
I2CONSET=1<<STA;
I2CONCLR=1<<SI;
while(!(I2STAT==0x08));

}

void i2c_end(void)                
{
 I2CONSET=(1<<STO);
 I2CONCLR=1<<I2EN;
}
