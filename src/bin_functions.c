#include "include.h"
#include "bin_functions.h"

void print_binary(int a) {
    int i=sizeof(int)-1;
    printf("Bin rep for decimal %d\n", a);
    while(i>=0) {
        if(a & (1<<i)) {
	    printf("1");
	}
	else {
	    printf("0");
	}
	i--;
    }
    printf("\n");

    return;
}


char* dec_to_bin_string(int a) {
    int i=sizeof(int)-1;
    char* bin_string;
    bin_string = (char*)malloc(i+1);
    while(i>=0) {
        if(a & (1<<i)) {
	    *(bin_string + (sizeof(int)-1)-i) = '1';
	}
	else {
	    *(bin_string + (sizeof(int)-1)-i) = '0';
	}
    }
    i--;

    return bin_string;
}
