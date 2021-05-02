
#include "functions.h"

void my_puts(char *s) {
    while(*s != '\0') {
         printf("%c", *s);
	 s++;
    }
    printf("\n");
    return;
}

int my_strlen(const char *s) {
    int len = 0;
    while(*s != '\0') {
        len++;
	s++;
    }

    return len;
}

char* my_strrev(char* s) {
    char* output = NULL;
    int len = 0, i;
    len = my_strlen(s);
    output = (char*)malloc(len*(sizeof(char)));
    for (i = len - 1; i >= 0; i--) {
        *(output + len - i) = *(s + i);
    }

    return output;
}

int my_strcmp(char* s1, char* s2) {
    int ret_val = 1, i = 0, l1 = 0, l2 = 0;
    l1 = my_strlen(s1);
    l2 = my_strlen(s2);
    if (l1 == l2) {
        while (i<l1) {
            if (*(s1 + i) == *(s2 + i)) {
                ret_val = 0;
	    }
	    i++;
	}
    }

    return ret_val;
}
