#include "include.h"
#include "ll_functions.h"

int get_node_by_name(struct packet* head_node, char* name) {
    struct packet* temp_node = head_node;
    int node_id = 0;
    if(temp_node == NULL) {
        printf("List is empty\n");
        return node_id;
    }
    while(temp_node!=NULL) {
        node_id++;
	if(temp_node->name == name) {
	    break;
        }
        temp_node = temp_node->next;
    }

    return node_id;
}


int get_node_by_id(struct packet* head_node, int id) {
    struct packet* temp_node = head_node;
    int node_id = 0;
    if(temp_node == NULL) {
        printf("List is empty\n");
        return node_id;
    }
    while(temp_node!=NULL) {
        node_id++;
        if(temp_node->id == id) {
            break;
        }
	temp_node = temp_node->next;
    }
						
    return node_id;
}


int count_list(struct packet* head_node) {
    int count=0;
    struct packet* temp_node = head_node;
    if(temp_node == NULL) {
        printf("List is empty\n");
        return count;
    }
    while(temp_node != NULL) {
        count++;
        temp_node = temp_node->next;
    }

    return count;
}


void print_list(struct packet* head_node) {
    struct packet* temp_node = head_node;
    if (temp_node == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp_node != NULL) {
        printf("%d\t", temp_node->id);
        printf("%s\n", temp_node->name);
        temp_node = temp_node->next;
    }

    return;
}


struct packet* add_node(struct packet* head_node, int id, char* name) {
    struct packet* temp_node = head_node;
    //if first node
    if (temp_node == NULL) {
        head_node = (struct packet*)malloc(sizeof(struct packet));
        head_node->id = id;
        head_node->name = name;
        head_node->next = NULL;
        return head_node;
    }
    //go to last node
    while (temp_node->next != NULL) {
        temp_node = temp_node->next;
    }
    //now we're at the end of the list, now add next node
    temp_node->next = (struct packet*)malloc(sizeof(struct packet));
    temp_node = temp_node->next;
    temp_node->id = id;
    temp_node->name = name;
    temp_node->next = NULL;

    return head_node;
}


//delete a node by ID
struct packet* delete_node_by_id(struct packet* head_node, int id) {
    struct packet* temp_node = head_node;
    struct packet* prev_node;

    //if first node to be deleted
    if (temp_node->id == id) {
        head_node = temp_node->next;
        free(temp_node);
        return head_node;
    }
    //if not first node
    while (temp_node->next != NULL) {
        if (temp_node->next->id == id) {
        //if last node
            if (temp_node->next->next == NULL) {
                temp_node->next = NULL;
                prev_node = temp_node->next;
                free(prev_node);
                break;
            }
            else {
                prev_node = temp_node->next;
                temp_node->next = temp_node->next->next;
                free(prev_node);
                break;				
            }
	}
        temp_node = temp_node->next;
    }

    return head_node;
}


