void i2cRead( uint8_t i2c, uint8_t address, uint8_t* buffer, uint16_t bufferSize, int writeStop, uint8_t* lectura, uint16_t tamanio, int readStop );

void i2cWrite(uint8_t i2c,uint8_t address, uint8_t* dato, uint16_t tamanio, int );