#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <fenv.h>

typedef union {
    double x;
    uint64_t hex;
}doubleword;


typedef union {
    float x;
    uint32_t hex;
}floatword;

int print_hex_flt(float f);
int print_hex_dbl(double d);
