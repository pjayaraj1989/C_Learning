#include "include.h"
#include "str_functions.h"
#include "file_functions.h"

char* read_file_contents(char* filename) {
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    int count = 0; int i = 0; char ch; char* output;
    count = get_file_count(filename);
    output = (char*)malloc(count*(sizeof(char)));
    while(i<count) {
        ch = fgetc(fp);
	if (ch == EOF) {
            my_puts("EOF reached!");
	    break;
	}
	*(output+i) = ch;
	i++;
    }
    fclose(fp);

    return output;
}


int get_file_count(char* filename) {
    FILE* fp=NULL;
    fp=fopen(filename,"r");
    int count=0;
    char c;
    if(fp==NULL) {
        printf("File pointer is empty!");
	fclose(fp);
	return count;
    }
    else {
        while((c=fgetc(fp))) {
	    if (c==EOF) {	
	        break;
	    }
	    count+=1;
        }
    fclose(fp);
    return count;																	}	
}
