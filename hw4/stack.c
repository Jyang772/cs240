//Justin Yang
//03-17-2016
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
int val[MAXVAL];

/*void viewstack(void)
{
	int i;
	printf("\nstack:\n");
	for(i = sp - 1; i >= 0; i--)
		printf("%lf\n", val[i]);
}
*/
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
int pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
