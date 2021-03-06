/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_I2C_H
#define _MOCK_I2C_H

#include "unity.h"
#include "i2c.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_i2c_Init(void);
void mock_i2c_Destroy(void);
void mock_i2c_Verify(void);




#define i2cRead_Ignore() i2cRead_CMockIgnore()
void i2cRead_CMockIgnore(void);
#define i2cRead_Expect(i2c, address, buffer, bufferSize, writeStop, lectura, tamanio, readStop) i2cRead_CMockExpect(__LINE__, i2c, address, buffer, bufferSize, writeStop, lectura, tamanio, readStop)
void i2cRead_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t i2c, uint8_t address, uint8_t* buffer, uint16_t bufferSize, int writeStop, uint8_t* lectura, uint16_t tamanio, int readStop);
typedef void (* CMOCK_i2cRead_CALLBACK)(uint8_t i2c, uint8_t address, uint8_t* buffer, uint16_t bufferSize, int writeStop, uint8_t* lectura, uint16_t tamanio, int readStop, int cmock_num_calls);
void i2cRead_AddCallback(CMOCK_i2cRead_CALLBACK Callback);
void i2cRead_Stub(CMOCK_i2cRead_CALLBACK Callback);
#define i2cRead_StubWithCallback i2cRead_Stub
#define i2cRead_ReturnThruPtr_buffer(buffer) i2cRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, sizeof(uint8_t))
#define i2cRead_ReturnArrayThruPtr_buffer(buffer, cmock_len) i2cRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, (int)(cmock_len * (int)sizeof(*buffer)))
#define i2cRead_ReturnMemThruPtr_buffer(buffer, cmock_size) i2cRead_CMockReturnMemThruPtr_buffer(__LINE__, buffer, cmock_size)
void i2cRead_CMockReturnMemThruPtr_buffer(UNITY_LINE_TYPE cmock_line, uint8_t* buffer, int cmock_size);
#define i2cRead_ReturnThruPtr_lectura(lectura) i2cRead_CMockReturnMemThruPtr_lectura(__LINE__, lectura, sizeof(uint8_t))
#define i2cRead_ReturnArrayThruPtr_lectura(lectura, cmock_len) i2cRead_CMockReturnMemThruPtr_lectura(__LINE__, lectura, (int)(cmock_len * (int)sizeof(*lectura)))
#define i2cRead_ReturnMemThruPtr_lectura(lectura, cmock_size) i2cRead_CMockReturnMemThruPtr_lectura(__LINE__, lectura, cmock_size)
void i2cRead_CMockReturnMemThruPtr_lectura(UNITY_LINE_TYPE cmock_line, uint8_t* lectura, int cmock_size);
#define i2cWrite_Ignore() i2cWrite_CMockIgnore()
void i2cWrite_CMockIgnore(void);
#define i2cWrite_Expect(i2c, address, dato, tamanio, cmock_arg1) i2cWrite_CMockExpect(__LINE__, i2c, address, dato, tamanio, cmock_arg1)
void i2cWrite_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t i2c, uint8_t address, uint8_t* dato, uint16_t tamanio, int cmock_arg1);
typedef void (* CMOCK_i2cWrite_CALLBACK)(uint8_t i2c, uint8_t address, uint8_t* dato, uint16_t tamanio, int cmock_arg1, int cmock_num_calls);
void i2cWrite_AddCallback(CMOCK_i2cWrite_CALLBACK Callback);
void i2cWrite_Stub(CMOCK_i2cWrite_CALLBACK Callback);
#define i2cWrite_StubWithCallback i2cWrite_Stub
#define i2cWrite_ReturnThruPtr_dato(dato) i2cWrite_CMockReturnMemThruPtr_dato(__LINE__, dato, sizeof(uint8_t))
#define i2cWrite_ReturnArrayThruPtr_dato(dato, cmock_len) i2cWrite_CMockReturnMemThruPtr_dato(__LINE__, dato, (int)(cmock_len * (int)sizeof(*dato)))
#define i2cWrite_ReturnMemThruPtr_dato(dato, cmock_size) i2cWrite_CMockReturnMemThruPtr_dato(__LINE__, dato, cmock_size)
void i2cWrite_CMockReturnMemThruPtr_dato(UNITY_LINE_TYPE cmock_line, uint8_t* dato, int cmock_size);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
