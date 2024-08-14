#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t; 

typedef float float32_t; // float/double can only be signed
typedef double float64_t; // float/double can only be signed

typedef enum 
{
	true = 1,
	false = 0
} bool;

#endif