#include "data_types.h"

int get_node_by_id(struct packet*, int);
int count_list(struct packet*);
void print_list(struct packet*);
struct packet* add_node(struct packet*, int, char*);
struct packet* delete_node_by_id(struct packet*, int);
