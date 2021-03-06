/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_TERMINAL_H
#define _MOCK_TERMINAL_H

#include "unity.h"
#include "terminal.h"

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

void mock_terminal_Init(void);
void mock_terminal_Destroy(void);
void mock_terminal_Verify(void);




#define leeri2c_Ignore() leeri2c_CMockIgnore()
void leeri2c_CMockIgnore(void);
#define leeri2c_Expect(i2c, address, buffer, bufferSize, writeStop, lectura, tamanio, readStop) leeri2c_CMockExpect(__LINE__, i2c, address, buffer, bufferSize, writeStop, lectura, tamanio, readStop)
void leeri2c_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t i2c, uint8_t address, uint8_t* buffer, uint16_t bufferSize, int writeStop, uint8_t* lectura, uint16_t tamanio, int readStop);
typedef void (* CMOCK_leeri2c_CALLBACK)(uint8_t i2c, uint8_t address, uint8_t* buffer, uint16_t bufferSize, int writeStop, uint8_t* lectura, uint16_t tamanio, int readStop, int cmock_num_calls);
void leeri2c_AddCallback(CMOCK_leeri2c_CALLBACK Callback);
void leeri2c_Stub(CMOCK_leeri2c_CALLBACK Callback);
#define leeri2c_StubWithCallback leeri2c_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
