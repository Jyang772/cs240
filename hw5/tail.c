//Justin Yang
//Tail


#include "lineholder.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 10
#define MAXLEN 1000

int getLine(char[], int length);

int main(int argc, char **argv) {

		
	int len = 0;
	int n = 0;
	char *ptr = NULL;
	if(argc > 1 && **(argv+1) == '-') {		//Implement some getopt functionality
		ptr = argv[1];				//Point to the next argument 
		n = atoi((*(argv+1)+1));			//pre-increment ptr to get next char
	}
	else						//If user hasn't specified n
		n = DEFAULT;	
	
	char *test = init_lineholder(n);
	while((getLine(test,MAXLEN)) > 0) {
		insert_line(test);
	}
	print_lines();
	return 0;
}


int getLine(char s[], int length) {
	int c,i = 0;
		
	while((c=getchar()) != EOF && (c != '\n'))
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	
	return i;
}

