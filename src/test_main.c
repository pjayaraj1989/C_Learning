#include "functions.h"

int main() {
    char *name = "Pranoy Jayaraj";
    int len = my_strlen(name);
    printf("Str length: %d\n", len);
    my_puts(name);
    
    char* name2 = "Jayaraj";
    if (my_substring(name, name2) == 0) {
        my_puts("Substring found");
    }

    char* rev_name = NULL;
    rev_name = my_strrev(name);
    my_puts("Reversed string");
    my_puts(rev_name);

    if (my_strcmp("Jayaraj", "Jayaraj") == 0) {
        my_puts("Str cmp passed");
    }

    return 0;
}
