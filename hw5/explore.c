//Justin Yang
//Modified for hw5

/* explore.c: program to explore memory locations via pointers
   bob wilson 03/13/2003
   modified by Ron Cheung 7/8/2003   */

#include <stdio.h>

/* external variable */
int a = 0x13579753;

/* external static variable */
static int b = 0x24680864;

/* function declarations */
void foobar(int, int, int *, int *);

int main(void) {
  static int c = 0xaaaa5555;   /* local static variable */
  int d = 0x5555aaaa;          /* local automatic variable */
  int *ap = &a;                /* pointer to external variable a */
  int *bp = &b;                /* pointer to external static variable b */
  int *cp = &c;                /* pointer to local static variable c */
  int *dp = &d;                /* pointer to local automatic variable d */
  int array[1] = {0x01010101}; /* array of one integer */
  
  /* Add code here to print the address of array[0].  */
	printf("address of array[0]: %p\n",array);  
  
  
  /* Add code here to print the values of variables a, b, c, d. */
	printf("value of variable a: %x\n"
		"value of variable b: %x\n"
		"value of variable c: %x\n"
		"value of variable d: %x\n",a,b,c,d);  
  
  
  /* Add code here to print the values of pointers ap, bp, cp, dp. */
 	printf("\nvalue of ap: %p\n"
		"value of bp: %p\n"
		"value of cp: %p\n"
		"value of dp: %p\n",ap,bp,cp,dp); 
  

  /* Add code here to print array[i] for i = 0 to high enough value.
     (What we want to see here is the values of all the pointer variables
     by incrementing out of the array and into the surrounding memory.) */
	for(int i=0; i<10; i++) 
		printf("value of array[%d]: %x\n",i,*(array+i)); 

 
  /* Call subroutine foobar and pass arguments.  */
  foobar(a, d, &a, &d);
  
  return 0;
}

/* foobar function definition */
void foobar(int x, int y, int *xp, int *yp) {
  int array[1] = {0x10101010};
  
  printf("Entering foobar\n");
  
  /* add code here to print address of array[0]  */
	printf("address of array[0]: %p\n",array);
  
  
  /* add code here to print array[i] for i = 0 to high enough value */
	for(int i=0; i<24; i++) 
		printf("value of array[%d]: %x\n",i,*(array+i));  
  
  return;
}

