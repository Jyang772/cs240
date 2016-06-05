/*
 *  stub driver for functions to study integer-hex conversions
 *
 */

#include <stdio.h>
#include <string.h>
#include "xbits.h"

#define ENOUGH_SPACE 2*sizeof(int)+1/* not really enough space */

int main() {
  	char hexstring[ENOUGH_SPACE];
	int decimal, recovered;

	while((scanf("%d",&decimal) != EOF)) {	
		itox(hexstring, decimal);
		recovered = xtoi(hexstring);
		printf("\ninput decimal int: %d\n"
			"hex representation: %s\n"
			"reconverted decimal: %d\n\n",decimal,hexstring,recovered);
	}

  return 0;  
}


