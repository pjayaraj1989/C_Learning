#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma pack (1)

//struct
struct packet
{
	int id;
	char* name;
	struct packet* next;
};

//LL functions
int get_node_by_id(struct packet*, int);
int count_list(struct packet*);
void print_list(struct packet*);
struct packet* add_node(struct packet*, int, char*);
struct packet* delete_node_by_id(struct packet*, int)
	
//string functions
int my_strcmp(char*, char*);
void my_pal_check(char*);
char* my_strrev(char*);
int my_substring(const char*, const char*);
void my_puts(char*);
int my_strlen(const char*);

//file handling
int get_file_count(char*);
char* read_file_contents(char*);

//bin <--> dec
char* dec_to_bin_string(int);

char* dec_to_bin_string(int a)
{
        int i=sizeof(int)-1;
        char* bin_string;
        bin_string = (char*)malloc(i+1);
        while(i>=0)
        {
                if(a & (1<<i))
                        *(bin_string + (sizeof(int)-1)-i) = '1';
                else
                         *(bin_string + (sizeof(int)-1)-i) = '0';
                i--;
        }
        return bin_string;
}



char* read_file_contents(char* filename)
{
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	int count = 0; int i = 0; char ch; char* output;

	count = get_file_count(filename);
	output = (char*)malloc(count*(sizeof(char)));
	while(i<count)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			my_puts("EOF reached!");
			break;
		}
		*(output+i) = ch;
		i++;
	}
	fclose(fp);
	return output;
}

int get_file_count(char* filename)
{
	FILE* fp=NULL;
	fp=fopen(filename,"r");
	int count=0;
	char c;
	if(fp==NULL)
	{
		printf("File pointer is empty!");
		fclose(fp);
		return count;
	}
	else
	{
		while((c=fgetc(fp))) 
		{
			if (c==EOF) 
			{	
				break;
			}
			count+=1;
		}
		fclose(fp);
		return count;
	}	
}

//array functions
int* create_int_array(int, char);

//IMPLEMENTATIONS
int* create_int_array(int count, char option)	//create an integer array with desired values
{
	int* output=NULL;
	int i=0;
	output=(int*)malloc(count*sizeof(int));
	srand(time(0));

	while(i<count)
	{
		switch (option)
		{
			case '1' : *(output+i)=1;
						break;
			case '0' : *(output+i)=0;
						break;
			case 'r'	: *(output+i)=(rand())%100;
						break;
			default	:	break;
		}
		i++;
	}
	//now print it
	while(i<count)
	{
		printf("%d ", output[i]);
		i++;
	}
	return output;
}

int get_node_by_name(struct packet* head_node, char* name)
{
	struct packet* temp_node = head_node;
	int node_id = 0;
	if(temp_node == NULL)
	{
		printf("List is empty\n");
		return node_id;
	}
	while(temp_node!=NULL)
	{
		node_id++;
		if(temp_node->name == name)
		{
			break;
		}
		temp_node = temp_node->next;
	}
	
	return node_id;
}

int get_node_by_id(struct packet* head_node, int id)
{
	struct packet* temp_node = head_node;
	int node_id = 0;
	if(temp_node == NULL)
	{
		printf("List is empty\n");
		return node_id;
	}
	while(temp_node!=NULL)
	{
		node_id++;
		if(temp_node->id == id)
		{
			break;
		}
		temp_node = temp_node->next;
	}
	
	return node_id;
}

int count_list(struct packet* head_node)
{
	int count=0;
	struct packet* temp_node = head_node;
	if(temp_node == NULL)
	{
		printf("List is empty\n");
		return count;
	}
	while(temp_node != NULL)
	{
		count++;
		temp_node = temp_node->next;
	}
	
	return count;
}

void print_list(struct packet* head_node)
{
	struct packet* temp_node = head_node;
	if (temp_node == NULL)
	{
		printf("List is empty\n");
		return;
	}
	while (temp_node != NULL)
	{
		printf("%d\t", temp_node->id);
		printf("%s\n", temp_node->name);
		temp_node = temp_node->next;
	}
}

struct packet* add_node(struct packet* head_node, int id, char* name)
{
	struct packet* temp_node = head_node;

	//if first node
	if (temp_node == NULL)
	{
		head_node = (struct packet*)malloc(sizeof(struct packet));
		head_node->id = id;
		head_node->name = name;
		head_node->next = NULL;
		return head_node;
	}

	//go to last node
	while (temp_node->next != NULL)
	{
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
struct packet* delete_node_by_id(struct packet* head_node, int id)
{
	struct packet* temp_node = head_node;
	struct packet* prev_node;

	//if first node to be deleted
	if (temp_node->id == id)
	{
		head_node = temp_node->next;
		free(temp_node);
		return head_node;
	}

	//not first node
	while (temp_node->next != NULL)
	{
		if (temp_node->next->id == id)
		{
			//if last node
			if (temp_node->next->next == NULL)
			{
				temp_node->next = NULL;
				prev_node = temp_node->next;
				free(prev_node);
				break;
			}
			else
			{
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

int my_strcmp(char* s1, char* s2)
{
	int ret_val = 1, i = 0, l1 = 0, l2 = 0;
	l1 = my_strlen(s1);
	l2 = my_strlen(s2);
	if (l1 == l2)
	{
		while (i<l1)
		{
			if (*(s1 + i) == *(s2 + i))
			{
				ret_val = 0;
			}
			i++;
		}
	}
	return ret_val;
}

void my_pal_check(char* s)
{
	char* rev_str = NULL;
	if (s != NULL)
	{
		if (my_strcmp(my_strrev(s), s) == 0)
			my_puts("Palindrome\n");
		else
			my_puts("NOT palindrome\n");
	}
}

char* my_strrev(char* s)
{
	char* output = NULL;
	int len = 0, i;
	len = my_strlen(s);

	output = (char*)malloc(len*(sizeof(char)));
	for (i = len - 1; i >= 0; i--)
	{
		*(output + len - i) = *(s + i);
	}
	return output;
}

int my_substring(const char* main_string, const char* substring)
{
	int l1 = 0, l2 = 0, i = 0;
	int count = 0, ret_val = 1;
	l1 = my_strlen(main_string);
	l2 = my_strlen(substring);
	if (l1 >= l2)
	{
		while (*main_string)
		{
			if (*(main_string) == *substring)//first char found?
			{
				while (i<l2)
				{
					if (*(main_string + i) == *(substring + i))
					{
						count++;
					}
					i++;
				}
			}
			main_string++;
		}
	}
	if (count == l2)
	{
		ret_val = 0;
	}
	return ret_val;
}

char* my_strcat(const char* s1, const char* s2)
{
	char* s = NULL;
	int l1 = 0, l2 = 0, l = 0, i = 0;
	l1 = my_strlen(s1);
	l2 = my_strlen(s2);
	s = (char*)malloc((l1 + l2) * sizeof(char));
	while (i < l1)
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (i<l2)
	{
		*(s + l1 + i) = *(s2 + i);
		i++;
	}
	return s;
}

void my_puts(char* s)
{
	while (*s != '\0')
	{
		printf("%c", *s);
		s++;
	}
	printf("\n");
}

int my_strlen(const char* s)
{
	int len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return len;
}
