/*
 *  stub driver for functions to study integer-hex conversions
 *
 */

#include <stdio.h>
#include <string.h>
#include "xbits.h"

#define ENOUGH_SPACE 1 /* not really enough space */

int main() {
  char hexstring[ENOUGH_SPACE];
  int m=0, n = 0x79FEB220;
  
  itox( hexstring, n);

  /* for stub testing: create a fake input string */
  strcpy( hexstring, "6BCD7890"); 
  m = xtoi(hexstring);

  /* print input int, hex string representation, int converted back */
  m= xtoi(hexstring);
  printf("\ninput decimal int   : %d\n", n);
  printf("hex representation  : %s\n", hexstring);
  printf("reconverted decimal : %d\n\n", m);

  return 0;  /* everything is just fine */
}


