#include "floating_point_functions.h"

int print_hex_flt(float f) {
    floatword fw;
    fw.x = f;
    printf("In Hex format: %x\n", fw.hex);
    return 0;
}

int print_hex_dbl(double d) {
    doubleword dw;
    dw.x = d;
    printf("In hex format: %lx\n", dw.hex);

    return 0;
}
