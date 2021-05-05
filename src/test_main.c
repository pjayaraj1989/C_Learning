#include "include.h"
#include "str_functions.h"
#include "ll_functions.h"
#include "floating_point_functions.h"

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

    //create_linked_list(5);
    struct packet* head_node = NULL;
    head_node=add_node(head_node,1, "Pranoy");
    head_node=add_node(head_node,2,"Jayaraj");
    head_node=add_node(head_node,4,"Leena");
    print_list(head_node);

    float f  = -3.14;
    print_hex_flt(f);

    double d = 0x6.25p+23;
    print_hex_dbl(d);

    return 0;
}
