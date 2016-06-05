/*
	Get line from user input. 
	Parse line character by character starting from the end. 
	If character is '\t' or ' ', continue iterating.
	Place '\0' at the beginning of trailing tabs and blank spaces
*/

#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[],int lim);
void trim(char s[],int length);

int main(void)
{
	int c, length;
	char line[MAXLINE];

	

	
	while((length = getLine(line,MAXLINE)) > 0)
	//length = getLine(line,MAXLINE);
	{
		trim(line,length);
		printf("%s",line);
	}

}


int getLine(char s[], int lim)
{
	int c, i;
	for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	
	//printf("%d\n",i);
	if(c == '\n'){	
		s[i] = '\n';
		i++;
		s[i] = '\0';
	}
	//printf("%d\n",i);
	
	//s[i] = '\0';


	

	return i;
}


void trim(char s[], int length)
{
	int i;
	int newline = 0;
	//printf("%d\n",length);
	for(i=length-1; i>=0 && (s[i] == '\t' || s[i] == ' ' || s[i] == '\n'); i--)
	{
		if(s[i] == '\n' && i != 0)
			newline = 1;
		s[i] = '\0';
	}
	if(newline){
		s[i+1] = '\n';
		s[i+2] = '\0';
	}
	//printf("%d\n",i);
}	

