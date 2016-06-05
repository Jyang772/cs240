#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5


char *lines[5];
char s[20];

int getLine(char[],int length);

int main() {
	
	int i = 0, len = 0;
	int first;
	int maxed = 0;
	
	while((len = getLine(s,1000)) > 0) {
		/*if(i >= MAXLINES) {
			i = (i % MAXLINES);
			first = (i+1) % MAXLINES;		
		}*/	
		if(i >= MAXLINES || maxed) {
			maxed = 1;
			free(lines[0]);
			for(int j=0; j<MAXLINES-1;j++)
				*(lines+j) = *(lines+j+1);
			lines[MAXLINES-1] = (char*)malloc(sizeof(char)*len);
			strcpy(lines[MAXLINES-1],s);
			continue;
		}
		lines[i] = (char*)malloc(sizeof(char)*len);
		strcpy(lines[i++],s);
	}	
	
	printf("-----\n");
	int k;
	for(k=0; k<MAXLINES;k++)
		printf("%s\n",lines[k]);
//		for(k=0; k<MAXLINES; k++)
//			printf("%s\n",lines[(i++)%MAXLINES]);			
			
	return 0;
}	

int getLine(char s[], int length) {

	int c, i=0;	
	while((c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i] = '\0';

	return i;
}
