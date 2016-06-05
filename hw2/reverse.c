/*
 * Read each line.
 * Call Reverse(), which iterates through each line starting from the end.
 * Iteration begins at length-2, to skip '\0' and '\n' characters.
*/


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int getLine(char line[], int maxline);
void reverse(char line[]);

char line[MAXLINE];

int main()
{

	while(getLine(line,MAXLINE)>0){
		reverse(line);
	}	
	return 0;
}



int getLine(char line[], int lim){

	int i,c;
	for(i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n' ; i++)
		line[i] = c;

	if(c == '\n'){
		line[i] = '\n';
		++i;
	}
	
	line[i] = '\0';	

	return i;
}


void reverse(char line[]){
	
	int i;
	for(i=strlen(line)-2;i>=0; i--) //skip '\0' and newline as first character
		printf("%c",line[i]);
	printf("\n");
}
