#ifndef BIT_OPERATION_H
#define BIT_OPERATION_H

#include "std_types.h"
#define SET_BIT(X, POS) ((X) |= (0x01 << ((uint32_t)POS)))
#define CLR_BIT(X, POS) ( (X) &= ~(0x01 << ((uint32_t)POS)) )
#define TOG_BIT(X, POS) ( (X) ^= (0x01 << ((uint32_t)POS)) )
#define GET_BIT(X, POS) ( ((X) >> ((uint32_t)POS)) & 0x01 )

#define SET_NIB_TO_VAL(X, POS, VAL)	((X) = (X) & ~(0xF << (POS * 4)) | (VAL << (POS * 4)))

#define SET_PORT(Y) ( (Y) = 0xFF )
#define CLR_PORT(Y) ( (Y) = 0x00 )
#define TOG_PORT(Y) ( (Y) ^= 0xFF )

#define SET_PORT_TO_VAL(Y, VAL) ( (Y) = (VAL) )

/*
static inline void SET_BIT(uint32_t _reg, uint8_t _pos)
{
	_reg |= (0x01 << _pos);
}

static inline void CLR_BIT(uint32_t _reg, uint8_t _pos)
{
	_reg &= ~(0x01 << _pos);
}

static inline void TOG_BIT(uint32_t _reg, uint8_t _pos)
{
	_reg ^= (0x01 << _pos);
}

static inline uint8_t GET_BIT(uint32_t _reg, uint8_t _pos)
{
	return ((_reg >> _pos) & 0x01);
}
*/

#endif
