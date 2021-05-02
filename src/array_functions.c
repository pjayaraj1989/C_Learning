#include "array_functions.h"

int* create_int_array(int count, char option) {
    int* output=NULL;
    int i=0;
    output=(int*)malloc(count*sizeof(int));
    srand(time(0));

    while(i<count) {
        switch (option) {
            case '1' : *(output+i)=1;
	        break;
	    case '0' : *(output+i)=0;
                break;
            case 'r'	: *(output+i)=(rand())%100;
	        break;
            default	:
	        break;
	}
	i++;
    }
    //now print it
    while(i<count) {
        printf("%d ", output[i]);
        i++;
    }
    
    return output;
}
