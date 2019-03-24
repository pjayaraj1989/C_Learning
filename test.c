#include "functions.h"

int main()
{
	int len = 0;
	char* Name = NULL;
	//printf("%d\n", my_strlen("Pranoy"));
	//my_puts("Pranoy");
	//my_puts(my_strcat("Pranoy", "Jayaraj"));
	//len = my_substring(Name1, Name2);
	//my_puts("Pranoy");
	//my_puts(my_strrev("Pranoy"));

	
	//create_linked_list(5);
	struct packet* head_node = NULL;
	head_node=add_node(head_node,1, "Pranoy");
	head_node=add_node(head_node,2,"Jayaraj");
	head_node=add_node(head_node,4,"Leena");
	
	print_list(head_node);
	
	return 0;
}
