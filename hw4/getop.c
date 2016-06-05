//Justin Yang!!
//03-17-2016
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c, t; 
    while ((s[0] = c = t = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (!isdigit(c) && c != '.') {         /* collect integer part */
	if(c == '-' && (isdigit(s[++i] = c = getch())))
		;
	else if(c == '\n' && s[i-1] == '-') {
		ungetch(c);
		return '-';
		}
	else  
		return t; //t since c would have the value of getch() ; ex. ' '
	}
	
    if(isdigit(c))
		while(isdigit(s[++i] = c = getch()));
    if (c == '.')                       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';                        /* terminate string */
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

