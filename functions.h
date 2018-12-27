#include<stdio.h>
#include<stdlib.h>

//struct
struct packet 
{
	int id;
	char* name;
	struct packet* next;
};


//ll functions
void print_list(struct packet*);
struct packet* add_node(int, char*);
int my_strcmp(char*, char*);
void my_pal_check(char*);
char* my_strrev(char*);
int my_substring(const char*, const char*);
void my_puts(char*);
int my_strlen(const char*);

void print_list(struct packet* head_node)
{
		struct packet* temp_node = head_node;
		if(temp_node == NULL)
		{
			printf("List is empty\n");
			return;
		}
		while(temp_node->next != NULL)
		{
			printf("%d\t",temp_node->id);
			printf("%s\n",temp_node->name);			
			temp_node=temp_node->next;
		}
}

struct packet* add_node(int id, char* name)
{
	struct packet* head_node=NULL;
	struct packet* temp_node=head_node;
	
	//if first node
	if(temp_node == NULL)
	{
		head_node = (struct packet*)malloc(sizeof(struct packet));
		head_node->id = id;
		head_node->name = name;
		head_node->next = NULL;
		return head_node;
	}
	
	//go to last node
	while(temp_node->next != NULL)
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
