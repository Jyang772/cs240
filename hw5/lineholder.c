//Justin Yang
//Lineholder

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000	//For lineholder
#define MAXLINES 2000	//Maximum 2000 lines the user can specify to get

char *lineptr[MAXLINES]; 
char **lptr;
int nlines=0, lines_read=0;

char *init_lineholder(int n) {
	
	lptr = lineptr;	
	nlines = n;		
	char *line = (char*)malloc(sizeof(char)*MAXLEN);	//Each line can be >= 1000 chars
	return line;
}

void insert_line(char *line) {
	
	++lines_read;

	if(lines_read > nlines) {
		free(lineptr[0]);						//Free first slot of lineptr
		for(int i=0; i<nlines-1; i++) 
			*(lineptr+i) = *(lineptr+i+1);				//Ripple pointers to the left by one.
		lineptr[nlines-1] = (char*)malloc(sizeof(char)*strlen(line)+1);	//strlen doesn't count NULL | allocate space for line at last slot
		strcpy(lineptr[nlines-1],line);
	}
	else {	//First fill up array to first n lines using ptr to beginning of **lineptr
		*(lptr) = (char*)malloc(sizeof(char)*strlen(line)+1);
		strcpy(*lptr,line);	
		lptr++;
	}

}	

void print_lines() {
	
	int i = 0;	
	lptr = lineptr;					//User might request more lines than actually read.
	while((i < lines_read) && (i++ < nlines)) {
		printf("%s",*lptr);
		free(*lptr++);
	}
}
