#pragma once

#include <stm32f7xx.h>

#include "../ll/i2c.h"

typedef enum{ II_CROW  = 0x01
            , II_CROW2 = 0x02
            , II_CROW3 = 0x03
            , II_CROW4 = 0x04
} ii_ADDR_t;


/////////////////////
// setup
uint8_t ii_init( uint8_t address );
void ii_deinit( void );

void ii_set_pullups( uint8_t state );

uint8_t ii_get_address( void );
void ii_set_address( uint8_t address );


//////////////////////////
// help (autogenerated)
const char* ii_list_modules( void );
const char* ii_list_cmds( uint8_t address );


/////////////////////////
// leader calls: add to internal queue
uint8_t ii_broadcast( uint8_t address, uint8_t cmd, float* data );
uint8_t ii_query( uint8_t address, uint8_t cmd, float* data );

// call ii_process from main loop to send the next enqueued operation
void ii_process( void );


///////////////////////////
// reception dequeue
uint8_t* ii_processFollowRx( void );
uint8_t* ii_processLeadRx( void );


////////////////////////////////////////////
// callbacks from i2c LL library
void I2C_Lead_RxCallback( uint8_t address, uint8_t cmd, uint8_t* data );
void I2C_Follow_RxCallback( uint8_t* data );
void I2C_Follow_TxCallback( uint8_t* data );
